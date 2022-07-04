//Class: Department of Computer Science and Engineering 
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
struct student
{
 float math;
 float scie;
};

float AvePoint(struct student);

int main()
{
	struct student stu;
	printf("Enter student math (a floating point):");
	fflush(stdin);
	scanf("%f",&stu.math);
	printf("Enter student science(a floating point):");
	fflush(stdin);
	scanf("%f",&stu.scie);
	
	printf("\nIn main program, we pass tructure to the function...\n");
	printf("Within function, we calculate the average value...\n");
	printf("In main program, we display information...\n");
	printf("student math:  %.2f\n",stu.math);
	printf("student scie:  %.2f\n",stu.scie);
	printf("student average:  %.2f\n",AvePoint(stu));
	
	system("pause");
	return 0;
}

float AvePoint(struct student stu)
{
	float ave;
	ave=(stu.math+stu.scie)/2;
	return ave;
}
