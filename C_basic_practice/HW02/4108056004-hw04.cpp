//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("�ĥ|�D\n\n");
	char sex;
	float a,b;
	printf("�п�J�ʧO(M,F) :");
	fflush(stdin);
	scanf("%c",&sex);
	while(sex!='M'&&sex!='m'&&sex!='F'&&sex!='f')
	{
		printf("�п�J�ʧO(M,F) :");
		fflush(stdin);
		scanf("%c",&sex);
	}
	printf("�п�J����(cm) :");
	fflush(stdin);
	scanf("%f",&a);
	switch(sex){
		case 'M':
		case 'm': b=(a-80)*0.7;
				  printf("�z���з��魫�O:%.2f\n",b);
				  break;
		
		default : b=(a-70)*0.6;
				  printf("�z���з��魫�O:%.2f\n",b);
	}
	
	system("PAUSE");
	return 0;
}
