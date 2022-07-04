//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define N 25
void list(int *);
void swap(int *,int *ptr);
void selection_sort(int *ptr);

int main()
{
	int i,array[N];

	for(i=0;i<N;i++)
	{
		*(array+i)=rand()%1000+250;
	}
	printf("\nSource array ...\n");
	list(array);
	
	selection_sort(array);
	printf("\nSorting ...\n");
	list(array);
	
	system("pause");
	return 0;
}

void list(int *ptr)
{
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("%8d",*(ptr+i));
		if((i+1)%5==0)
		{
			printf("\n");
		}
	}
}

void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}

void selection_sort(int *ptr)
{
	int i,cmp,min;
	
	for(i=0;i<N;i++)
	{
		for(cmp=min=i,cmp++; cmp<N; cmp++)
		{
			if(*(ptr+cmp)<*(ptr+min))
			{
				min=cmp;
			}
			swap((ptr+min),(ptr+i));
		}
	}
}
