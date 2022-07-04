//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	do{
		printf("please enter a positive integer:\n");
		fflush(stdin);
		scanf("%d",&num);
	}while(num<=0);                            //若不為正整數則繼續 
	
	system("PAUSE");
	return 0;
}
