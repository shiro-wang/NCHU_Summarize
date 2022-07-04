//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
unsigned long long int fac(int );

int main()
{
	int num=0;
	unsigned long long int sum=0;
	while(num<1||num>15)
	{
		printf("please enter a number : ");
		fflush(stdin);
		scanf("%d",&num);
	}
	printf("%llu \n",fac(num));
	
	system("pause");
	return 0;
}
unsigned long long int fac(int num)
{
	if(num>0)
	{
		return (num*fac(num-1));
	}else{
		return 1;
	}
}
