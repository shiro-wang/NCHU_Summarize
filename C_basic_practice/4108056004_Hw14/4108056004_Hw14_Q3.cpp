//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:���䥿 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
FILE *fptr;
FILE *fptr2;

int main()
{
	fptr=fopen("C:\\hw14\\input3.txt","r");
	if(fptr==NULL)
	{
		printf("�ɮ�input3�}�ҥ���!");
		exit(0);
	}
	fptr2=fopen("C:\\hw14\\output3.txt","w");
	if(fptr==NULL)
	{
		printf("�ɮ�output3�}�ҥ���!");
		exit(0);
	}
	
	unsigned long long int num;
	while(num!=0)
	{
		fscanf(fptr,"%llu",&num);
		if(num==0)
		{
			break;
		}else if(num%11==0){
			fprintf(fptr2,"%llu is a multiple of 11.\n",num);
		}else{
			fprintf(fptr2,"%llu is not a multiple of 11.\n",num);
		}
		
	}
		
	
	fclose(fptr);
	fclose(fptr2);
	printf("complete!\n");
	
	system("pause");
	return 0;
}
