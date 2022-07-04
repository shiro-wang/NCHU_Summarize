#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

FILE *fptr;
FILE *fptr2;
//typedef struct Node *node;
typedef struct Node Node;
struct Node{				
	char self[MAX];		//自身 
	char f[MAX];		//函式 
};
struct Node* heap[MAX];		//利用陣列設好 

int M,N;
int i, j, l, a;
int loop=0;

void show(struct Node* s, char gg[MAX]){
	char inf[MAX];
	memset(inf,0,sizeof(inf));
	if(!strcmp(s->f,"")){		//已經沒有函示往下接了就輸出 
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
			if(space<2){				//用space把前面幾個字先輸出出來 後面再判斷 
				fprintf(fptr2,"%c",s->f[k]);
			}
			
			if(s->f[k]!=' '){			//字串存到inf 
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
						if(!strcmp(heap[a]->self,inf)){		//找到函示內字串 再回傳到show裡做遞迴 
							show(heap[a],gg);
						}
					}
				}
				memset(inf,0,sizeof(inf));		//重製好習慣 
				space++;
				l=0;
			}
		}
		fprintf(fptr2,") ");
	}
}

int main(){
	int numtest=4;			//在此更改檔名 
	char s[50];
	
	sprintf(s,"test%d.txt",numtest);
	fptr=fopen(s,"r");
	if(fptr==NULL)
	{
		printf("檔案test%d開啟失敗!",numtest);
		exit(0);
	}
	sprintf(s,"output%dtest.txt",numtest);
	fptr2=fopen(s,"w");
	if(fptr2==NULL)
	{
		printf("檔案output%d開啟失敗!",numtest);
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
		memset(heap[i]->f,0,sizeof(heap[i]->f));		//初始化 
		memset(heap[i]->self,0,sizeof(heap[i]->self));
	}
	
	for(i=0;i<M;i++){
		memset(inm,0,sizeof(strlen(inm)));
		fscanf(fptr,"%s",&inm);
		//printf("%d: %s",i,inm);
		strcpy(heap[i]->self,inm);
		strcpy(heap[i]->f,"");			//先存inm再存到self裡 
	}	fgetc(fptr);
	
	fscanf(fptr,"%d",&N); getc(fptr);
	
	for(i=0;i<N;i++){
		memset(inm,0,sizeof(inm));
		fscanf(fptr,"%s",&inm);
		//printf("%s\n",inm);
		for(j=0;j<M;j++){
			if(!strcmp(inm,heap[j]->self)){					//找一開始點
				//printf("j=%d\n",j); 
				fgetc(fptr);fgetc(fptr);fgetc(fptr);		//" = "
				l=0;
				memset(function,0,sizeof(function));
				while((ch=getc(fptr))!='\n'&&ch!=EOF){
					function[l++]=ch;				//後續函式輸入 
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
	for(i=0;i<M;i++){		//輸出 
		temp=heap[i];
		fprintf(fptr2,"%s -> ",temp->self);
		show(temp,temp->self);
		fprintf(fptr2,"\n");
	}
	
	if(loop==1){		//loop情況 
		fclose(fptr2);
		remove(s);			//刪掉再創一個 
		fptr2=fopen(s,"w");
		if(fptr2==NULL)
		{
			printf("檔案output%d開啟失敗!",numtest);
			exit(0);
		}
		fprintf(fptr2,"No solution.");
	}
	//system("pause");
	return 0;
} 
