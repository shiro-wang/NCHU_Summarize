//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int C(int ,int );

int main()
{
	int m=0,n=0;
	printf("�п�J��ӥ����M,N�A�BM�ݤj�󵥩�N�AM���b1~10�����AN���b1~5����\n");
	printf("M=");
	fflush(stdin);
	scanf("%d",&m);
	printf("N=");
	fflush(stdin);
	scanf("%d",&n);
	while(m<1||m>10||n<0||n>5||m<n)
	{
		printf("��J���~!\n\n");
		printf("M=");
		fflush(stdin);
		scanf("%d",&m);
		printf("N=");
		fflush(stdin);
		scanf("%d",&n);
	}
	
	printf("C %d �� %d = %d\n",m,n,C(m,n));
	
	system("pause");
	return 0;
}

int C(int m,int n)
{
	if(n>0)
	{
		// /n��᭱�A�o�˴N���|�b���OC10 5�ɡA����9/4�Q�j��h���p�� 
		printf("%d %d\n",m,n);
		return (m*C(m-1,n-1)/n);
	}else{
		return 1;
	}
}
