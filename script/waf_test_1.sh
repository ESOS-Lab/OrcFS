#!/bin/bash

#FileSystem="f2fs"
#FileSystem="ext4"
#DEV="/dev/sdc1"
DEV="/dev/sda5"
DEVP="sda5"
MNT="/mnt/f2fs_mnt"

initialize()
{
	echo ""
	echo " initialize process"
	echo " run util: $util"
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

preOccupy()
{
	echo ""
	echo "    preoccupy the device"
#	WRITTEN=`echo $TotalSize*75/100 | bc`
#	mobibench -p ${MNT}/preWrtn -f $WRITTEN -r 512 -a 0 -y 0 # prewritten

#	toWrite=`echo 10485760 | bc`
	toWrite=`echo $TotalSize*90/100 | bc`
	mobibench -p ${MNT}/gc_test -f $toWrite -r 512 -a 0 -y 0 

	sync

	case ${FileSystem} in 
	f2fs)
		cat /sys/kernel/debug/f2fs/status > $STATNAME ;
		cat /proc/fs/f2fs/${DEVP}/segment_info > $SEGNAME ;
		cat /proc/fs/f2fs/${DEVP}/waf_info > $WAFNAME ;;
	ext4)
		cat /proc/fs/ext4/${DEVP}/mb_groups  > $STATNAME ;;
	esac

	sleep 10

}


gc()
{
	echo "     run test"
	NRUNS=5 ;

	STARTIME=$(date  +%s)
	echo "Start Iteration..."
#	read -n 1 $input1

	for i in `seq 1 $NRUNS` 
	do
		mobibench -p ${MNT}/gc_test -f $toWrite -r 4 -a 1 -y 0

#		sync
		ENDTIME=$(date +%s)	
		echo ${i} $(( $ENDTIME - $STARTIME )) >> RUNTIME_${FileSystem}

		case ${FileSystem} in 
		f2fs)
			cat /sys/kernel/debug/f2fs/status > ${STATNAME%.txt}_${i}.txt ;
			cat /proc/fs/f2fs/${DEVP}/waf_info > ${WAFNAME%.txt}_${i}.txt ;
			cat /proc/fs/f2fs/${DEVP}/segment_info > ${SEGNAME%.txt}_${i}.txt ;;
		ext4)
			cat /proc/fs/ext4/${DEVP}/mb_groups  > ${STATNAME%.txt}_${i}.txt ;;
		esac

#		read -n 1 $input2
	done

		kill -2 $killpid
}

_mkfs()
{
	echo " make file system: $FileSystem on $DEV"
	sync
	umount ${MNT} 

	case $FileSystem in 
		f2fs) 
#		      mkfs -t f2fs -l f2fs -t 0 $DEV 
#		      mkfs -t f2fs -l f2fs -t 0 $DEV 4194304	# 2GByte
		      mkfs -t f2fs -l f2fs -t 0 $DEV 41943040	# 20GByte
		      echo " mkfs f2fs successful" ;; 
		ext4)
		      mkfs -t ext4 -L ext4 -E nodiscard -E lazy_itable_init=0 -E lazy_journal_init=0 $DEV
		      echo " mkfs ext4 successful" ;; 
		*) echo "available file system: f2fs | ext4" ;;
	esac
}

_mountFS()

{
	echo 3 > /proc/sys/vm/drop_caches

	case $FileSystem in 
		f2fs) mount -t $FileSystem $DEV $MNT 
			echo "  mount f2fs successful" ;;
		ext4) mount -t $FileSystem -o nodiscard $DEV $MNT
			echo "  mount ext4 successful" ;;
		*) echo "available file system: f2fs" ;;
	esac
	
#	echo 20 > /sys/fs/f2fs/sda5/reclaim_segments
}


runTest()
{
	for FileSystem in f2fs 
	do
		[ -d ./result ] || { mkdir -p result; } 
		[ -d ./result/${FileSystem} ] || { mkdir -p result/${FileSystem}; } 

		STATNAME=./result/${FileSystem}/01_stat_mount.txt
		SEGNAME=./result/${FileSystem}/01a_seg_mount.txt
		initialize
		TotalSize=`df | grep $DEV | awk '{print $4}' | awk '{print int($1*1)}'`
				
		STATNAME=./result/${FileSystem}/02_stat_precond.txt
		SEGNAME=./result/${FileSystem}/02a_seg_precond.txt
#		precondition
		STATNAME=./result/${FileSystem}/03_stat_preWritten.txt
		SEGNAME=./result/${FileSystem}/03a_seg_preWritten.txt
		WAFNAME=./result/${FileSystem}/03a_waf_preWritten.txt
		preOccupy
		STATNAME=./result/${FileSystem}/04_stat_gc.txt
		SEGNAME=./result/${FileSystem}/04a_seg_gc.txt
		WAFNAME=./result/${FileSystem}/04_waf_gc.txt
		gc
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


