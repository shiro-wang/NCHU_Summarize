//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k=1,l,m=1,sum1=0,sum2=0,a=1,b=1;
	printf("please enter a positive integer between 2 and 15:\n");
		fflush(stdin);
		scanf("%d",&i);
	while(i<2||i>15)
	{
		printf("\n Input 2 Error!\n");
		printf("please enter a positive integer between 2 and 15:\n");
		fflush(stdin);
		scanf("%d",&i);
	}                                   //���b 
	
	for(j=1;j<=i;j++)                                      //1!2!3!����123���� 
	{
		while(k<=j)                                       //�W�Lj(���y��)�ɵ������U�@��
		{
			a=a*(-k);                                        //�Yj��3�ɡAa=1�M��Ǧ^�A��2�A�A�Ǧ^��3�A�������X�h 
			k++;
			
		}     
		sum1+=a;                                     //��X�Ӫ��o�䱵�� 
	}
	sum1=-sum1;
	for(l=1;l<=i;l++)
	{
		while(m<=l)                                       
		{
			b=b*m;                                      
			m++;
		}
		if(l%4==1)
			{
				sum2+=b;
			}else if(l%4==3||l%4==0)
			{
				sum2+=(-b);
			}
	}
	
	printf("1. The value of Sum1: %d\n",sum1);
	printf("2. The value of Sum2: %d\n",sum2);
	system("PAUSE");
	return 0;
}
