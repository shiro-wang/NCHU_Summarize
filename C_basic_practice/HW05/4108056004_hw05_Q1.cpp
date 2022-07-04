//Class: Department of Computer Science and Engineering 
//Registration Number:4108056004
//Name:¤ý«ä¥¿ 
//Contract e-mail:n0970424680@gmail.com
#include<stdio.h>
#include<stdlib.h>
struct data
{
	char name[50];
	int roll;
	float marks;
};

int main()
{
	struct data stu;
	printf("size of stu.name  = %d\n",sizeof(stu.name));
	printf("size of stu.rpll  = %d\n",sizeof(stu.roll));
	printf("size of stu.marks = %d\n",sizeof(stu.marks));
	printf("size of structure = %d\n\n",sizeof(stu));
	
	printf("Enter Basic Stucture information:\n");
	printf("Enter name: ");
	gets(stu.name);
	printf("Enter roll number (an integer): ");
	fflush(stdin);
	scanf("%d",&stu.roll);
	printf("Enter marks (a floating number): ");
	fflush(stdin);
	scanf("%f",&stu.marks);
	
	printf("\nDisplaying Structure Information:\n");
	printf("Name: %s\n",stu.name);
	printf("Roll number: %d\n",stu.roll);
	printf("Marks: %.1f\n",stu.marks);
	
	system("pause");
	return 0;
}
