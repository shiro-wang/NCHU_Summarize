//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int ch[20];
	int seed=100;
	srand(seed);
	int i,j;
	for(i=16;i>=0;i--)
	{
		ch[i]=rand()%2;
	}
	printf("Generate a 17 bits binary:");
	for(i=0;i<17;i++)
	{
		printf("%d",ch[i]);
	}
	int sum=0;
	int num=1;
	for(i=0;i<17;i++)
	{
		num=1;
		j=0;
		if(ch[16-i]==1)
		{
			while(j<i)
			{
				num*=2;
				j++;
			}
			sum+=num;
		}
	}
	printf("\nThe converted decimal is %d\n",sum);
	system("pause");
	return 0;
}
