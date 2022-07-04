//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int Testprime(int);

int main()
{
	float num;
	int a,b,c;
	int num1,num2;
	int i,j;
	int count=2;
	int sum=0;
	printf("Please enter a positive integer between 5 and 1000:\n");
	fflush(stdin);
	scanf("%f",&num);
	while(num<5||num>1000||num!=(int)num)
	{
		printf("\nInput Eror!\n");
		printf("Please enter a positive integer between 5 and 1000:\n");
		fflush(stdin);
		scanf("%f",&num);
	}
	a=num;
	
    if(Testprime(a)>=2)
    {
    	printf("%d isn't a prime number.\n",a);
    	b=a;
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
		
		count=2;
		c=b;
		while(count==2)
    	{
    		++c;
    		count=0;
    		for(j=1;j<c;j++)
    		{
    			if(c%j==0)
    			{
    				count++;
				}
				if(count==2)
				{
					break;
				}
			}
		}
		
    	
		printf("The next two prime numbers: %d and %d\n",b,c);
	}else{
		printf("%d is a prime number.\n",a);
		count=2;
		b=a;
		while(count==2)
    	{
    		--b;
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
		num1=b;
		count=2;
		c=num1;
		while(count==2)
    	{
    		--c;
    		count=0;
    		for(j=1;j<c;j++)
    		{
    			if(c%j==0)
    			{
    				count++;
				}
				if(count==2)
				{
					break;
				}
			}
		}
		num2=c;
    	
		printf("The previous two prime numbers: %d and %d\n",num1,num2);
		
	}
	
	system("PAUSE");
	return 0;
}
int Testprime(int a)
{
	int i;
	int count=0;
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
    return count;
}
