//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
FILE *fptr;

int main()
{
	int row,ele;
	int num=0,sum=0,count=1;
	int i,j;
	int allsum[5]={0};
	fptr=fopen("C:\\Users\\user\\hw13-Q1-in.txt","r");
	if(fptr!=NULL)
	{
		
		fscanf(fptr,"%d %d",&row,&ele);
		printf("There are %d rows , every row has %d elements.\n",row,ele);
		//printf("%d %d\n",row,ele);
		
		for(i=0;i<row;i++)
		{
			int a,b,c;
			fscanf(fptr,"%d %d %d",&a,&b,&c);
			sum=a+b+c;
			allsum[i]=sum;
		}
		
		
		
		
		
		for(i=0;i<row;i++)
		{
			printf("the sum of row %d = %d\n",i+1,allsum[i]);
		}
		
	}else{
		printf("檔案無法開啟!");
		exit(0);
	}
	fclose(fptr);
	
	system("pause");
	return 0;
}
