//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第四題\n\n");
	char sex;
	float a,b;
	printf("請輸入性別(M,F) :");
	fflush(stdin);
	scanf("%c",&sex);
	while(sex!='M'&&sex!='m'&&sex!='F'&&sex!='f')
	{
		printf("請輸入性別(M,F) :");
		fflush(stdin);
		scanf("%c",&sex);
	}
	printf("請輸入身高(cm) :");
	fflush(stdin);
	scanf("%f",&a);
	switch(sex){
		case 'M':
		case 'm': b=(a-80)*0.7;
				  printf("您的標準體重是:%.2f\n",b);
				  break;
		
		default : b=(a-70)*0.6;
				  printf("您的標準體重是:%.2f\n",b);
	}
	
	system("PAUSE");
	return 0;
}
