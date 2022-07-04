//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
FILE *fptr;
FILE *fptr2;

int main()
{
	int c1=0,c2=0;
	printf("1. Begin to open files!!\n");
	fptr=fopen("C:\\quiz3\\in1.txt","r");
	if(fptr==NULL)
	{
		printf("檔案in1開啟失敗!");
		exit(0);
	}
	printf("2.Successfully open input file!!\n");
	fptr2=fopen("C:\\quiz3\\out1.txt","w");
	if(fptr==NULL)
	{
		printf("檔案out1開啟失敗!");
		exit(0);
	}
	printf("3.Successfully open output file!!\n");
	printf("4.Begin to read and process integers in files!!\n");
	int H1,M1,H2,M2;
	int m;
	int b=1;
	while(1)
	{
		fscanf(fptr,"%d %d %d %d",&H1,&M1,&H2,&M2);
		if(H1==0&&M1==0&&H2==0&&M2==0)
		{
			break;
		}
		
		if(H1>H2)
		{
			H2+=24;
		}else if(H1==H2&&M1>M2)
		{
			H2+=24;
		}
		
		m=(H2*60+M2)-(H1*60+M1);
		
		fprintf(fptr2,"%d\n",m);
	}
	printf("5.Processed integers are complete!!\n");
	
	
	
	fclose(fptr);
	fclose(fptr2);
	printf("6.Files are closed, output file is complete, end of program!\n");
	
	system("pause");
	return 0;
}
