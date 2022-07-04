//資工系 
//4108056004 
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("請輸入A的值: \n");
	fflush(stdin);
	scanf("%d",&a);
	
	b=(a++)*2;
	printf("A=%d,B=%d\n",a,b);           //B值a會先執行   
	
	b=(++a)*2;
	printf("A=%d,B=%d \n",a,b);          // B值a會先+1執行 
	
	
	system("PAUSE");
	return 0;
}
