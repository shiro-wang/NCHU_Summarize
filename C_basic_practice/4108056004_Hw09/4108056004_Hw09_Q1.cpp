//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
void show(int a[]);
void bubble(int a[]);
void show_inc(int a[]);
void show_dec(int a[]);

int main()
{
	int A[10]={0};
	int i;
	for(i=0;i<SIZE;i++)
	{
		A[i]=rand()%100+1;
	}
	printf("sequence :\n");
	show(A);
	bubble(A);
	char c[100]={0};
	do{	printf("\nplease enter your command : ");
		fflush(stdin);
		gets(c);
	  }while(strcmp(c,"increase")&&strcmp(c,"decrease"));
	  
	if(!strcmp(c,"increase"))
	{
		show_inc(A);
	}else{
		show_dec(A);
	}
	
	system("pause");
	return 0;
}

void show(int A[])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

void bubble(int A[])
{
	int i,j;
	for(i=1;i<SIZE;i++)
	{
		for(j=0;j<SIZE-i;j++)
		{
			if(A[j]>A[j+1])
			{
				int temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
void show_inc(int A[])
{
	int k;
	for(k=0;k<SIZE;k++)
	{
		printf("%d ",A[k]);
	}
}
void show_dec(int A[])
{
	int k;
	for(k=SIZE-1;k>=0;k--)
	{
		printf("%d ",A[k]);
	}
}
