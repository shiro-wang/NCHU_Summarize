//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bubble(int *);
void show_inc(int *);
void show_dec(int *);

int main()
{
	int A[10]={0};
	int i;
	
	char ch[10]={0};
	printf("sequence :\n");
	for(i=0;i<10;i++)
	{
		*(A+i)=rand()%100+1;
		printf("%d ",*(A+i));
	}
	printf("\n\n");
	while(strcmp(ch,"increase")&&strcmp(ch,"decrease"))
	{
		printf("please enter your command : ");
		fflush(stdin);
		gets(ch);
		printf("\n");
	}
	bubble(A);
	printf("after using bubble sort :\n");
	if(!strcmp(ch,"increase"))
	{
		show_inc(A);
	}else{
		show_dec(A);
	}
	
	system("pause");
	return 0;
}

void bubble(int *ptr)
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(*(ptr+j)<*(ptr+j+1))
			{
				int temp;
				temp=*(ptr+j);
				*(ptr+j)=*(ptr+j+1);
				*(ptr+j+1)=temp;
			}
		}
	}
}

void show_dec(int *ptr1)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",*(ptr1+i));
	}
	printf("\n");
}
void show_inc(int *ptr2)
{
	int i;
	for(i=9;i>=0;i--)
	{
		printf("%d ",*(ptr2+i));
	}
	printf("\n");
}
