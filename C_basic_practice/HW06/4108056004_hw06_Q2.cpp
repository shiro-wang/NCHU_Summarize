//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char name[10];
	printf("Enter source file path: ");
	gets(name);
	FILE *fptr;
	fptr=fopen(name,"r");
	if(fptr==NULL)
	{
		printf("檔案開啟失敗!");
		exit(1);
	}else{
		int i=1;
		int l=1;
		int word=0;
		char ch;
		while((ch=getc(fptr))!=EOF)
		{
			if(ch==' '||ch=='\n')
			{
				word++;
			}
			if(ch!='\n')
			{
				printf("ASCII of %d character = %d\n",i,ch);
				i++;
			}else{
				printf("ASCII of %d character = %d\n",i,ch);
				printf("Line %d complete!\n\n",l);
				i++;
				l++;
			}
		}
		printf("Line %d complete!\n\n",l);
		
		printf("Total characters = %d\n",i-1);
		printf("Total words      = %d\n",word+1);
		printf("Total lines      = %d\n",l);
	}
	system("pause");
	return 0;
}
