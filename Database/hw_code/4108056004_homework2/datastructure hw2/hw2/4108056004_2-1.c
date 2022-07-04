#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define OUT 1000

typedef struct Platform *platform;
typedef struct Platform Platform;				//�إߤ�xstruct�Ϋ��� 
struct Platform{
	char data;
	platform left;
	platform right;
};

int main(){
	int i;
	char input='1';
	char out[OUT]={0};				//��X���G�s��}�C 
	int out_size=0;
	Platform *now = (Platform*)malloc(sizeof(Platform));		//�إ߲Ĥ@�Ӥ�x 
	now->data=' ';
	now->left=now;
	now->right=now;
	for(i=0;i<MAX-1;i++){			//�C�����qnow��x���k��s�W�@MAX-1�Ӥ�x�A�ê�l��data 
		Platform *new_plat = (Platform*)malloc(sizeof(Platform));
		new_plat->data=' ';
		new_plat->left=now;
		new_plat->right=now->right;
		now->right->left=new_plat;
		now->right=new_plat;
	}
	
	do{
		system("cls");
		switch(input){					//����x 
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
					out[out_size]=now->data;		//�x�s 
					out_size++;
				}
				break;
			default:
				for(i=0;i<MAX;i++){							//�Q���[��u�� 
					printf("%d:%c  ",i+1,now->data);
					now=now->right;
				}
				printf("\noutput:%s\n",out);		//��X�L�X���G 
				break;	
		}
		printf("input the command(0=end):");
		scanf("%c",&input);
	}while(input!='0');
	
	system("pause");
	return 0;
}
int Up(Platform *now){ 						//�ݯS�O�`�NA Z ' '���p 
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

