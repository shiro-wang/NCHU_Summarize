//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fptr;

void read();
void create();
void attach();

int main()
{
	char ch[10];
	printf("---command list---\n");
	printf("read\n");
	printf("create\n");
	printf("attach\n");
	printf("end\n");
	printf("------------------\n\n");
	
	
	do{
		printf("\nplease enter the command : ");
		fflush(stdin);
		gets(ch);
		
		if(!strcmp(ch,"read"))
		{
			read();
		}else if(!strcmp(ch,"create"))
		{
			create();
		}else if(!strcmp(ch,"attach"))
		{
			attach();
		}else if(strcmp(ch,"read")&&strcmp(ch,"create")&&strcmp(ch,"attach")&&strcmp(ch,"end")){
			printf("\ncommand error!\n");
		}
	}while(strcmp(ch,"end"));
	
	printf("\nbyebye~\n");
	
	system("pause");
	return 0;
}
void read()
{
	fptr=fopen("C:\\Users\\user\\hw13-Q2-4108056004.txt","r");
	if(fptr!=NULL)
	{
		char ch;
		while((ch=getc(fptr))!=EOF)
		{
			printf("%c",ch);
		}
	}else{
		printf("\nfile not exit\n");
	}
	fclose(fptr);
}
void attach()
{
	fptr=fopen("C:\\Users\\user\\hw13-Q2-4108056004.txt","r");
	if(fptr!=NULL)
	{
		fptr=fopen("C:\\Users\\user\\hw13-Q2-4108056004.txt","a");

		
			printf("\nplease write something : ");
			char str[50];
			fflush(stdin);
			gets(str);
			strcat(str,"\n");
			fputs(str,fptr);
			printf("attach the text into the file\n");
		
	
	}	else{
		printf("\nfile not exit\n");}
	fclose(fptr);
	}

void create()
{
	fptr=fopen("C:\\Users\\user\\hw13-Q2-4108056004.txt","w");
	if(fptr!=NULL)
	{
		fputs("\nhw13-Q2-4108056004.txt :\n",fptr);
		printf("\ncreate the file\n");
		
	}else{
		printf("\nfile not exit\n");
	}
	fclose(fptr);
}
