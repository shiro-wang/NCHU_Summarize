//��u�t 
//4108056004 
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("�п�JA����: \n");
	fflush(stdin);
	scanf("%d",&a);
	
	b=(a++)*2;
	printf("A=%d,B=%d\n",a,b);           //B��a�|������   
	
	b=(++a)*2;
	printf("A=%d,B=%d \n",a,b);          // B��a�|��+1���� 
	
	
	system("PAUSE");
	return 0;
}
