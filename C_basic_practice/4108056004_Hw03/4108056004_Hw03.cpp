//資工系 
//4108056004 
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>


int main()
{
	printf("Question01\n"); 
	int testVariable,TestVariable;
	printf("testVariable的記憶體位置:%#x \n",&testVariable);
	printf("TestVariable的記憶體位置:%#x \n\n",&TestVariable);
	
	printf("Question02\n");
	char i;
	printf("請輸入單一個字母:");
	scanf("%c",&i);
	
	if(i<=90&&i>=65)                            //設大變小 
	{
	   printf("%c的小寫是:%c\n\n",i,i+32);
    }else if(i>=97&&i<=122)
	{
	   printf("%c的大寫是:%c\n\n",i,i-32);      //設小變大 
	}else
	{
		printf("你必須輸入任一英文字母\n\n");   //設不是字母的狀況 	                                        
	}                                           //想用while迴圈不知為何字會跑兩次所以先不用 
    
	printf("Question03\n");
	int j = 0; 
	printf("please enter a natural number:\n");
	scanf("%d",&j);
	while(j<=0)                                 //非自然數狀況 
	{
		printf("%d is not a natural number.\n\n",j);
		printf("please enter a natural number:\n");
	    scanf("%d",&j);
	}
	printf("your natural number is %d \n\n",j);
	
	printf("Question04\n");
	int k=0;
	printf("如為閏年顯示YES，平年為NO\n");
	printf("如輸入負數即結束\n" );
	while(k>=0)
	{
		printf("請輸入年份: ");
	    scanf("%d",&k);
		if(k%4==0)                            
		{
			if(k%100==0)
			{
				if(k%400==0)
				{
					printf("YES \n");
				}
				if(k%400!=0)
				{
					printf("NO \n");
				}
			}
			if(k%100!=0)
			{
				printf("YES \n");
			}
			
		}
		if(k%4!=0)
		{
			printf("NO \n");
		}
		
	}
	
	
	system("PAUSE");
	return 0;
	
}
