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
	fptr=fopen("C:\\quiz3\\in2.txt","r");
	if(fptr==NULL)
	{
		printf("檔案in2開啟失敗!");
		exit(0);
	}
	printf("2.Successfully open input file!!\n");
	fptr2=fopen("C:\\quiz3\\out2.txt","w");
	if(fptr==NULL)
	{
		printf("檔案out2開啟失敗!");
		exit(0);
	}
	printf("3.Successfully open output file!!\n");
	printf("4.Begin to read and process integers in files!!\n");
	
	char ch;
	char s[26];
	int s2[26]={0};
	
	int count=0;
	int i,j;
	int test;
	
	while((ch=getc(fptr))!=EOF)
	{
		if((ch>=65&&ch<=90)||(ch>=96&&ch<=122))
		{
			if(ch>=97&&ch<=122)
			{
				ch-=32;
			}
			for(j=0;j<count;j++)
			{
				if(ch==s[j])
				{
					s2[j]+=1;
					break;
				}	
			}
			if(j==count)
			{
				s[count]=ch;
				s2[count]+=1;
				count++;
			}
		}	
	}
	for(i=0;i<count;i++)
	{
		fprintf(fptr2,"%c=%d\n",s[i],s2[i]);
	}
	
	printf("5.Processed integers are complete!!\n");
	
	
	
	fclose(fptr);
	fclose(fptr2);
	printf("6.Files are closed, output file is complete, end of program!\n");
	
	system("pause");
	return 0;
}
