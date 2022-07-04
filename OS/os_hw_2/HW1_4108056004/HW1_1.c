#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(){
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int count,range;
	char initialbuffer[1<<20]={'a'};
	char readbuffer[4<<10]={0};
	char writebuffer[2<<10]={'b'};

	FILE* fp;
	fp = fopen("text","w");
	for(int i=0;i<200;i++){
		fwrite(initialbuffer,1,1<<20,fp);
	}
	fclose(fp);
///////////////////////////////start sequential read
	fp = fopen("text","r");
	count=(200<<20)/(4<<10);	
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		fread(readbuffer,1,4<<10,fp);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequentail read 4kb time is:\t%lf(s) \n",(double)diff/1000000);
	fclose(fp);
///////////////////////////////start sequential write
	fp = fopen("text","r+");
	count=(200<<20)/(2<<10);
	
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		fwrite(writebuffer,1,2<<10,fp);
		fsync(fileno(fp));
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the sequential write 2kb time is:\t%lf(s) \n",(double)diff/1000000);
	fclose(fp);
///////////////////////////////start random read
	fp = fopen("text","r");
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		fseek(fp,(rand()%range)<<10,SEEK_SET);
		fread(readbuffer,1,4<<10,fp);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random read 4kb time is:\t%lf(s) \n",(double)diff/1000000);
	fclose(fp);
///////////////////////////////start random write 2kb without fsync
	fp = fopen("text","r+");
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
		fseek(fp,(rand()%range)*(4<<10),SEEK_SET);
		fwrite(writebuffer,1,2<<10,fp);
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 2kb time is(no fsync):\t%lf(s) \n",(double)diff/1000000);
	fclose(fp);
///////////////////////////////start random write 2kb with fsync
	fp = fopen("text","r+");
	count=50000;
	srand(time(NULL));	
	range = (200<<20)/(4<<10);	//4kb offset
	gettimeofday(&start,NULL);
	int r;
	for(int i=0;i<count;i++){
		r=rand() % range;
		//if(i<10){printf("r:%d real:%d\n",r,r*(4<<10));}
		fseek(fp,(r)*(4<<10),SEEK_SET);
		fwrite(writebuffer,1,(2<<10),fp);
		fsync(fileno(fp));
	}
	gettimeofday(&end,NULL);
	diff=1000000*(end.tv_sec - start.tv_sec)+end.tv_usec-start.tv_usec;
	printf("the random write 2kb time is(with fsync):\t%lf(s) \n",(double)diff/1000000);
	fclose(fp);
	return 0;
}
