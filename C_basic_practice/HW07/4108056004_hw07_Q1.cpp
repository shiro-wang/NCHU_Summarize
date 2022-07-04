//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define UPPER 4096
#define LOWER -2048

int main()
{
	int *arr;
	arr=(int *) malloc(MAX_SIZE*sizeof(int));
	if(arr==NULL)
	{
		printf("Error:unable to allocate required memory.\n");
		exit(0);
	}else{
		int s=1;
		while(s<100||s>1000)
		{
			printf("Please input an integer seed between 100 and 1000:");
			fflush(stdin);
			scanf("%d",&s);
		}
		printf("Your input seed for randomness is %d\n",s);
		srand(s);
		int i;
		for(i=0;i<MAX_SIZE;i++)
		{
			*(arr+i)=rand()%(UPPER-LOWER+1)+LOWER;
		}
		int max1=*(arr+0),max2=*(arr+0),min1=*(arr+0),min2=*(arr+0);
		int tm1=0,tm2=0,ti1=0,ti2=0;
		
		for(i=1;i<MAX_SIZE;i++)
		{
			if(*(arr+i)>max1)
			{
				max1=*(arr+i);
			}
			if(*(arr+i)<min1)
			{
				min1=*(arr+i);
			}
		}
		for(i=1;i<MAX_SIZE;i++)
		{
			if(*(arr+i)>max2&&*(arr+i)!=max1)
			{
				max2=*(arr+i);
			}
			if(*(arr+i)<min2&&*(arr+i)!=min1)
			{
				min2=*(arr+i);
			}
		}
		for(i=1;i<MAX_SIZE;i++)
		{
			if(*(arr+i)==max1)
			{
				tm1++;
			}
			if(*(arr+i)==max2)
			{
				tm2++;
			}
			if(*(arr+i)==min1)
			{
				ti1++;
			}
			if(*(arr+i)==min2)
			{
				ti2++;
			}
		}
		
		printf("First largest in array = %d\n",max1);
		printf("First largest total number = %d\n",tm1);
		printf("Second largest in array = %d\n",max2);
		printf("Second largest total number = %d\n",tm2);
		printf("First smallest in array = %d\n",min1);
		printf("First smallest total number = %d\n",ti1);
		printf("Second smallest in array = %d\n",min2);
		printf("Second smallest total number = %d\n",ti2);
		
		free(arr);
		
	}
	
	system("pause");
	return 0;
}
