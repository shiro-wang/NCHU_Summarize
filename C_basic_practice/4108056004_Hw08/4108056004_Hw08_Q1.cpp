//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch[3];
	printf("please enter a string : ");
	gets(ch);
	char temp;
	if(ch[0]>ch[1]&&ch[1]>ch[2])
	{
		temp=ch[0];
		ch[0]=ch[2];
		ch[2]=temp;
	}else if(ch[0]>ch[1]&&ch[0>ch[2]&&ch[1]<ch[2]])
	{
		temp=ch[0];
		ch[0]=ch[1];
		ch[1]=ch[2];
		ch[2]=temp;
	}
	if(ch[0]>ch[1]&&ch[0]<ch[2])
	{
		temp=ch[0];
		ch[0]=ch[1];
		ch[1]=temp;
	}else if(ch[0]<ch[1]&&ch[0]>ch[2])
	{
		temp=ch[2];
		ch[2]=ch[1];
		ch[1]=ch[0];
		ch[0]=temp;
	}
	if(ch[0]<ch[1]&&ch[1]>ch[2]&&ch[0]<ch[2])
	{
		temp=ch[1];
		ch[1]=ch[2];
		ch[2]=temp;
	}
	puts(ch);
	
	system("pause");
	return 0;
}
