//��u�t 
//4108056004 
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h> 

int main()
{
	int num,a;
	int total=0;
	printf("�п�J�@�ӼƦr�A�L�X�q1�즹�Ʋ֥[���᪺�M: ");
	fflush(stdin);
	scanf("%d",&num);
	
	for(a=1;a<=num;a++)     //�q�@��a 
	{
		total+=a;           //a�֥[�Jtotal 
	}
	printf("Answer= %d \n",total);
	
	system("PAUSE");
	return 0;
}
