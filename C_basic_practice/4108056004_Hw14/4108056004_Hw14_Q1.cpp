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
	fptr=fopen("C:\\hw14\\input1.txt","r");
	if(fptr==NULL)
	{
		printf("檔案input1開啟失敗!");
		exit(0);
	}
	int t,i,j,a,b;
	int sum=0;
	
	fscanf(fptr,"%d",&t);
	int c[t];
	
	for(i=0;i<t;i++)
	{
		sum=0;
		fscanf(fptr,"%d %d",&a,&b);
		for(j=a;j<=b;j++)
		{
			if(j%2==0)
			{
				sum+=j;
			}
		}
		c[i]=sum;
	}
	fclose(fptr);
	
	fptr2=fopen("C:\\hw14\\output1.txt","w");
	if(fptr==NULL)
	{
		printf("檔案output1開啟失敗!");
		exit(0);
	}
	for(i=0;i<t;i++)
	{
		fprintf(fptr,"Case %d: %d\n",i+1,c[i]);
	}
	fclose(fptr2);
	printf("complete!\n");
	
	system("pause");
	return 0;
}
