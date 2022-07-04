//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
float Maxvalue(float);

int main()
{
	float a,b,c;
	int flag=0;
	printf("Please enter three numbers:");
	fflush(stdin);
	flag=scanf("%f %f %f",a,b,c);
	while(flag!=3)
	{
		printf("Input Error 1!\n\n");
		printf("Please enter three numbers:");
		flag=scanf("%f %f %f",a,b,c);
	}
	printf("The biggest number is: %f",Maxvalue(a));
	
	system("PAUSE");
	return 0;
}
float Maxvalue(float a,float b,float c)
{
	int temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(c>a)
	{
		temp=a;
		a=c;
		c=temp;
	}
	
	return a;
}
