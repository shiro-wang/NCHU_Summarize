//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr;
	char ch,str[20];
	fptr=fopen("HW06.txt","w");
	if(fptr==NULL)
	{
		printf("檔案開啟失敗!");
		exit(1);
	}
	printf("Please enter a string: ");
	scanf("%s",&str);
	fputs(str,fptr);
	
	short int i=1;
	short int count=0,word=0;
	while(ch=getc(fptr)!=EOF)
	{
		printf("ASCII of %hd character = %d\n",i,ch);
		i++;
		count++;
		if(ch==9||ch==32)
		{
			word++;
		}
	}
	
	
	printf("\nTotal number of characters = %hd\n",count);
	printf("Total number of words = %hd",word);
	fclose(fptr);
	
	system("pause");
	return 0;
}
