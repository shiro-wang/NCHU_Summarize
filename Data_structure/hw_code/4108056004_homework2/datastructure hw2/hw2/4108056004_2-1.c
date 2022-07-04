#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define OUT 1000

typedef struct Platform *platform;
typedef struct Platform Platform;				//建立月台struct及指標 
struct Platform{
	char data;
	platform left;
	platform right;
};

int main(){
	int i;
	char input='1';
	char out[OUT]={0};				//輸出結果存放陣列 
	int out_size=0;
	Platform *now = (Platform*)malloc(sizeof(Platform));		//建立第一個月台 
	now->data=' ';
	now->left=now;
	now->right=now;
	for(i=0;i<MAX-1;i++){			//每次都從now月台的右邊新增共MAX-1個月台，並初始化data 
		Platform *new_plat = (Platform*)malloc(sizeof(Platform));
		new_plat->data=' ';
		new_plat->left=now;
		new_plat->right=now->right;
		now->right->left=new_plat;
		now->right=new_plat;
	}
	
	do{
		system("cls");
		switch(input){					//控制台 
			case '>': 
				now=now->right;
				break;
			case '<': 
				now=now->left;
				break;
			case '+': 
				Up(now);
				break;
			case '-': 
				Down(now);
				break;
			case '.': 
				if(now->data!=' '){
					out[out_size]=now->data;		//儲存 
					out_size++;
				}
				break;
			default:
				for(i=0;i<MAX;i++){							//利於觀察工具 
					printf("%d:%c  ",i+1,now->data);
					now=now->right;
				}
				printf("\noutput:%s\n",out);		//輸出印出結果 
				break;	
		}
		printf("input the command(0=end):");
		scanf("%c",&input);
	}while(input!='0');
	
	system("pause");
	return 0;
}
int Up(Platform *now){ 						//需特別注意A Z ' '狀況 
	if(now->data==' '){
		now->data='A';
	}else if(now->data=='Z'){
		now->data=' ';
	}else{
		now->data=++now->data;
	}
	return 1;
}
int Down(Platform *now){
	if(now->data==' '){
		now->data='Z';
	}else if(now->data=='A'){
		now->data=' ';
	}else{
		now->data=--now->data;
	}
	return 1;
}

