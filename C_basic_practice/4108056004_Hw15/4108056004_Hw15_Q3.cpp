//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int a=0,b=0;
	while(a<1||a>9)
	{
		printf("Enter the amplitude: ");
		fflush(stdin);
		scanf("%d",&a);
	}
	while(b<1||b>9)
	{
		printf("Enter the number of waves: ");
		fflush(stdin);
		scanf("%d",&b);
	}
	int i,j,k;
	for(i=0;i<b;i++)
	{
		for(j=1;j<=a;j++)
		{
			printf("\n");
			for(k=0;k<j;k++)
			{
				printf("%d",j);
			}
									
		}
		for(j=a-1;j>=1;j--)
		{
			printf("\n");
			for(k=0;k<j;k++)
			{
				printf("%d",j);
			}
			
		}
		printf("\n");
	}
	
	
	system("pause");
	return 0;
}
