//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
float Maxvalue(float ,float, float );

int main()
{
	float a,b,c,d;
	int flag;
	printf("Please enter three numbers, and enter ok in the end:");
	fflush(stdin);
	flag=scanf("%f%f%f%f",&a,&b,&c,&d);
	//多一個d防止輸入4個數字以上  有點爛的方法... 
	
	while(flag!=3)
	{
		printf("Input Error 1!\n\n");
		printf("Please enter three numbers, and enter ok in the end:");
		fflush(stdin);
		flag=scanf("%f %f %f%f",&a,&b,&c,&d);
		
	}

	printf("The largest number is: %f\n",Maxvalue(a,b,c));
	
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
