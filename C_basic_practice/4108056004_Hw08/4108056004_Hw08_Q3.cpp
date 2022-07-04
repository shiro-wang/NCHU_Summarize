//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=-1;
	while(a<0)
	{
		printf("please enter a non-negative integer : ");
		fflush(stdin);
		scanf("%d",&a);
	}
	int ch[a+1];
	int i;
	ch[0]=0;
	ch[1]=1;
	for(i=2;i<=a+1;i++)
	{
		ch[i]=ch[i-1]+ch[i-2];
	}
	int k;
	for(k=0;k<a+1;k++)
	{
		printf("%d ",ch[k]);
	}
	
	system("pause");
	return 0;
}
