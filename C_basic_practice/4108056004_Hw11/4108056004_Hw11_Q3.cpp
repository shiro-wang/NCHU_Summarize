//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char N [7][50]={"Joe Chen","Jason Wang","Donald Peterson"};
	strcpy(N[3],N[0]);
	strcpy(N[4],N[1]);
	strcpy(N[5],N[2]);
	strcpy(N[6],N[0]);
	strcat(N[6],N[1]);
	int i;
	for(i=0;i<7;i++)
	{
		printf("%s , %d\n",N[i],strlen(N[i]));
	}
	system("pause");
	return 0;
}
