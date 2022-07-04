//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int prime(int);
int notprime(int);

int main()
{
	float num;
	int a;
	int i;
	int count=0;
	printf("Please enter a positive integer between 2 and 100:\n");
	fflush(stdin);
	scanf("%f",&num);
	while(num<2||num>100)
	{
		printf("\nInput Eror!\n");
		printf("Please enter a positive integer between 2 and 100:\n");
		fflush(stdin);
		scanf("%f",&num);
	}
	a=num;
	printf("\nFloating %f is converted to integer type %d\n\n",num,a);
	for(i=1;i<a;i++)
	{
	   if(a%i==0)
	   {
	       count++;
	   }
	   if(count>=2)
	   {
	   	    break;
	   }
    }
    if(count>=2)
    {
    	printf("3.The input number isn't a prime number: %d\n",a);
		printf("4.Accumulating value from 2 to %d becomes: %d\n",a,notprime(a));
	}else{
		printf("1.The input number is a prime number: %d\n",a);
		printf("2.The next prime number is: %d\n",prime(a));
		
	}
	
	system("PAUSE");
	return 0;
}
int prime(int a)
{
	int b=a;
	int count=2;
	int i;
	while(count==2)
	{
		++b;
		count=0; 
		for(i=1;i<b;i++)
		{
	   		if(b%i==0)
			{
	     	   count++;
	   		}
	   		
	   		if(count==2)
	   		{
	   	  	    break;
	   		}
    	}
    	
	} 
	return b;
}
int notprime(int a)
{
	int i,j,sum=0;
	for(i=2;i<=a;i++)
	{
		sum+=i;
	}
	return sum;
}
