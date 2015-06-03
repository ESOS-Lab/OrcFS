#!/bin/bash

DEV="/dev/sdb"
OUTPUTDIR="./fio_result"
MNT="/home/jedisty/f2fs_mnt"
FILESYSTEM="f2fs"
NRUNS=1

_mkfs()
{
	case $FILESYSTEM in
		f2fs)
			mkfs -t f2fs -s 128 $DEV
			echo "mkfs f2fs"
			;;
		ext4)
			mkfs -t ext4 $DEV
			echo "mkfs ext4"
			;;
	esac
}

_mount()
{
	echo 3 > /proc/sys/vm/drop_caches

	case $FILESYSTEM in
		f2fs)
			mount -t $FILESYSTEM $DEV $MNT
			;;
		ext4)
			mount -t $FILESYSTEM $DEV $MNT
			;;
	esac

	echo "mount device $DEV at $MNT as $FILESYSTEM"
}

run_FIO_Test()
{
	echo "Start Test"

	touch ${MNT}/fio_test

	for i in `seq 1 $NRUNS`
	do
		fio --output=./${OUTPUTDIR}/128k_q32_seqwrite_${FILESYSTEM} --name=128k_q32_seqwrite --readwrite=write --bs=128k --ioengine=libaio --iodepth=32 --direct=0 --end_fsync=1 --exitall --norandommap --randrepeat=0 --refill_buffers --filename=${MNT}/fio_test --size="$ToWriteSize_1K"K --write_iops_log=128k_q32_seqwrite --iopsavgtime=1000

	done
}

getTestFileSize()
{
	TotalSize_1K=`df | grep $DEV | awk '{print $4}'`
	PreOccupySize_1K=`echo $TotalSize_1K*70/100 | bc`
	ToWriteSize_1K=`echo $TotalSize_1K*90/100 | bc`
}

main()
{
	umount ${MNT}

# Initialize
	_mkfs
	_mount
	getTestFileSize

# Run Test
	run_FIO_Test
}

case $1 in
        run)
		main
		;;
        clean)
		rm {$OUTPUTDIR}/*.txt
		;;
        *)      echo "usage: $0 {run|clean}" 
                echo "       run: run the test and save the result under $OUTPUTDIR"
                echo "       clean: erases result file before running the test"
		;;
esac
