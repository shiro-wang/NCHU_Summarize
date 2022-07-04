//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
void sorting(int *);
void swap(int *);

int main()
{
	int A[3],i,num;
	int flag=0;
	printf("*****  Question 4 *****\n\n");
	while(!flag)
	{
	printf("Please input a seed: ");
	fflush(stdin);
	flag=scanf("%d",&num);
	}
	srand(num);
	printf("\nProducing random numbers using seed =%d\n",num);
	printf("Initial values ...\n");
	
	for(i=0;i<3;i++)
	{
		A[i]=rand()%(3001)-1500;
	}
	printf("x = %d. y = %d. z = %d.\n\n",A[0],A[1],A[2]);
	sorting(A);
	printf("In main program ...\n");
	printf("After executing sorting() function ...\n");
	printf("x = %d. y = %d. z = %d.\n\n",A[0],A[1],A[2]);
	swap(A);
	printf("In main program ...\n");
	printf("After executing swapping() function ...\n");
	printf("Swapping the largest and the smallest ...\n");
	printf("x = %d. y = %d. z = %d.\n\n",A[0],A[1],A[2]);
	printf("*****Question 4 Terminated *****\n");
	
	system("pause");
	return 0;
}
void sorting(int *ptr)
{
	int i,j;
	for(i=1;i<3;i++)
	{
		for(j=0;j<3-i;j++)
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
void swap(int *ptr)
{
	int temp;
	temp=*(ptr+0);
	*(ptr+0)=*(ptr+2);
	*(ptr+2)=temp;
}
