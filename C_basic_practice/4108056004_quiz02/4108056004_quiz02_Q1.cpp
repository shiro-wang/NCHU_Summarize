//Class: Department of Computer Science and Engineering 
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int GCDFUN(int ,int );
int main()
{
	unsigned long long int a,b;
	printf("*****  Question 1  *****\n");
	printf("Enter any two numbers to find GCD: ");
	fflush(stdin);
	scanf("%u%u",&a,&b);
	
	
	printf("GCD of %d and %d = %d",a,b,GCDFUN(a,b));
	printf("\n*** Question 1 Terminated *****\n");
	system("pause");
	return 0;
}

GCDFUN(int a,int b)
{
	int c=1;
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
