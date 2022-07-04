//Class: Department of Computer Science and Engineering 
//Registration Number:4108056004
//Name:¤ı«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define STUDNO 10
struct student
{
	int regi;
	float math;
	float scie;
};

void Disp_struc(struct student stud[]);
void Bubble_opt(struct student stud[]);
float AveMath(struct student stud[]);
float AveScie(struct student stud[]);

int main()
{
	struct student stud[STUDNO];
	int seed;
	printf("Program begin .....\n\n");
	printf("Please input a seed: ");
	fflush(stdin);
	scanf("%d",&seed);
	srand(seed);
	printf("\nProducing random numbers for stud array of structure using seed= %d\n",seed);
	
	int i,k;
	for(i=0;i<STUDNO;i++)
	{
		stud[i].math=(rand()%1001)/10.0;
		stud[i].scie=(rand()%1001)/10.0;
	}

	for(k=0;k<STUDNO;k++)
	{
		stud[k].regi=k+1;
	}
	printf("Original array of structure ...\n");
	Disp_struc(stud);
	
	printf("\nSorting array of structure based on math ...\n");
	Bubble_opt(stud);
	Disp_struc(stud);
	
	printf("------------------------------------------\n");
	printf("Ave.    \t      %4.1f\t      %4.1f\n",AveMath(stud),AveScie(stud));
	
	system("pause");
	return 0;
}

void Disp_struc(struct student stud[])
{
	int i;
	for(i=0;i<STUDNO;i++)
	{
		printf("regi: %03d\t",stud[i].regi);
		printf("math: %4.1f\t",stud[i].math);
		printf("scie: %4.1f\n",stud[i].scie);
	}
}

void Bubble_opt(struct student stud[])
{
	int i,j;
	for(i=1;i<STUDNO;i++)
	{
		for(j=0;j<STUDNO-i;j++)
		{
			if(stud[j].math>stud[j+1].math)
			{
				struct student temp;
				temp=stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=temp;
			}else if(stud[j].math==stud[j+1].math)
			{
				if(stud[j].scie>stud[j+1].scie)
				{
					struct student temp;
					temp=stud[j];
					stud[j]=stud[j+1];
					stud[j+1]=temp;
				}
			}
		}
	}
}

float AveMath(struct student stud[])
{
	int i;
	float sum=0;
	for(i=0;i<STUDNO;i++)
	{
		sum+=stud[i].math;
	}
	sum=sum/STUDNO;
	return sum;
}

float AveScie(struct student stud[])
{
	int i;
	float sum=0;
	for(i=0;i<STUDNO;i++)
	{
		sum+=stud[i].scie;
	}
	sum=sum/STUDNO;
	return sum;
}
