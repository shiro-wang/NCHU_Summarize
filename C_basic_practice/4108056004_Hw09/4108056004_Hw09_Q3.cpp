//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
void Mm(int A[3][3], int C[2]);

int main()
{
	int i,j;
	int A[3][3]={0};
	int C[2]={0};
	printf("array A[3][3] : \n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			A[i][j]=rand()%100+1;
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	Mm(A, C);
	
	printf("\nmax = %d\n",C[0]);
	printf("min = %d\n",C[1]);
	system("pause");
	return 0;
}

void Mm(int A[3][3], int C[2])
{
	int i,j;
	int max=A[0][0];
	int min=A[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(A[i][j]>max)
			{
				max=A[i][j];
			}else if(A[i][j]<min)
			{
				min=A[i][j];
			}
		}
	}
	
	C[0]=max;
	C[1]=min;
}
