//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:王思正 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fptr;
FILE *fptr2;

int main()
{
	fptr=fopen("C:\\hw14\\input4.txt","r");
	if(fptr==NULL)
	{
		printf("檔案input4開啟失敗!");
		exit(0);
	}
	fptr2=fopen("C:\\hw14\\output4.txt","w");
	if(fptr==NULL)
	{
		printf("檔案output4開啟失敗!");
		exit(0);
	}
	
	char num[22];
	int a=0,b=0,c;
	int i=0;
	while(1)
	{
		fscanf(fptr,"%s",&num);
		//printf("%s\n",num);
		if(strcmp(num,"0")==0)
		{
			break;
		}
		
		a=0,b=0;
		
		for(i=0;i<strlen(num);i++)
		{
			//printf("%d %d\n",num[2*i]-'0',num[2*i+1]-'0');
			if(i%2==0)
			{
				a+=num[i]-'0';
			}else{
				b+=num[i]-'0';
			}
			
		}
		
		c=a-b;
		//printf("%d %d %d\n",a,b,c);
		if(c%11==0)
		{
			fprintf(fptr2,"%s is a multiple of 11.\n",num);
		}else{
			fprintf(fptr2,"%s is not a multiple of 11.\n",num);
		}
		
		
	}
		
	
	fclose(fptr);
	fclose(fptr2);
	printf("complete!\n");
	
	system("pause");
	return 0;
}
