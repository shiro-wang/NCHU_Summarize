//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("�Ĥ@�D\n\n");
	int i;
	char ch;
	for(i=1;i<=3;i++)
	{
		printf("Please Input Character: ");
		fflush(stdin);
		scanf("%c",&ch);
		
		if(ch>=65&&ch<=90)
		{
			ch=ch+32;
		}else if(ch>=97&&ch<=122)
		{
			ch=ch-32;
		}
		printf("%c \n",ch);
	}
	system("PAUSE");
	return 0;
}
