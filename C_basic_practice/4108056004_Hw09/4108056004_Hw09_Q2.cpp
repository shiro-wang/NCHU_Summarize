//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[3][2]={0};
	int B[2][3]={0};
	int C[3][3]={0};
	int i,j;
	printf("array A[3][2] : \n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			A[i][j]=rand()%100+1;
			printf("%3d",A[i][j]);
		}
		printf("\n");
	}
	printf("\narray B[2][3] : \n\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			B[i][j]=rand()%100+1;
			printf("%3d",B[i][j]);
		}
		printf("\n");
	}
	printf("\narray C[3][3] : \n\n");
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			C[i][j]=A[i][0]*B[0][j]+A[i][1]*B[1][j];
			printf("%3d",C[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}
