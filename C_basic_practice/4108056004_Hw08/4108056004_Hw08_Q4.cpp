//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=-1;
	while(a<=0)
	{
		printf("please enter a number : ");
		fflush(stdin);
		scanf("%d",&a);
	}
	int ch[20][20];
	int i,j;
	
	for(i=0;i<a;i++)
	{
		ch[i][0]=1;
		ch[i][i]=1;
		printf("%d ",ch[i][0]);
		for(j=1;j<=i-1;j++)
		{
			ch[i][j]=ch[i-1][j-1]+ch[i-1][j];
			printf("%d ",ch[i][j]);
		}
		printf("%d",ch[i][i]);
		printf("\n");
	}
	system("pause");
	return 0;
}
