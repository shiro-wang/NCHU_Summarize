//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void Main(int A[]);
int main()
{
	printf("*****  Question 3 *****\n");
	long long int num;
	
	int A[4];
	int flag=0;
	while(!flag)
	{
	printf("Please input a seed: ");
	fflush(stdin);
	flag=scanf("%d",&num);
	}
	srand(num);
	printf("\nProducing random numbers using seed =%d\n",num);
	printf("Original array using the seed %d\n",num);
	
	int i;
	int k=pow(2,15);
	for(i=0;i<4;i++)
	{
		A[i]=rand()%(k+1)-k/2;
		printf("index=%3d. memory=%p. value=%8d\n",i,&A[i],A[i]);
	}
	Main(A);
	printf("*****Question 2 Terminated *****\n");
	system("pause");
	return 0;
}

void Main(int A[])
{
	int B[4];
	printf("\nIn the Main Program\n");
	printf("Reverse arrayy and reverse integers:\n");
	
	
	int i;
	for(i=0;i<4;i++)
	{
		int j,ans=0;
		while(A[3-i]!=0)
		{
			j=A[3-i]%10;
			A[3-i]/=10;
			ans+=j;
			ans*=10;
		}
		B[i]=ans/10;
		printf("index=%3d. memory=%p. value=%8d\n",i,&B[i],B[i]);
	}
}
