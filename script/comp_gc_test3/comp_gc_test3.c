#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_IO_LENGTH 524288

int n_threads;
int n_files;
long long file_size_1k;
long long record_size_1k;
int* fd;
char* path;
char** arr_file_name;
pthread_t* t_id;

void init_test_file_names(void);
void create_test_files(void);
void create_worker_thread(void);
void open_test_files(void);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int thread_count = 0;

void* thread_function(void* arg)
{
	long id = (long)arg;

	int i;
	int fd_local = fd[id];
	long long n_remains;
	long long to_write;

	long long file_size;
	long long record_size = record_size_1k * 1024;

	char buf[record_size];

//TEMP_TIME
	int sleep_usec;
	int io_count = 0;
	int n_io = 0;

	pthread_mutex_lock(&mutex1);
	thread_count++;
	pthread_mutex_unlock(&mutex1);

	while(thread_count != n_threads){
		;
	}

	memset(buf, 0xefac, record_size);

	file_size = lseek(fd_local, 0, SEEK_END);

	if (lseek(fd_local, 0, SEEK_SET) == -1){
		printf("[%s] lseek fail!\n", __FUNCTION__);

		/* close the file */
		close(fd_local);

		pthread_exit((void*)0);	
	}

//TEMP_TIME
/*
	srand((unsigned)time(NULL));
	sleep_usec = rand()%1000;
	sleep_usec *= 1000;
	usleep(sleep_usec);
*/
	n_io = rand()%9 + 1;

	n_remains = file_size;
	while(n_remains > 0){

//TEMP
//		printf("[%ld] start io %d/%d\n", id, io_count, n_io);

		if(n_remains >= record_size)
			to_write = record_size;
		else
			to_write = n_remains;

		if(write(fd_local, buf, to_write) != to_write){
			printf("[%s] File write fail [%d, %lld]\n", __FUNCTION__, fd_local, n_remains);
			break;
		}

		n_remains -= to_write;

		io_count++;
		if(io_count == n_io){
			fsync(fd_local);
//			sleep(0.2);

			n_io = rand()%9 + 1;
			io_count = 0;
		}
	}

	/* synchronize the file */
	fsync(fd_local);

	/* close the file */
	close(fd_local);

	pthread_exit((void*)0);	
}

/*
 * ./program path(1) n_threads(2) total_file_size_1K record_size_1k test_mode
 *
 */

int main(int argc, char* argv[])
{
	int i;
	int total_file_size_1k;
	int test_mode;

	path 			= argv[1];		// file path
	n_threads 		= atoi(argv[2]);	// the number of thread
	total_file_size_1k 	= atoi(argv[3]);	// total file size (kbyte)
	record_size_1k		= atoi(argv[4]);	// record size (kbyte)
	test_mode		= atoi(argv[5]);
	file_size_1k 		= total_file_size_1k / n_threads;	// file size for each threads

	init_test_file_names();

	if(test_mode == 0){
		create_test_files();
	}
	else if(test_mode == 1){
		open_test_files();
		create_worker_thread();
	}
	else{
		printf("[%s] Wrong test mode: %d\n", __FUNCTION__, test_mode);
	}

        for(i=0; i<n_files; i++){
                free(arr_file_name[i]);
        }
	free(arr_file_name);

	return 0;
}

void init_test_file_names(void)
{
	int i;
	char temp_c[4];
	char* file_name;

	/* Make n file names for test */
	n_files = n_threads;

	/* Allocate Memory for file name variable */
	file_name = (char*)malloc(strlen(path)+6);
	arr_file_name = (char**)malloc(sizeof(file_name) * n_files);
	for(i=0; i<n_files; i++){
		arr_file_name[i] = (char*)malloc(strlen(path)+6);
	}

	for(i=0; i<n_files; i++){
		/* Make file name*/
		strcpy(file_name, path);
		strncat(file_name, "/", 1);
		sprintf(temp_c,"%d",i);
		strncat(file_name, temp_c, 4);

		/* Update file name array */
		strcpy(arr_file_name[i], file_name);

		/* Reset file name */
		memset(file_name, '\0', sizeof(file_name));
	}
	
	/* Make file descriptor array */
	fd = (int*)malloc(sizeof(int)*n_files);

	/* free memory */
	free(file_name);
}

void create_test_files(void)
{
	int i;
	long long n_remains;
	long long to_write;
	char buf[MAX_IO_LENGTH];
	long long file_size = file_size_1k * 1024;

	memset(buf, 0xcafe, MAX_IO_LENGTH);

	for(i = 0; i<n_files; i++){
		/* Open a file */
		fd[i] = open(arr_file_name[i], O_RDWR | O_CREAT, 0644);

		n_remains = file_size;
		while(n_remains > 0){

			if(n_remains >= MAX_IO_LENGTH)
				to_write = MAX_IO_LENGTH;
			else
				to_write = n_remains;

			if(write(fd[i], buf, to_write) != to_write){
				printf("[%s] File write fail\n", __FUNCTION__);
				break;
			}

			n_remains -= to_write;
		}

		/* synchronize the file */
		fsync(fd[i]);
	}
}

void open_test_files(void)
{
	int i;
	
	for(i = 0; i<n_files; i++){
		/* Open a file */
		fd[i] = open(arr_file_name[i], O_RDWR, 0644);
	}
}

void create_worker_thread(void)
{
	int err;
	long i;
	void* t_ret;

	/* Create worker thread */
	t_id = (pthread_t*)malloc(n_threads*sizeof(pthread_t));

	for(i=0; i<n_threads; i++){
		err = pthread_create(&t_id[i], NULL, thread_function, (void*)i);
		if(err != 0){
			printf("Can't create thread %ld: %s\n", i, strerror(err));
			return;
		}
	}

	/* Wait thread execution */
	for(i=0; i<n_threads; i++){
		err = pthread_join(t_id[i], &t_ret);
		if(err != 0){
			printf("Can't join with thread %ld: %s\n", i, strerror(err));
			return;
		}
	}

	free(t_id);
}
