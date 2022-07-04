//資工系 
//4108056004 
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c;
	float r,t;
	printf("請輸入使用何種轉換(攝氏轉換華氏輸入c，華氏轉換攝氏輸入f): \n");
	scanf("%s",&c);
	
	while(c!='c'&&c!='f'&&c!='C'&&c!='F')                                             //輸入防呆 
	{
		printf("您輸入的是無效字元!! \n");
		printf("請輸入使用何種轉換(攝氏轉換華氏輸入c，華氏轉換攝氏輸入f): \n");
		scanf("%s",&c);
	}
	
	if(c=='c'||c=='C')                                                                  //C轉F 
	{
		printf("請您輸入攝氏溫度:");
		scanf("%f",&r);
		while(r<-273.15)                                                           //合法C>=-273.15 
		{
			printf("您輸入的溫度不再合法範圍內 \n");
			printf("請您輸入攝氏溫度:");
			scanf("%f",&r);
		}
		t=r*9/5+32;
		printf("經轉換華氏溫度為:%f\n\n",t);	
	}
	
	if(c=='f'||c=='F')                                                            //F轉C 
	{
		printf("請您輸入華氏溫度:");
		scanf("%f",&r);
		while(r<-459.67)                                                          //合法F>=-459.67 
		{
			printf("您輸入的溫度不再合法範圍內 \n");
			printf("請您輸入攝氏溫度:");
			scanf("%f",&r);
		}
		t=(r-32)*5/9;
		printf("經轉換攝氏溫度為:%f\n\n",t);
	}
	
	system("PAUSE");
	return 0;
		
}
