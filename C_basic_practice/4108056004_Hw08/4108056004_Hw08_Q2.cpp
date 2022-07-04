//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add(int& );
int minus(int& );
int mult(int& );

int main()
{
	int num;
	char ch[100];
	printf("please enter a number : ");
	fflush(stdin);
	scanf("%d",&num);
	
	printf("---command list---\n");
	printf("exit => terminate this program\n");
	printf("add => add 1\n");
	printf("minus => minus 1\n");
	printf("double => double\n\n");
	
	
	do{
		printf("\nnow the number is : %d\n",num);
		printf("please enter the command : ");
		fflush(stdin);
		gets(ch);
		
		if(!strcmp(ch,"add"))
		{
			add(num);
		}else if(!strcmp(ch,"minus"))
		{
			minus(num);
		}else if(!strcmp(ch,"double"))
		{
			mult(num);
		}else if(strcmp(ch,"add")&&strcmp(ch,"minus")&&strcmp(ch,"double")&&strcmp(ch,"exit")){
			printf("\ncommand error!\n");
		}
	}while(strcmp(ch,"exit"));
	
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
