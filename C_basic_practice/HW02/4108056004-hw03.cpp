//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第三題\n\n");
	int m;
	printf("請輸入月份:");
	fflush(stdin);
	scanf("%d",&m);
	while(m<1||m>12)
	{
		printf("Please enter the month 1~12:");
		scanf("%d",&m);
	}
	switch(m){
		case 3:
		case 4:
		case 5: printf("Spring.\n");
				break;
		
		case 6:
		case 7:
		case 8: printf("Summer.\n");
				break;
		
		case 9:
		case 10:
		case 11: printf("Autumn.\n");
				 break;
		
		default: printf("Winter.\n");
	}
	
	system("PAUSE");
	return 0;
	
}
