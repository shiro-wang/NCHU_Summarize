#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int count,range;
	char initialbuffer[1<<20]={0};
	char readbuffer[4<<10]={0};
	char readbuffer_2[3<<10]={0};
	char writebuffer_0[2<<10]={0};
	char writebuffer[3<<10]={0};

	int fp;
	fp = open("text2",O_RDWR | O_CREAT);
	if(fp == -1){
		printf("open text2 failed.\n");
		return 0;
	}
	for(int i=0;i<200;i++){
		write(fp,initialbuffer,1<<20);
	}
	close(fp);
///////////////////////////////start sequential read
	fp = open("text2",O_RDONLY);
	count=(200<<20)/(4<<10);	
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		read(fp,readbuffer,4<<10);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequentail read 4kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start sequential write
	fp = open("text2",O_WRONLY);
	count=(200<<20)/(2<<10);
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		write(fp,writebuffer_0,2<<10);
		fsync(fp);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequential write 2kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random read
	fp = open("text2",O_RDONLY);
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		lseek(fp,(rand()%range)<<10,0);
		read(fp,readbuffer_2,3<<10);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random read 3kb time is:\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random write 3kb without fsync
	fp = open("text2",O_RDWR);
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		lseek(fp,(rand()%range)<<10,0);
		write(fp,writebuffer,3<<10);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 3kb time is(no fsync):\t%lf(s) \n",(double)diff/1000000);
	close(fp);
///////////////////////////////start random write 3kb with fsync
	fp = open("text2",O_RDWR);
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		lseek(fp,(rand()%range)<<10,0);
		write(fp,writebuffer,3<<10);
		fsync(fp);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 3kb time is(with fsync):\t%lf(s) \n",(double)diff/1000000);
	close(fp);
	return 0;
}
