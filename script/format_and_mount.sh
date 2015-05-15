#!/bin/bash

#FileSystem="f2fs"
#FileSystem="ext4"
#DEV="/dev/sdc1"
DEV="/dev/sdb5"
DEVP="sdb5"
MNT="/mnt/f2fs_mnt"

initialize()
{
	echo ""
	echo " initialize process"
	echo " run util: $util"
	RESULT=result/${FileSystem}/buffered_util_${util}.txt
	BWONLY=result/${FileSystem}/buffered_util_${util}_BW.txt

	echo 3 > /proc/sys/vm/drop_caches	

	_mkfs
	_mountFS

	case ${FileSystem} in 
	f2fs)
		cat /sys/kernel/debug/f2fs/status > $STATNAME ;
		cat /proc/fs/f2fs/${DEVP}/segment_info > $SEGNAME ;;
	ext4)
		cat /proc/fs/ext4/${DEVP}/mb_groups  > $STATNAME ;;
	esac
	sleep 10
}

precondition()
{
	# sequential 512KB buffered write maximum available size
	echo ""
	echo "   precondition phase"
	mobibench -p ${MNT} -f $TotalSize -r 512 -a 0 -y 0
	sync
	sleep 10
	rm ${MNT}/test.dat0
	sync

	case ${FileSystem} in 
	f2fs)
		cat /sys/kernel/debug/f2fs/status > $STATNAME ;
		cat /proc/fs/f2fs/${DEVP}/segment_info > $SEGNAME ;;
	ext4)
		cat /proc/fs/ext4/${DEVP}/mb_groups  > $STATNAME ;;
	esac
}

_mkfs()
{
	echo " make file system: $FileSystem on $DEV"
	sync
	umount ${MNT} 

	case $FileSystem in 
		f2fs) 
		      mkfs -t f2fs -l f2fs -t 0 $DEV 
		      echo " mkfs f2fs successful" ;; 
		ext4)
#		      mkfs -t ext4 -L ext4 -E nodiscard -E lazy_itable_init=0 -E lazy_journal_init=0 $DEV
		      mkfs -t ext4 $DEV
		      echo " mkfs ext4 successful" ;; 
		*) echo "available file system: f2fs | ext4" ;;
	esac
}

_mountFS()

{
	echo 3 > /proc/sys/vm/drop_caches

	case $FileSystem in 
		f2fs) mount -t $FileSystem -o background_gc=off $DEV $MNT 
			echo "  mount f2fs successful" ;;
#		ext4) mount -t $FileSystem -o nodiscard $DEV $MNT
		ext4) mount -t $FileSystem $DEV $MNT
			echo "  mount ext4 successful" ;;
		*) echo "available file system: f2fs" ;;
	esac
	
#	echo 20 > /sys/fs/f2fs/sda5/reclaim_segments
}


runTest()
{
	for FileSystem in ext4
	do

		for util in  90 #70 50 
		do
			[ -d ./result ] || { mkdir -p result; } 
			[ -d ./result/${FileSystem} ] || { mkdir -p result/${FileSystem}; } 
			[ -d ./result/${FileSystem}/${util} ] || { mkdir -p result/${FileSystem}/${util}; } 
			[ -d ./result/${FileSystem}/blk/${util} ] || { mkdir -p result/${FileSystem}/blk/${util}; } 

			STATNAME=./result/${FileSystem}/${util}/01_stat_${util}_mount.txt
			SEGNAME=./result/${FileSystem}/${util}/01a_seg_${util}_mount.txt
			initialize
			echo "$FileSystem Ended"
		done
		echo "$FileSystem Ended"
	done
}

case $1 in
	run)    runTest ;;
	clean)  rm result/*.txt
		runTest;;
	*) 	echo "usage: $0 {run|clean}" 
	        echo "       run: run the test and save the result under result"
		echo "       clean: erases result file before running the test" ;;
esac


