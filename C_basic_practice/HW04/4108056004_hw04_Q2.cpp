//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define MIN 100
void sorting(int *,int *,int *);

int main()
{
	int seed=20192019;
	srand(seed);
	int a=(rand()%MAX+MIN);
	int b=(rand()%MAX+MIN);
	int c=(rand()%MAX+MIN);
	printf("Initial values ...\n");
	printf(" x = %d   y = %d   z=%d\n\n",a,b,c);
	printf("In main program, Before calling sorting() function ...\n");
	printf(" x = %d   y = %d   z=%d\n\n\n",a,b,c);
	sorting(&a,&b,&c);
	
	printf("Back to main program.\n\n");
	printf("After executing sorting() function...\n");
	printf(" x = %d   y = %d   z=%d\n\n",a,b,c);
	
	system("pause");
	return 0;
}

void sorting(int *a,int *b,int *c)
{
	printf("In sorting() function\n\n");
	printf("Using pointers before sorting process...\n");
	printf(" *a = %d   *b = %d   *c=%d\n\n",*a,*b,*c);
	
	int t[3]={*a,*b,*c};
	
	int i,j,temp;
	for(i=1;i<3;i++)
	{
		for(j=0;j<3-i;j++)
		{
			if(t[j]<t[j+1])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	*a=t[0];
	*b=t[1];
	*c=t[2];
	
	printf("End of the sorting process...\n");
	printf(" *a = %d   *b = %d   *c=%d\n\n\n",*a,*b,*c);
}
