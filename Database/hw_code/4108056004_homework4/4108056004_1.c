#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

FILE *fptr;
FILE *fptr2;
//typedef struct Node *node;
typedef struct Node Node;
struct Node{				
	char self[MAX];		//�ۨ� 
	char f[MAX];		//�禡 
};
struct Node* heap[MAX];		//�Q�ΰ}�C�]�n 

int M,N;
int i, j, l, a;
int loop=0;

void show(struct Node* s, char gg[MAX]){
	char inf[MAX];
	memset(inf,0,sizeof(inf));
	if(!strcmp(s->f,"")){		//�w�g�S����ܩ��U���F�N��X 
		fprintf(fptr2,"%s ",s->self);
		//return;
	}else{
		int space=0;
		int k;
		l=0;
		//printf("s->f: %s",s->f);
		for(k=0;k<strlen(s->f);k++){
			//printf("k:%c ",s->f[k]);
			//printf("space:%d",space);
			if(space<2){				//��space��e���X�Ӧr����X�X�� �᭱�A�P�_ 
				fprintf(fptr2,"%c",s->f[k]);
			}
			
			if(s->f[k]!=' '){			//�r��s��inf 
				inf[l++]=s->f[k];
			}
			
			if(s->f[k]==' '){
				if(space>=2){
					//printf("inf:%s",inf);
					if(!strcmp(inf,gg)){
						//printf("loop!\n");
						loop=1;
						break;
					}
					for(a=0;a<M;a++){
						if(!strcmp(heap[a]->self,inf)){		//����ܤ��r�� �A�^�Ǩ�show�̰����j 
							show(heap[a],gg);
						}
					}
				}
				memset(inf,0,sizeof(inf));		//���s�n�ߺD 
				space++;
				l=0;
			}
		}
		fprintf(fptr2,") ");
	}
}

int main(){
	int numtest=4;			//�b������ɦW 
	char s[50];
	
	sprintf(s,"test%d.txt",numtest);
	fptr=fopen(s,"r");
	if(fptr==NULL)
	{
		printf("�ɮ�test%d�}�ҥ���!",numtest);
		exit(0);
	}
	sprintf(s,"output%dtest.txt",numtest);
	fptr2=fopen(s,"w");
	if(fptr2==NULL)
	{
		printf("�ɮ�output%d�}�ҥ���!",numtest);
		exit(0);
	}
	/////////////////
	fscanf(fptr,"%d",&M); fgetc(fptr);
	
	Node *temp = (Node*)malloc(sizeof(Node));
	
	char inm[MAX];
	char function[MAX];
	char inf[MAX];
	char ch;
	int k;
	int space;
	for(i=0;i<MAX;i++){
		heap[i]=(Node*)malloc(sizeof(Node));
	}
	
	for(i=0;i<M;i++){
		memset(heap[i]->f,0,sizeof(heap[i]->f));		//��l�� 
		memset(heap[i]->self,0,sizeof(heap[i]->self));
	}
	
	for(i=0;i<M;i++){
		memset(inm,0,sizeof(strlen(inm)));
		fscanf(fptr,"%s",&inm);
		//printf("%d: %s",i,inm);
		strcpy(heap[i]->self,inm);
		strcpy(heap[i]->f,"");			//���sinm�A�s��self�� 
	}	fgetc(fptr);
	
	fscanf(fptr,"%d",&N); getc(fptr);
	
	for(i=0;i<N;i++){
		memset(inm,0,sizeof(inm));
		fscanf(fptr,"%s",&inm);
		//printf("%s\n",inm);
		for(j=0;j<M;j++){
			if(!strcmp(inm,heap[j]->self)){					//��@�}�l�I
				//printf("j=%d\n",j); 
				fgetc(fptr);fgetc(fptr);fgetc(fptr);		//" = "
				l=0;
				memset(function,0,sizeof(function));
				while((ch=getc(fptr))!='\n'&&ch!=EOF){
					function[l++]=ch;				//����禡��J 
				}
				//printf("f:%s\n",function);
				strcpy(heap[j]->f,function);
				//printf("fun:%s\n",heap[j]->f);
			}
		}
	}
	/*if(!strcmp(heap[M-1]->f,"")){
		printf("!!!!!!!");
	}*/
	for(i=0;i<M;i++){		//��X 
		temp=heap[i];
		fprintf(fptr2,"%s -> ",temp->self);
		show(temp,temp->self);
		fprintf(fptr2,"\n");
	}
	
	if(loop==1){		//loop���p 
		fclose(fptr2);
		remove(s);			//�R���A�Ф@�� 
		fptr2=fopen(s,"w");
		if(fptr2==NULL)
		{
			printf("�ɮ�output%d�}�ҥ���!",numtest);
			exit(0);
		}
		fprintf(fptr2,"No solution.");
	}
	//system("pause");
	return 0;
} 
