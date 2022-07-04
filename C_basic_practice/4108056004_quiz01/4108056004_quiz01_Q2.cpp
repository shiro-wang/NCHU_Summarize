//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第二題\n\n");
	
	int a,b,c,d;
	int temp,temp_2,temp_3,temp_4;
	printf("Please input four integers :");
	fflush(stdin);
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(c>a)
	{
		temp_2=a;
		temp_3=b;
		temp_4=c;
		a=temp_4;
		b=temp_2;
		c=temp_3;
	}else if(c>b)
	{
		temp=b;
		b=c;
		c=temp;
	}
	if(d>a)
	{
		temp=a;
		temp_2=b;
		temp_3=c;
		temp_4=d;
		a=temp_4;
		b=temp;
		c=temp_2;
		d=temp_3;
	}else if(d>b)
	{
		temp=b;
		temp_2=c;
		temp_3=d;
		b=temp_3;
		c=temp;
		d=temp_2;
	}else if(d>c)
	{
		temp=c;
		c=d;
		d=temp;
	}
	printf("由大至小:%d %d %d %d\n",a,b,c,d);
	system("PAUSE");
	return 0;
}
