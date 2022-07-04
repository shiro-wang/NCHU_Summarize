//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第一題\n\n");
	int d=1;
	while(d>=1&&d<=7)
	{
		printf("請輸入今天星期幾:");
		fflush(stdin);
		scanf("%d",&d);
		
		if(d>=1&&d<=5)
		{
			printf("今天要上班上課!\n\n");
		}else if(d==6||d==7){
			printf("爽! 睡到自然醒~\n");
		}
	}
	printf("您輸入數字非1~7，將自動退出。\n");
	
	system("PAUSE");
	return 0;
}
