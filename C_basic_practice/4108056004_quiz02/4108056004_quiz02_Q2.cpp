//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int A;
	int flag=0;
	printf("*****  Question 2 *****\n");
	while(!flag)
	{
	printf("Enter an intger number to calculate product of digit: ");
	fflush(stdin);
	flag=scanf("%lld",&A);
	}
	
	int i=0,j,ans=1;
	if(A>0)
	{
		while(A!=0)
		{
			j=A%10;
			A/=10;
			ans*=j;
			i++;
		}
	}else if(A<0){
		A=-A;
		while(A!=0)
		{
			j=A%10;
			A/=10;
			ans*=j;
			i++;
		}
		ans=-ans;
	}else{
		ans=0;
	}
	printf("Input has %d digits\n",i);
	printf("Product of digit = %d\n\n",ans);
	
	printf("*****Question 2 Terminated *****\n");
	system("pause");
	return 0;
}
