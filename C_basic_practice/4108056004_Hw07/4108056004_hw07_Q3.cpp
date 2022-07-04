//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int C(int ,int );

int main()
{
	int m=0,n=0;
	printf("請輸入兩個正整數M,N，且M需大於等於N，M介在1~10之間，N介在1~5之間\n");
	printf("M=");
	fflush(stdin);
	scanf("%d",&m);
	printf("N=");
	fflush(stdin);
	scanf("%d",&n);
	while(m<1||m>10||n<0||n>5||m<n)
	{
		printf("輸入錯誤!\n\n");
		printf("M=");
		fflush(stdin);
		scanf("%d",&m);
		printf("N=");
		fflush(stdin);
		scanf("%d",&n);
	}
	
	printf("C %d 取 %d = %d\n",m,n,C(m,n));
	
	system("pause");
	return 0;
}

int C(int m,int n)
{
	if(n>0)
	{
		// /n放後面，這樣就不會在像是C10 5時，輪到9/4被強制去除小數 
		printf("%d %d\n",m,n);
		return (m*C(m-1,n-1)/n);
	}else{
		return 1;
	}
}
