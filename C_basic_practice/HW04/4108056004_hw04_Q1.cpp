//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define MAX 6000
#define MIN 300
void swap(int *,int *);

int main()
{
	int seed=2019;
	srand(seed);
	int a=(rand()%MAX+MIN);
	int b=(rand()%MAX+MIN);
	printf("Initial values ...\n");
	printf(" x = %d   y = %d\n\n",a,b);
	printf("In main program, Before calling swap() function ...\n");
	printf(" x = %d   y = %d\n\n\n",a,b);
	swap(&a,&b);
	
	printf("Back to main program.\n\n");
	printf("After executing swap() function...\n");
	printf(" x = %d   y = %d",a,b);
	
	system("pause");
	return 0;
}

void swap(int *a,int *b)
{
	printf("In swap() function\n\n");
	printf("Using pointers before swapping process...\n");
	printf(" *a = %d   *b = %d\n\n",*a,*b);
	
	int temp=*a;
	*a=*b;
	*b=temp;
	printf("End of the swapping process...\n");
	printf(" *a = %d   *b = %d\n\n\n",*a,*b);
}
