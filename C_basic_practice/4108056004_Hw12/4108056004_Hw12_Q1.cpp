//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ı«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
struct student1
{
	int id;
	int math;
	int english;
};
void bubbleM(struct student1 A[]);
void bubbleE(struct student1 A[]);

int main()
{
	struct student1 A[10];
	int i,j,l;
	for(i=0;i<10;i++)
	{
		A[i].id=i+1;
	}
	int seed;
	printf("please input the seed number : ");
	scanf("%d",&seed);
	srand(seed);
	for(j=0;j<10;j++)
	{
		A[j].math=rand()%101;
		A[j].english=rand()%101;
	}
	
	printf("\n");
	for(l=0;l<10;l++)
	{
		printf("id: %3d\t",A[l].id);
		printf("math: %3d\t",A[l].math);
		printf("english: %3d\n",A[l].english);
	}
	bubbleM(A);
	printf("\nmax math score = %d\n",A[0].math);
	printf("id = %d\t",A[0].id);
	int s=1;
	while(A[s].math==A[0].math)
	{
		printf("%d\t",A[s].id);
		s++;
	}
	bubbleE(A);
	printf("\nmax english score = %d\n",A[0].english);
	printf("id = %d\t",A[0].id);
	int s1=1;
	while(A[s1].math==A[0].math)
	{
		printf("%d\t",A[s1].id);
		s1++;
	}
	
	system("pause");
	return 0;
}
void bubbleM(struct student1 A[])
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(A[j].math<A[j+1].math)
			{
				struct student1 temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
void bubbleE(struct student1 A[])
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(A[j].english<A[j+1].english)
			{
				struct student1 temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
