//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k=1,sum=0,a=1;
	do{
		printf("please enter a positive number:\n");
		fflush(stdin);
		scanf("%d",&i);
	}while(i<1||i>10);                                     //���b 
	
	for(j=1;j<=i;j++)                                      //1!2!3!����123���� 
	{
		while(k<=j)                                       //�W�Lj(���y��)�ɵ������U�@��
		{
			a=a*k;                                        //�Yj��3�ɡAa=1�M��Ǧ^�A��2�A�A�Ǧ^��3�A�������X�h 
			k++;
		}
		sum+=a;                                           //��X�Ӫ��o�䱵�� 
	}
	printf("the sum is %d\n",sum);
	
	
	system("PAUSE");
	return 0;
	
}
