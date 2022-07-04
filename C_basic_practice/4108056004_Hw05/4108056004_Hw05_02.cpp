//資工系 
//4108056004 
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h> 

int main()
{
	int num,a;
	int total=0;
	printf("請輸入一個數字，印出從1到此數累加之後的和: ");
	fflush(stdin);
	scanf("%d",&num);
	
	for(a=1;a<=num;a++)     //從一到a 
	{
		total+=a;           //a累加入total 
	}
	printf("Answer= %d \n",total);
	
	system("PAUSE");
	return 0;
}
