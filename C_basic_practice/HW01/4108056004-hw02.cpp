//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第二題:\n");
	int x=10, y=20;
	int a=0,b=0,c=0;
	char s[10]="Hello";
	int printf_value;
	int scanf_value;
	
	printf_value=printf("%s\n",s);
	printf("Printf return value is %d\n",printf_value);
	
	
	printf_value=printf("%d + %d = %d\n",x,y,x+y);
	printf("Printf return value is %d\n",printf_value);
	
	
	printf("Input three decimal value :\n");
	fflush(stdin);
	scanf_value=scanf("%d %d %d",&a,&b,&c);
	printf("Scanf return value is %d\n",scanf_value);
	
	
	system("PAUSE");
	return 0;
}
