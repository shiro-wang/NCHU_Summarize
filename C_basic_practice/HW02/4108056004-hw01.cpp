//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("�Ĥ@�D\n\n");
	int d=1;
	while(d>=1&&d<=7)
	{
		printf("�п�J���ѬP���X:");
		fflush(stdin);
		scanf("%d",&d);
		
		if(d>=1&&d<=5)
		{
			printf("���ѭn�W�Z�W��!\n\n");
		}else if(d==6||d==7){
			printf("�n! �Ψ�۵M��~\n");
		}
	}
	printf("�z��J�Ʀr�D1~7�A�N�۰ʰh�X�C\n");
	
	system("PAUSE");
	return 0;
}
