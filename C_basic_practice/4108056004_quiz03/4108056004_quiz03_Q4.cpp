//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fptr;
FILE *fptr2;

void bubble(struct student A[],int size);
void show(struct student A[],int size);
struct student
{
	char name[30];
	int num;
	float score;
} *ptr;

int main()
{
	printf("1. Begin to open files!!\n");
	fptr=fopen("C:\\quiz3\\in4.txt","r");
	if(fptr==NULL)
	{
		printf("檔案in4開啟失敗!");
		exit(0);
	}
	printf("2.Successfully open input file!!\n");
	fptr2=fopen("C:\\quiz3\\out4.txt","w");
	if(fptr==NULL)
	{
		printf("檔案out4開啟失敗!");
		exit(0);
	}
	printf("3.Successfully open output file!!\n");
	printf("4.Begin to read and process integers in files!!\n");
	
	int size;
	int i;
	int test;
	
	
	printf("Read in Student Recorders: ");
	scanf("%d",&size);
	
	ptr=(struct student *) malloc(size*sizeof(struct student));
	if(ptr==NULL)
	{
		printf("Error:unable to allocate required memory.\n");
		exit(0);
	}
	printf("\nSuccessfully allocating %d structure memory!",size);
	
	for(i=0;i<size;i++)
	{
		test=fscanf(fptr,"%s %d %f",&(ptr+i)->name,&(ptr+i)->num,&(ptr+i)->score);
		if(test==EOF)
		{
			break;
		}
	}
	printf("\nOriginal Student Records..\n");			
	show(ptr,size);
	
	bubble(ptr,size);
	printf("\nOptional Bubble Sorting by the Roll Field!!\n\n");
	show(ptr,size);
	for(i=0;i<size;i++)
	{
		fprintf(fptr2,"%s %3d %2.2f\n",(ptr+i)->name,(ptr+i)->num,(ptr+i)->score);
	}
	float sum=0;
	float ave;
	for(i=0;i<size;i++)
	{
		sum+=(ptr+i)->score;
	}
	ave=sum/size;
	fprintf(fptr2,"\nTotal Student = %d",size);
	fprintf(fptr2,"\nAverage Scores = %2.2f",ave);
		
			
	free(ptr);
	
	printf("5.Processed integers are complete!!\n");
	
	fclose(fptr);
	fclose(fptr2);
	printf("6.Files are closed, output file is complete, end of program!\n");
	system("pause");
	return 0;
}
void bubble(struct student A[],int size)
{
	int i,j;
	for(i=1;i<size;i++)
	{
		for(j=0;j<size-i;j++)
		{
			if(A[j].num>A[j+1].num)
			{
				struct student temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
			if(A[j].num==A[j+1].num)
			{
				if(A[j].score>A[j+1].score)
				{
					struct student temp;
					temp=A[j];
					A[j]=A[j+1];
					A[j+1]=temp;	
				}
			}
		}
	}
}
void show(struct student A[],int size)
{
	printf("No.     Name     Roll     Scores\n");
	printf("--------------------------------\n");
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d  %9s   %3d   %8.2f\n",i+1,A[i].name,A[i].num,A[i].score);
	} 
}
