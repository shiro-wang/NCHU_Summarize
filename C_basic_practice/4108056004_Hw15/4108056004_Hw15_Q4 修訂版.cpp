//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char ch[10];
	char s[10];
	int s2[10]={0};
	
	int count=0;
	int i,j;
	printf("Enter a string that will only take the first 10 characters: \n");
	gets(ch);
	
	for(i=0;i<strlen(ch);i++)
	{
		for(j=0;j<count;j++)
		{
			if(ch[i]==s[j])
			{
				s2[j]+=1;
				break;
			}
			
		}
		if(j==count)
		{
			s[count]=ch[i];
			s2[count]+=1;
			count++;
		}
	}
		
	for(i=0;i<count;i++)
	{
		printf("%c : %d\n",s[i],s2[i]);
	}
	
	
	
	system("pause");
	return 0;
}
