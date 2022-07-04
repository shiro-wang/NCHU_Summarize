//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int add(int& );
int minus(int& );
int mult(int& );

int main()
{
	int num,cnum=1;
	printf("please enter a number : ");
	fflush(stdin);
	scanf("%d",&num);
	
	printf("---command list---\n");
	printf("0 => terminate this program\n");
	printf("1 => add 1\n");
	printf("2 => minus 1\n");
	printf("3 => double\n\n");
	
	
	do{
		printf("\nnow the number is : %d\n",num);
		printf("please enter the command number : ");
		fflush(stdin);
		scanf("%d",&cnum);
		
		if(cnum==1)
		{
			add(num);
		}else if(cnum==2)
		{
			minus(num);
		}else if(cnum==3)
		{
			mult(num);
		}else if(cnum!=0){
			printf("\ncommand error!\n");
		}
	}while(cnum!=0);
	
	printf("\nbyebye~\n");
	
	system("pause");
	return 0;
}
int add(int &num)
{
	num=num+1;
	return num;
}
int minus(int &num)
{
	num-=1;
	return num;
}
int mult(int &num)
{
	num*=2;
	return num;
}
