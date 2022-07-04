//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(struct student2 &a,struct student2 &b);
struct student2	
{
	char name[10];	
	int score;
};

int main()
{
	struct student2 a;
	struct student2 b;
	struct student2 c;
	int seed;
	printf("please input the seed number : ");
	scanf("%d",&seed);
	srand(seed);
	strcpy(a.name,"Amy");
	strcpy(b.name,"Bob");
	strcpy(c.name,"Eve");
	a.score=rand()%101;
	b.score=rand()%101;
	c.score=rand()%101;
	printf("\nbefor sorting:\n\n");

	struct student2 A[3];
	A[0]=a;
	A[1]=b;
	A[2]=c;
	int k;
	for(k=0;k<3;k++)
	{
		printf("%s %d\n",A[k].name,A[k].score);
	}
	
	printf("\nAfter sprting:\n\n");
	int i,j;
	for(i=1;i<3;i++)
	{
		for(j=0;j<3-i;j++)
		{
			if(A[j].score>A[j+1].score)
			{
				swap(A[j],A[j+1]);
			}
		}
	}
	
	for(k=0;k<3;k++)
	{
		printf("%s %d\n",A[k].name,A[k].score);
	}
	
	system("pause");
	return 0;
}
void swap(struct student2 &a,struct student2 &b)
{
	struct student2 temp;
	temp=a;
	a=b;
	b=temp;
}
