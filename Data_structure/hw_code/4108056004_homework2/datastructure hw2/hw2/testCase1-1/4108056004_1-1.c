#include<stdio.h>
#include<stdlib.h>

typedef struct Treenode *treenode;
typedef struct Treenode Treenode;
struct Treenode{					//�ؾ�`�I 
	int data;
	treenode left;
	treenode right;
};

typedef struct queue *queue_pointer;		//��Q�`�I 
typedef struct queue queue;
struct queue{
	Treenode *treenode;
	queue_pointer link;
};



int q01=0;
void dequeue(queue *head,queue *tail,char ch,int lorr){
	//queue *tempq = tail;
	if(lorr==0){
		//printf("in function %d %c\n",lorr,ch);
		tail->treenode->left->data=ch;
		if(ch=='0'){								//�Y������0�A��tail->left�@�ӧ���`�I�A�ñN��ǤJQ���U�@��link 
			Treenode *newnodel = (Treenode*)malloc(sizeof(Treenode));
			Treenode *newnoder = (Treenode*)malloc(sizeof(Treenode));
			tail->treenode->left->left=newnodel;
			tail->treenode->left->right=newnoder;
			newnodel->data=' ';
			newnoder->data=' ';
			queue *newq = (queue*)malloc(sizeof(queue));
			newq->treenode=tail->treenode->left;
			
			head->link=newq;
			printf("%c\n",head->link->treenode->data);
			q01++;
		}
		
	}else if(lorr==1){
	//	printf("in function %d %c\n",lorr,ch);
		tail->treenode->right->data=ch;
		if(ch=='0'){					//�Y������0�A��tail->right�@�ӧ���`�I�A�ñN��ǤJQ���U�@��link
			Treenode *newnodel = (Treenode*)malloc(sizeof(Treenode));
			printf("ok2\n"); 
			Treenode *newnoder = (Treenode*)malloc(sizeof(Treenode));printf("ok2\n"); 
			tail->treenode->right->left=newnodel;printf("ok2\n"); 
			tail->treenode->right->right=newnoder;printf("ok2\n"); 
			newnodel->data=' ';printf("ok2\n"); 
			newnoder->data=' ';printf("ok2\n"); 
			queue *newq = (queue*)malloc(sizeof(queue));printf("ok2\n"); 
			newq->link=NULL;printf("ok2\n"); 
			newq->treenode=tail->treenode->right;printf("ok2\n"); 
			if(q01==1){						//������̱��󲾰�head ��tail�����V 
				head->link->link=newq;
				*tail=*(tail->link);
				*head=*newq;
				q01--;
			}else{
				head->link=newq;
				*tail=*(tail->link);
				*head=*newq;
			}
		}else{
			if(q01==1){
				*tail=*(tail->link);printf("ok2\n"); 
				printf("%c\n",head->link->treenode->data);
				*head=*(head->link);printf("ok2\n"); //stuck     	//���B�d��A�٨S�ˬd��..............TT 
				q01--;printf("ok2\n"); 
			}else{
				*tail=*(tail->link);
			}
		}
		
		
	}
	//return 1;
}

FILE *fptr;

int main(){
	fptr=fopen("test2.txt","r");
	if(fptr==NULL){
		printf("Open text1.txt fail.\n");
		exit(0);
	}
	int exist=0;
	
	queue *head = (queue*)malloc(sizeof(queue));
	queue *tail = head;
	
	Treenode *newnodef = (Treenode*)malloc(sizeof(Treenode));		//�`�����إ߰_�l�I(root 
	head->treenode=newnodef;
	head->treenode->data=' ';
	head->treenode->left=NULL;
	head->treenode->right=NULL;
	
	Treenode *root;
	char ch=' ';
	getc(fptr);ch=getc(fptr);			//�ݲĤ@�� 
	if(ch=='0'){
		Treenode *newnodel = (Treenode*)malloc(sizeof(Treenode));		//���𦳮ڡA�C�C�\ 
		Treenode *newnoder = (Treenode*)malloc(sizeof(Treenode));
		head->treenode->data='0';
		head->treenode->left=newnodel;
		head->treenode->right=newnoder;
		root=head->treenode;
		
		exist=1;
	}else{
		exist=0;						//����L�ڡA���h~ 
	}
	int lorr=0;
	if(exist){
		while((ch=getc(fptr))!=EOF){
			if(ch=='0'||ch=='n'){
				printf("lorr %d %c \n",lorr,ch);
				dequeue(head,tail,ch,lorr);
				if(lorr==0){
					lorr++;
				}else if(lorr==1){
					lorr--;
				}
			}
		}
	}else{
		printf("this tree doesn't exist\n");
		exit(0);
	}
	printf("%c\n",root->right->left->data);                //�T�{�w�غc�� ����!!!!!!!!! ????????? 
	
	system("Pause");
	return 0;
}


