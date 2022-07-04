//Class: Department of Computer Science and Engineering
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str[50];
	int i=0;
	int counter=0,word=0;
	printf("Please enter a string: ");
	gets(str);
	while(str[i]!=0)
	{
		printf("ASCII of %d character = %d\n",i+1,str[i]);
		if(str[i]==9||str[i]==32)
		{
			if(str[i-1]!=9&&str[i-1]!=32)
			{
				word++;
			}
		}
		i++;
	}
	printf("ASCII of %d character = %d\n",i+1,str[i]);
	i++;
	word++;
	
	printf("\nTotal number of characters = %d",i);
	printf("\nTotal number of words = %d\n",word);
	
	system("pause");
	return 0;
}
