//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ı«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
struct student3
{
	int id;
	int score;
	int group;
};
int main()
{
	struct student3 A[10];
	int seed;
	int i,j,k;
	printf("please input the seed number : ");
	scanf("%d",&seed);
	srand(seed);
	for(i=0;i<10;i++)
	{
		A[i].id=i+1;
		A[i].score=rand()%101;
		A[i].group=rand()%2+1;
	}
	for(j=0;j<10;j++)
	{
		printf("id: %3d, ",A[j].id);
		printf("score: %3d ,",A[j].score);
		printf("group: %3d\n",A[j].group);
	}
	

	int n1=0,n2=0;
	printf("\ngroup 1 :\n");
	printf("id= ");
	for(k=0;k<10;k++)
	{	
		if(A[k].group==1)
		{
			printf("%3d",A[k].id);
			n1++;
		}
	}
	printf("\n\ngroup 2 :\n");
	printf("id= ");
	for(k=0;k<10;k++)
	{
		if(A[k].group==2)
		{
			printf("%3d",A[k].id);
			n2++;
		}
	}
	struct student3 B[n1];
	struct student3 C[n2];
	n1=0;
	n2=0;
	for(k=0;k<10;k++)
	{	
		if(A[k].group==1)
		{
			B[n1]=A[k];
			n1++;
		}
	}	
	for(k=0;k<10;k++)
	{	
		if(A[k].group==2)
		{
			C[n2]=A[k];
			n2++;
		}
	}	
/*	printf("\nG1\n");
	for(j=0;j<n1;j++)
	{
		printf("id: %3d, ",B[j].id);
		printf("score: %3d ,",B[j].score);
		printf("group: %3d\n",B[j].group);
	}*/
	

	
	
	
	for(i=1;i<n1;i++)
	{
		for(j=0;j<n1-i;j++)
		{
			if(B[j].score<B[j+1].score)
			{
				struct student3 temp;
				temp=B[j];
				B[j]=B[j+1];
				B[j+1]=temp;
			}
		}
	}
	printf("\n\nmax score in group 1 : %d\n",B[0].score);
	printf("id = %3d",B[0].id);
	int s=1;
	while(B[s].score==B[0].score)
	{
		printf("%3d",B[s].id);
		s++;
	}
	
	for(i=1;i<n2;i++)
	{
		for(j=0;j<n2-i;j++)
		{
			if(C[j].score<C[j+1].score)
			{
				struct student3 temp;
				temp=C[j];
				C[j]=C[j+1];
				C[j+1]=temp;
			}
		}
	}
	printf("\n\nmax score in group 2 : %d\n",C[0].score);
	printf("id = %3d",C[0].id);
	s=1;
	while(C[s].score==C[0].score)
	{
		printf("%3d",C[s].id);
		s++;
	}
	
	system("pause");
	return 0;
	
	
}

