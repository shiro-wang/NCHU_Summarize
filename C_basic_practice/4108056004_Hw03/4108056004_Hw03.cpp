//��u�t 
//4108056004 
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>


int main()
{
	printf("Question01\n"); 
	int testVariable,TestVariable;
	printf("testVariable���O�����m:%#x \n",&testVariable);
	printf("TestVariable���O�����m:%#x \n\n",&TestVariable);
	
	printf("Question02\n");
	char i;
	printf("�п�J��@�Ӧr��:");
	scanf("%c",&i);
	
	if(i<=90&&i>=65)                            //�]�j�ܤp 
	{
	   printf("%c���p�g�O:%c\n\n",i,i+32);
    }else if(i>=97&&i<=122)
	{
	   printf("%c���j�g�O:%c\n\n",i,i-32);      //�]�p�ܤj 
	}else
	{
		printf("�A������J���@�^��r��\n\n");   //�]���O�r�������p 	                                        
	}                                           //�Q��while�j�餣������r�|�]�⦸�ҥH������ 
    
	printf("Question03\n");
	int j = 0; 
	printf("please enter a natural number:\n");
	scanf("%d",&j);
	while(j<=0)                                 //�D�۵M�ƪ��p 
	{
		printf("%d is not a natural number.\n\n",j);
		printf("please enter a natural number:\n");
	    scanf("%d",&j);
	}
	printf("your natural number is %d \n\n",j);
	
	printf("Question04\n");
	int k=0;
	printf("�p���|�~���YES�A���~��NO\n");
	printf("�p��J�t�ƧY����\n" );
	while(k>=0)
	{
		printf("�п�J�~��: ");
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
