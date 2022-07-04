//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int S[4]={};
int top=-1;
void push(int *);
void pop(int *);

int main()
{
	char ch[]={0};
	int i;
	while(strcmp(ch,"end"))
	{
		printf("stack =>");
		for(i=0;i<top+1;i++)
		{
			printf("%d ",S[i]);
		}
		printf("\nplease enter your command : ");
		fflush(stdin);
		scanf("%s",&ch);
		
		if(!strcmp(ch,"push"))
		{
			if(top+1==4)
			{
				printf("the stack is full\n\n");
			}else{
				push(S);
			}
		}else if(!strcmp(ch,"pop"))
		{
			if(top+1==0)
			{
				printf("the stack is empty!\n\n");
			}
			else{
				pop(S);
			}
		}else if(strcmp(ch,"end"))
		{
			printf("command errror!\n\n");
		}
	}
	printf("byebye~\n");
	system("pause");
	return 0;
}

void push(int *ptr)
{
	int flag,num;
	do{
	printf("please enter your number : ");
	fflush(stdin);
	flag=scanf("%d",&num);
	}while(!flag);
	*(ptr+top+1)=num;
	printf("\n");
	top++;
}
void pop(int *ptr)
{
	printf("the pop number is : %d\n\n",*ptr+top);
	top--;
}
