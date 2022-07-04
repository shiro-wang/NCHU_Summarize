//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k=1,l,m=1,sum1=0,sum2=0,a=1,b=1;
	printf("please enter a positive integer between 2 and 15:\n");
		fflush(stdin);
		scanf("%d",&i);
	while(i<2||i>15)
	{
		printf("\n Input 2 Error!\n");
		printf("please enter a positive integer between 2 and 15:\n");
		fflush(stdin);
		scanf("%d",&i);
	}                                   //防呆 
	
	for(j=1;j<=i;j++)                                      //1!2!3!中的123控制 
	{
		while(k<=j)                                       //超過j(輪流數)時結束換下一個
		{
			a=a*(-k);                                        //若j到3時，a=1然後傳回再乘2，再傳回乘3，結束後丟出去 
			k++;
			
		}     
		sum1+=a;                                     //丟出來的這邊接住 
	}
	sum1=-sum1;
	for(l=1;l<=i;l++)
	{
		while(m<=l)                                       
		{
			b=b*m;                                      
			m++;
		}
		if(l%4==1)
			{
				sum2+=b;
			}else if(l%4==3||l%4==0)
			{
				sum2+=(-b);
			}
	}
	
	printf("1. The value of Sum1: %d\n",sum1);
	printf("2. The value of Sum2: %d\n",sum2);
	system("PAUSE");
	return 0;
}
