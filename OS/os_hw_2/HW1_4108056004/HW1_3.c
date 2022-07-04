#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(){
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int count,range;
	char initialbuffer[1<<20]={0};
	char readbuffer[4<<10]={0};
	char readbuffer_2[3<<10]={0};
	char writebuffer_2kb[2<<10]={0};
	char writebuffer_3kb[3<<10]={0};
	char writebuffer_4kb[4<<10]={0};

	int fp;
	char *map_fp;
	struct stat st;
	long int filesize;
	int r;
/////////////////////////////initial
	fp = open("text3",O_RDWR | O_CREAT);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	for(int i=0;i<200;i++){
		write(fp,initialbuffer,1<<20);
	}
	close(fp);
///////////////////////////////start sequential read
	fp = open("text3",O_RDWR);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	stat("text3",&st);
	filesize = st.st_size;
	map_fp = mmap(NULL, filesize, PROT_WRITE | PROT_READ, MAP_SHARED, fp, 0);
	count=(200<<20)/(4<<10);	
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		memcpy(readbuffer, map_fp, (4<<10));
		map_fp += (4<<10);	
	}
	
	gettimeofday(&end,NULL);
	for(int i=0;i<count;i++){
		map_fp -= (4<<10);	
	}
	munmap(map_fp, filesize);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequentail read 4kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start sequential write
	fp = open("text3",O_RDWR);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	count=(200<<20)/(2<<10);
	stat("text3",&st);
	filesize = st.st_size;
	map_fp = mmap(NULL, filesize, PROT_WRITE | PROT_READ, MAP_SHARED, fp, 0);
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		memcpy(map_fp, writebuffer_2kb, (2<<10));
		map_fp += (2<<10);
		fsync(fp);
	}
	gettimeofday(&end,NULL);
	for(int i=0;i<count;i++){
		map_fp -= (2<<10);	
	}
	munmap(map_fp, filesize);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequential write 2kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random read
	fp = open("text3",O_RDWR);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	count=50000;
	stat("text3",&st);
	filesize = st.st_size;
	map_fp = mmap(NULL, filesize, PROT_WRITE | PROT_READ, MAP_SHARED, fp, 0);
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		r=rand()%range;
		map_fp += (r<<10);
		memcpy(readbuffer_2, map_fp, (3<<10));
		map_fp -= (r<<10);
	}
	gettimeofday(&end,NULL);

	munmap(map_fp, filesize);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random read 3kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random write 4kb without fsync
	fp = open("text3",O_RDWR);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	count=50000;
	stat("text3",&st);
	filesize = st.st_size;
	map_fp = mmap(NULL, filesize, PROT_WRITE | PROT_READ, MAP_SHARED, fp, 0);
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset

	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		r=rand()%range;
		map_fp += (r<<10);
		memcpy(map_fp, writebuffer_4kb,(4<<10));
		map_fp -= (r<<10);
	}
	gettimeofday(&end,NULL);

	munmap(map_fp, filesize);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 4kb time is(no fsync):\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random write 3kb with fsync
	fp = open("text3",O_RDWR);
	if(fp == -1){
		printf("open text3 failed.\n");
		return 0;
	}
	count=50000;
	stat("text3",&st);
	filesize = st.st_size;
	map_fp = mmap(NULL, filesize, PROT_WRITE | PROT_READ, MAP_SHARED, fp, 0);
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset

	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		r=rand()%range;
		map_fp += (r<<10);
		memcpy(map_fp, writebuffer_3kb,(3<<10));
		fsync(fp);
		map_fp -= (r<<10);
	}
	gettimeofday(&end,NULL);

	munmap(map_fp, filesize);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 3kb time is(no fsync):\t%lf(s) \n",(double)diff/1000000);
	close(fp);
	return 0;
}
