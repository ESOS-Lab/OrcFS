#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define MAX_IO_LENGTH 524288

int n_files;
long long file_size_1k;
long long record_size_1k;
int random_ratio;
int fd;
char* path;
char file_name[10] = "test_file";

void init_test_files(void);
void open_test_files(void);
void create_test_files(void);
double overwrite_test_files(void);

long long get_current_utime(void)
{
        struct timeval current;

        gettimeofday(&current,NULL);

        return (current.tv_sec*1000000 + current.tv_usec);
}

/*
 * ./program  path  file_size_1k  record_size_1k  random_ratio(%)
 *
 */

int main(int argc, char* argv[])
{
	long long total_file_size_1k;
	int test_mode;
	double iops = 0;

	path 			= argv[1];		// file path
	file_size_1k 		= atoi(argv[2]);	// file size in Kbyte
	record_size_1k		= atoi(argv[3]);	// record size in Kbyte
	random_ratio 		= atoi(argv[4]);	// random area ratio in percentage	
	test_mode		= atoi(argv[5]);

	if(test_mode < 0 || test_mode > 2){
		printf("[%s] test mode should be 0 or 1 (current: %d)\n", __FUNCTION__, test_mode);
	}

	if(test_mode == 0){
		create_test_files();
	}
	else if(test_mode == 1){
		open_test_files();
		iops = overwrite_test_files();
	}
	else{
		printf("[%s] Wrong input: %d\n", __FUNCTION__, test_mode);
	}

	printf("%lf\n", iops);

	return 0;
}

void create_test_files(void)
{
	int i;
	long long n_remains;
	long long to_write;
	long long file_size = file_size_1k * 1024;
	char buf[MAX_IO_LENGTH];

	memset(buf, 0xcafe, MAX_IO_LENGTH);
	/* Change directory to path */
	if(chdir(path) == -1){
		printf("[%s] Change directory to %s fail\n", __FUNCTION__, path);
		return;
	}

	/* Open a file */
	fd = open(file_name, O_RDWR | O_CREAT, 0644);
	if(fd == -1){
		printf("[%s] file %s create fail\n", __FUNCTION__, file_name);
		return;
	}

	n_remains = file_size;
	while(n_remains > 0){

		if(n_remains >= MAX_IO_LENGTH)
			to_write = MAX_IO_LENGTH;
		else
			to_write = n_remains;

		if(write(fd, buf, to_write) != to_write){
			printf("[%s] File write fail\n", __FUNCTION__);
			break;
		}

		n_remains -= to_write;
	}

	/* synchronize the file */
	fsync(fd);
}

void open_test_files(void)
{
	/* Change directory to path */
	if(chdir(path) == -1){
		printf("[%s] Change directory to %s fail\n", __FUNCTION__, path);
		return;
	}

	/* Open a file */
	fd = open(file_name, O_RDWR, 0644);
	if(fd == -1){
		printf("[%s] file %s create fail\n", __FUNCTION__, file_name);
		return;
	}
}

double overwrite_test_files(void)
{
	int i;
	long long file_size = file_size_1k * 1024;
	long long record_size = record_size_1k * 1024;
	long long num_recs = ( (file_size_1k / record_size_1k) * random_ratio ) / 100;
	char buf[record_size];
	long long offset;
	long long *recnum = NULL;

	long long io_time_start, io_time_end;

	memset(buf, 0xefac, record_size);
	recnum = (long long *)malloc(sizeof(*recnum)*num_recs);

	srand((unsigned)time(NULL));
	for(i = 0; i < num_recs; i++) { // re-shuffle the array
		recnum[i] = rand() % num_recs * record_size;
	}

	io_time_start = get_current_utime();

	for(i = 0; i<num_recs; i++){

		offset = (long long)recnum[i];

		if(lseek(fd, offset, SEEK_SET)==-1){
			printf("[%s] File lseek fail\n", __FUNCTION__);
			break;
		}

		if(write(fd, buf, record_size) != record_size){
			printf("[%s] File write fail\n", __FUNCTION__);
			break;
		}
	}
	
	/* synchronize the file */
	fsync(fd);

	io_time_end = get_current_utime();

	return (double)(num_recs * 1000000)/(io_time_end - io_time_start);
}
