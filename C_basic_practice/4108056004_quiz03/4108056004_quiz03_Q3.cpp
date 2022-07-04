//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define L 17
#define k 10
FILE *fptr;
FILE *fptr2;
int state(int );

int main()
{
	int c1=0,c2=0;
	printf("1. Begin to open files!!\n");
	fptr=fopen("C:\\quiz3\\in3.txt","r");
	if(fptr==NULL)
	{
		printf("檔案in3開啟失敗!");
		exit(0);
	}
	printf("2.Successfully open input file!!\n");
	fptr2=fopen("C:\\quiz3\\out3.csv","w");
	if(fptr==NULL)
	{
		printf("檔案out3開啟失敗!");
		exit(0);
	}
	printf("3.Successfully open output file!!\n");
	printf("4.Begin to read and process integers in files!!\n");
	
	char ch;
	int N[L];
	int N2[L];
	int i=0,j,l;
	while((ch=getc(fptr))!=EOF)
	{
		N[i]=ch-48;
		i++;
	}
	printf("Read in string = ");
	for(i=0;i<L;i++)
	{
		printf("%d",N[i]);
	}
	for(i=0;i<L;i++)
	{
		N2[i]=N[L-1-i];
	}
	printf("\nBackward string = ");
	for(i=0;i<L;i++)
	{
		printf("%d",N2[i]);
	}
	
	int sum=0;
	for(i=0;i<L;i++)
	{
		if(N[i]==1)
		{
			j=0;
			l=1;
			while(j<i)
			{
				l*=2;
				j++;
			}
			sum+=l;
		}
	}
	printf("\nThe converted decimal = %d\n",sum);
	
	
	fprintf(fptr2,"Read in string = ");
	for(i=0;i<L;i++)
	{
		fprintf(fptr2,"%d",N[i]);
	}
	fprintf(fptr2,"\nBackward string = ");
	for(i=0;i<L;i++)
	{
		fprintf(fptr2,"%d",N2[i]);
	}
	fprintf(fptr2,"\nThe converted decimal = %d\n",sum);
	//int b=3;
	//printf("%d",state(b));
	printf("Coefficients in Combination Number System\n");
	fprintf(fptr2,"Coefficients in Combination Number System\n");//這邊做不出來 
	int r[k];
	int a=1;
	int i2;
	for(i=k;i>=1;i--)   //一個一個檢查 再減掉所能減的最大值 
	{
		if(sum!=0)
		{
			a=1;
			i2=i;
			while(a<=sum)
			{
				i2++;
				a=state(i2)/state(i);
			}
			i2-=1;
			a=state(i2)/state(i);
			sum-=a;
			r[i-1]=i2;  //將此時的紅數字儲存起來 
		}else{
			r[i-1]=i-1;
		}
	}
	
	for(i=0;i<k;i++)
	{
		printf("%3d",10-i);
		printf("\n");
	}
	for(i=0;i<k;i++)
	{
		printf("%3d",r[k-i]);
		printf("\n");
	}
	
	
	
	printf("5.Processed integers are complete!!\n");
	
	
	
	fclose(fptr);
	fclose(fptr2);
	printf("6.Files are closed, output file is complete, end of program!\n");
	
	system("pause");
	return 0;
}
int state(int a)
{
	int sum=1;
	int i=0;
	while(i<a)
	{
		sum*=(i+1);
		i++;
	}
	return sum;
}
