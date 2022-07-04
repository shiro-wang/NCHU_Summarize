//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int A[3][4];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			A[i][j]=rand()%100+1;
			if(A[i][j]<30)
			{
				A[i][j]=30;
			}
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
 } 
