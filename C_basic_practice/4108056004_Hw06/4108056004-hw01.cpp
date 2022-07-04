//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int raw,column;
	for(raw=1;raw<=9;++raw)
	{
		for(column=1;column<=9;++column)                          //沒差!!先看第一，符合第二就先執行了，執行完才在執行第三 
		{
			printf("%d X %d = %d",raw,column,raw*column);
			printf("\n");
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	system("PAUSE");
	return 0;
}
