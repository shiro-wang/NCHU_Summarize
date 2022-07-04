//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k=1,sum=0,a=1;
	do{
		printf("please enter a positive number:\n");
		fflush(stdin);
		scanf("%d",&i);
	}while(i<1||i>10);                                     //防呆 
	
	for(j=1;j<=i;j++)                                      //1!2!3!中的123控制 
	{
		while(k<=j)                                       //超過j(輪流數)時結束換下一個
		{
			a=a*k;                                        //若j到3時，a=1然後傳回再乘2，再傳回乘3，結束後丟出去 
			k++;
		}
		sum+=a;                                           //丟出來的這邊接住 
	}
	printf("the sum is %d\n",sum);
	
	
	system("PAUSE");
	return 0;
	
}
