//��u�t 
//4108056004
//���䥿 
//n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	//Hw01
	float q,w;
	float e;                                                               //�Hfloat�]�ܼ� 
	printf("�п�J�����T���Ψ������: ");
	scanf("%f %f",&q,&w);                                                                   //��J��� 
	while(q<=0||w<=0)                                                //���b 
	{
		printf("�Х��T��J�⥿��!\n");
		scanf("%f %f",&q,&w);
	}
	e=sqrt(pow(q,2)+pow(w,2));                                                   //pow(a,b)��a��b����!! 
	printf("���������:%f\n\n",e);
	
	 
	//Hw02
	char c;
	int r,t;
	printf("�п�J�ϥΦ���ഫ(����ഫ�ؤ��JC�A�ؤ��ഫ����JF):");
	scanf("%s",&c);
	if(c=='C')                                                                  //C��F 
	{
		printf("�бz��J���ū�:");
		scanf("%d",&r);
		t=r*9/5+32;
		printf("�g�ഫ�ؤ�ū׬�:%d\n\n",t);	
	}
	if(c=='F')                                                            //F��C 
	{
		printf("�бz��J�ؤ�ū�:");
		scanf("%d",&r);
		t=(r-32)*5/9;
		printf("�g�ഫ���ū׬�:%d\n\n",t);
	}
		
	
	//HW03
	int i;
	int j=1;
	int count=0;
	printf("Enter any normal number to check whether it's a prime number. \n");
	scanf("%d",&i);
	int k=sqrt(i);
	for(j=1;j<=k;j++)                                          //for�j��f�t�h�[�@���ܼƧޥ�!! 
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
	}else if(i=1){                                              //1���O��� 
	    printf("%d isn't a prime number.\n\n",i);
	}else{
		printf("%d is a prime number.\n\n",i);
	}
	
	
	//HW04
	int a=0,b=0,d=0;
	printf("�п�J�T�ӼƦr: ");
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
	printf("�N�Ʀr�Ѥp��j�ƦC: %d  %d  %d\n",a,b,d);
	
    
    
	system("PAUSE");
	return 0;
}
