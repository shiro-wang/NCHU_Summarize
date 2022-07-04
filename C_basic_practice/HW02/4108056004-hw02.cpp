//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("第二題\n\n");
	int score;
	char grade;
	printf("請輸入分數:");
	fflush(stdin);
	scanf("%d",&score);
	while(score<0||score>100)
	{
		printf("Please enter the score 0~100 again :");
		scanf("%d",&score);
	}
	if(score>=90)
	{
		grade='A';
		printf("level %c\n",grade);
	}else if(score>=80)
	{
		grade='B';
		printf("level %c\n",grade);
	}else if(score>=70)
	{
		grade='C';
		printf("level %c\n",grade);
	}else if(score>=60)
	{
		grade='D';
		printf("level %c\n",grade);
	}else{
		grade='E';
		printf("level %c\n",grade);
	}
	
	system("PAUSE");
	return 0;
	
}
