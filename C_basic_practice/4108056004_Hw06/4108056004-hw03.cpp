//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int hr;
	int min=-1;
	do{                                           //�ӤW�D�g�k 
		printf("please enter hour:\n");
		fflush(stdin);
		scanf("%d",&hr);
	}while(hr<0||hr>23);
	
	while(min<0||min>=60)                         //�դ��@�˪� 
	{
		printf("please enter minute:\n");
		fflush(stdin);
		scanf("%d",&min);
	}
	
	printf("the time is %d:%d\n",hr,min);
	
	system("PAUSE");
	return 0;
}
