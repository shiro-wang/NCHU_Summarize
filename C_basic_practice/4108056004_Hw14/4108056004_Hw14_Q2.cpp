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
	fptr=fopen("C:\\hw14\\input2.txt","r");
	if(fptr==NULL)
	{
		printf("檔案input2開啟失敗!");
		exit(0);
	}
	int i,num1=0,num2=0;
	char a[100]={0},b[100]={0};
	char ch;
	while((ch=getc(fptr))!='\n')
	{
		a[num1]=ch;
		num1++;
	}
	//printf("%s\n",a);
	
	while((ch=getc(fptr))!=EOF)
	{
		b[num2]=ch;
		num2++;
	}
	//printf("%s\n",b);
	fclose(fptr);
	
	fptr2=fopen("C:\\hw14\\output2.txt","w");
	if(fptr==NULL)
	{
		printf("檔案output2開啟失敗!");
		exit(0);
	}
	if(num1==num2)
	{
		for(i=0;i<num1;i++)
		{
			fprintf(fptr,"%c%c\n",b[i],a[i]);
		}
	}else if(num1>num2)
	{
		for(i=0;i<num2;i++)
		{
			fprintf(fptr,"%c%c\n",b[i],a[i]);
		}
		for(i=num2;i<num1;i++)
		{
			fprintf(fptr," %c\n",a[i]);
		} 
	}else{
		for(i=0;i<num1;i++)
		{
			fprintf(fptr,"%c%c\n",b[i],a[i]);
		}
		for(i=num1;i<num2;i++)
		{
			fprintf(fptr,"%c\n",b[i]);
		}	
	}
	
	
	fclose(fptr2);
	printf("complete!\n");
	
	system("pause");
	return 0;
}
