//資工系 
//4108056004
//王思正 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	//Hw01
	float q,w;
	float e;                                                               //以float設變數 
	printf("請輸入直角三角形兩邊邊長: ");
	scanf("%f %f",&q,&w);                                                                   //輸入兩數 
	while(q<=0||w<=0)                                                //防呆 
	{
		printf("請正確輸入兩正數!\n");
		scanf("%f %f",&q,&w);
	}
	e=sqrt(pow(q,2)+pow(w,2));                                                   //pow(a,b)為a的b次方!! 
	printf("斜邊邊長為:%f\n\n",e);
	
	 
	//Hw02
	char c;
	int r,t;
	printf("請輸入使用何種轉換(攝氏轉換華氏輸入C，華氏轉換攝氏輸入F):");
	scanf("%s",&c);
	if(c=='C')                                                                  //C轉F 
	{
		printf("請您輸入攝氏溫度:");
		scanf("%d",&r);
		t=r*9/5+32;
		printf("經轉換華氏溫度為:%d\n\n",t);	
	}
	if(c=='F')                                                            //F轉C 
	{
		printf("請您輸入華氏溫度:");
		scanf("%d",&r);
		t=(r-32)*5/9;
		printf("經轉換攝氏溫度為:%d\n\n",t);
	}
		
	
	//HW03
	int i;
	int j=1;
	int count=0;
	printf("Enter any normal number to check whether it's a prime number. \n");
	scanf("%d",&i);
	int k=sqrt(i);
	for(j=1;j<=k;j++)                                          //for迴圈搭配多加一個變數技巧!! 
	{
	   if(i%j==0)
	   {
	       count++;
	   }
	   if(count>=2)
	   {
	   	    break;
	   }
    }
    if(count>=2)
    {
    	printf("%d isn't a prime number.\n\n",i);
	}else if(i=1){                                              //1不是質數 
	    printf("%d isn't a prime number.\n\n",i);
	}else{
		printf("%d is a prime number.\n\n",i);
	}
	
	
	//HW04
	int a=0,b=0,d=0;
	printf("請輸入三個數字: ");
	scanf("%d %d %d",&a,&b,&d);
	if(a>b)
	{
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	if(b>d)
	{
		int temp;
		temp=b;
		b=d;
		d=temp;
	}
	printf("將數字由小到大排列: %d  %d  %d\n",a,b,d);
	
    
    
	system("PAUSE");
	return 0;
}
