//��u�t 
//4108056004 
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c;
	float r,t;
	printf("�п�J�ϥΦ���ഫ(����ഫ�ؤ��Jc�A�ؤ��ഫ����Jf): \n");
	scanf("%s",&c);
	
	while(c!='c'&&c!='f'&&c!='C'&&c!='F')                                             //��J���b 
	{
		printf("�z��J���O�L�Ħr��!! \n");
		printf("�п�J�ϥΦ���ഫ(����ഫ�ؤ��Jc�A�ؤ��ഫ����Jf): \n");
		scanf("%s",&c);
	}
	
	if(c=='c'||c=='C')                                                                  //C��F 
	{
		printf("�бz��J���ū�:");
		scanf("%f",&r);
		while(r<-273.15)                                                           //�X�kC>=-273.15 
		{
			printf("�z��J���ūפ��A�X�k�d�� \n");
			printf("�бz��J���ū�:");
			scanf("%f",&r);
		}
		t=r*9/5+32;
		printf("�g�ഫ�ؤ�ū׬�:%f\n\n",t);	
	}
	
	if(c=='f'||c=='F')                                                            //F��C 
	{
		printf("�бz��J�ؤ�ū�:");
		scanf("%f",&r);
		while(r<-459.67)                                                          //�X�kF>=-459.67 
		{
			printf("�z��J���ūפ��A�X�k�d�� \n");
			printf("�бz��J���ū�:");
			scanf("%f",&r);
		}
		t=(r-32)*5/9;
		printf("�g�ഫ���ū׬�:%f\n\n",t);
	}
	
	system("PAUSE");
	return 0;
		
}
