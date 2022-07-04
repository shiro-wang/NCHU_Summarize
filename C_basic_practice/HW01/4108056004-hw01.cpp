//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第一題:\n");
	char ch='a';
	int i=21;
	float n1=123.456;
	double n2=123.456;
	
	printf("Character  : %c\n",ch);
	printf("Decimal    : %d\n",i);
	printf("Unsigned   : %u\n",i);
	printf("Octal      : %o\n",i);
	printf("Hexdecimal : %x\n",i);
	printf("Hexdecimal : %X\n",i);
	printf("Float      : %f	%e  %E\n",n1,n1,n1);
	printf("Double     : %lf %e  %E\n",n2,n2,n2);
	
	system("PAUSE");
	return 0;
}
