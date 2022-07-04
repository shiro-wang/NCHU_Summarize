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
	fptr=fopen("C:\\hw15\\input1.csv","r");
	if(fptr==NULL)
	{
		printf("檔案input1開啟失敗!");
		exit(0);
	}
	printf("2.Successfully open input file!!\n");
	fptr2=fopen("C:\\hw15\\output1.csv","w");
	if(fptr==NULL)
	{
		printf("檔案output1開啟失敗!");
		exit(0);
	}
	printf("3.Successfully open output file!!\n");
	printf("4.Begin to read and process integers in files!!\n");
	unsigned int t1,t2=0,t;
	int a,b;
	int i=1;
	while(1)
	{
		b=fscanf(fptr,"%d",&t1);
		if(b==EOF)
		{
			break;
		}
		t=t1;
		t2=0;
		while(t1!=0)
		{
			a=t1%10;
			t2+=a;
			t2*=10;
			t1/=10;
		}
		t2/=10;
		
		c1++;
		if(t==t2)
		{
			fprintf(fptr2,"%d,%d,%s\n",i++,t,"palindrome");
			c2++;
		}else{
			fprintf(fptr2,"%d,%d\n",i++,t);
		}
		fprintf(fptr2,"Results:,%d out of %d test integers are palindrome.",c2,c1);
	}
	printf("5.Processed integers are complete!!\n");
	
	
	
	fclose(fptr);
	fclose(fptr2);
	printf("6.Files are closed, output file is complete, end of program!\n");
	
	system("pause");
	return 0;
}
