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

preOccupy()
{
	echo ""
	echo "    preoccupy the device"
	WRITTEN=`echo $TotalSize*85/100 | bc`
	mobibench -p ${MNT}/preWrtn -f $WRITTEN -r 512 -a 0 -y 0 # prewritten

	toWrite=`echo 10485760 | bc`
	mobibench -p ${MNT}/gc_test -f $toWrite -r 512 -a 0 -y 0 

	sync

	case ${FileSystem} in 
	f2fs)
		cat /sys/kernel/debug/f2fs/status > $STATNAME ;
		cat /proc/fs/f2fs/${DEVP}/segment_info > $SEGNAME ;;
	ext4)
		cat /proc/fs/ext4/${DEVP}/mb_groups  > $STATNAME ;;
	esac

	sleep 10

}


gc()
{
	echo "     run test"
	case $util in
		90) NRUNS=30 ;;
		70) NRUNS=1000 ;;
		50) NRUNS=1000 ;;
		*)  NRUNS=2000 ;;
	esac
	NRUNS=5 ;

	echo "#>mobibench -p ${MNT}/gc_test -f $toWrite -r 4 -a 0 -y 0" > $RESULT
	echo "#itrtn  Bandwidth in MB" > $BWONLY
	

#	blktrace -a complete -d $DEV -o ./result/${FileSystem}/blk/${util}/blk_util_${util}_gc &
#	killpid=$!
	#echo "     blktrace running on process id of ${killpid}"

	STARTIME=$(date  +%s)
	echo "#GCitr TIME $STARTTIME in secodns" > RUNTIME_${FileSystem}_${util}
	
	echo "Start Iteration..."
#	read -n 1 $input1

	for i in `seq 1 $NRUNS` 
	do
		mobibench -p ${MNT}/gc_test -f $toWrite -r 4 -a 0 -y 0 >> $RESULT

		ENDTIME=$(date +%s)	
		echo ${i} $(( $ENDTIME - $STARTIME )) >> RUNTIME_${FileSystem}_${util}

		echo `tail -n 18 $RESULT | awk -F" " -v ITR="$i" '/TIME/{print "       successful iteration " ITR ":", $12,$13}' `

		case ${FileSystem} in 
		f2fs)
			cat /sys/kernel/debug/f2fs/status > ${STATNAME%.txt}_${i}.txt ;
			cat /proc/fs/f2fs/${DEVP}/segment_info > ${SEGNAME%.txt}_${i}.txt ;;
		ext4)
			cat /proc/fs/ext4/${DEVP}/mb_groups  > ${STATNAME%.txt}_${i}.txt ;;
		esac

#		read -n 1 $input2

	done

		kill -2 $killpid

	cat $RESULT | awk -F" "  'BEGIN{i=1};/TIME/{print i, $12,$13; i++}' >> $BWONLY
#	blkparse -i ./result/${FileSystem}/blk/${util}/blk_util_${util}_gc_${i}.blktrace.0 -o ./result/${FileSystem}/blk/${util}/blk_util_${util}_gc &
	#rm ./result/${FileSystem}/blk/${util}/blk_util_${util}_gc.blktrace.* 

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
#		f2fs) mount -t $FileSystem -o background_gc=off -o active_logs=2 $DEV $MNT 
			echo "  mount f2fs successful" ;;
		ext4) mount -t $FileSystem -o nodiscard $DEV $MNT
			echo "  mount ext4 successful" ;;
		*) echo "available file system: f2fs" ;;
	esac
	
	echo 20 > /sys/fs/f2fs/sdb/reclaim_segments
}


runTest()
{
	for FileSystem in f2fs 
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
			TotalSize=`df | grep $DEV | awk '{print $4}' | awk '{print int($1*1)}'`
				
			STATNAME=./result/${FileSystem}/${util}/02_stat_${util}_precond.txt
			SEGNAME=./result/${FileSystem}/${util}/02a_seg_${util}_precond.txt
#			precondition
			STATNAME=./result/${FileSystem}/${util}/03_stat_${util}_preWritten.txt
			SEGNAME=./result/${FileSystem}/${util}/03a_seg_${util}_preWritten.txt
			preOccupy
			STATNAME=./result/${FileSystem}/${util}/04_stat_${util}_gc.txt
			SEGNAME=./result/${FileSystem}/${util}/04a_seg_${util}_gc.txt
			gc
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


