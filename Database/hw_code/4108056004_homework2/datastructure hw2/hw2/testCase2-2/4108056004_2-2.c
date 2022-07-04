#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 20
#define OUT 10000
#define MAXCHAR 2000						//若檔案內容過大，這邊可以更改 
#define MAXANS 10000					//若最後length長度會超過，這裡更改 

typedef struct Platform *platform;
typedef struct Platform Platform;
struct Platform{
	char data;
	platform left;
	platform right;
};

FILE *fptr;

int main(){
	fptr=fopen("test.txt","r");                 //~檔名這邊改~ !!!!!!!!!!!!!!!!
	if(fptr==NULL){
		printf("open text.txt fail.\n");
		exit(0);
	}
	char s[MAXCHAR];
	int s_size=0;
	char ch;
	while((ch=getc(fptr))!=EOF){	//輸入並計算size 
		s[s_size]=ch;
		s_size++;
	}
	//printf("%s %d\n",s,s_size);
	
	
	int i,j;
	char input='1';
	char out[OUT]={0};
	int out_size=0;
	Platform *now = (Platform*)malloc(sizeof(Platform));
	now->data=' ';
	now->left=now;
	now->right=now;
	for(i=0;i<MAX-1;i++){
		Platform *new_plat = (Platform*)malloc(sizeof(Platform));
		new_plat->data=' ';
		new_plat->left=now;
		new_plat->right=now->right;
		now->right->left=new_plat;
		now->right=new_plat;
	}
	
	int size=0;
	char ans[MAXANS]={0};				//ans陣列 
	int ans_size=0;
		
	while(size<s_size){
		//printf("%c\n",s[size]);						//一個字一個字看 
		int ansprob[MAX]={0};						
		int ansprob_con[MAX]={0};
		int ansprob_platcon[MAX]={0};
		int ansprob_platmove[MAX]={0};
		int ansprob_alphabatmove[MAX]={0};
		if(s[size]==' '){
			s[size]='A'-1;
		}
		//////////
		for(i=0;i<MAX;i++){						//比較所有platform狀況 
			int d[4]={0};
			for(j=0;j<4;j++){
				d[j]=100;
			}
			int con=100;
			int min=100;
			
			if(now->data!=' '){					//取在此月台的移動length 
				d[0]=(int)s[size]-(int)now->data;
				//printf("%d\n",d[0]);
				d[0]=(int)fabs((double)d[0]);
				d[1]=27-d[0];
			}else{
				if(s[s_size]<'M'){
					d[2]=(int)s[size]-64;
				//	printf("%d\n",s[size]);
				}else{
					d[3]='Z'-s[size]+1;
				}	
			}
			//printf("%d %d %d %d",d[0],d[1],d[2],d[3]);    //check all condition
			for(j=0;j<4;j++){			//最小的移動方式 
				if(d[j]<min){
					min=d[j];
					con=j;
				}
			}
			
			ansprob_alphabatmove[i]=min;
			switch(con){
				case 0:					//以利後續輸出 
					ansprob_con[i]=0;
					break;
				case 1:
					ansprob_con[i]=1;
					break;
				case 2:
					ansprob_con[i]=2;
					break;
				case 3:
					ansprob_con[i]=3;
					break;
				default:
					break;
			}
			
			if(i<10){                     //原步數加上月台移動步數 
				ansprob[i]=min+i;
				ansprob_platcon[i]=0;
			}else if(i>=10){
				ansprob[i]=min+20-i;
				ansprob_platcon[i]=1;
			}
			//printf(" min:%d\n",ansprob[i]);   //check min
			now=now->right;
		}
		////////////////////////
		int totalmin=100;
		int minplat=100;
		for(i=0;i<MAX;i++){						//最後比較在所有月台上做的步數，找出最小 
			if(ansprob[i]<totalmin){
				totalmin=ansprob[i];
				minplat=i;
			}
		}
		//printf("%d %d\n",totalmin,minplat);
		switch(ansprob_platcon[minplat]){		//依最小情況去輸出指令 //記得實際上也要跑!!! 
			case 0:
				for(i=0;i<minplat;i++){
					ans[ans_size]='>';
					ans_size++;
					now=now->right;
				}
				break;
			case 1:
				for(i=0;i<20-minplat;i++){
					ans[ans_size]='<';
					ans_size++;
					now=now->left;
				}
				break;
			default:
					break;
		}
		switch(ansprob_con[minplat]){
			case 0:
				if(s[size]>now->data){
					for(i=0;i<ansprob_alphabatmove[minplat];i++){
						ans[ans_size]='+';
						ans_size++;
						Up(now);
					}
				}else{
					for(i=0;i<ansprob_alphabatmove[minplat];i++){
						ans[ans_size]='-';
						ans_size++;
						Down(now);
					}
				}
				break;
			case 1:
				if(s[size]>now->data){
					for(i=0;i<ansprob_alphabatmove[minplat];i++){
						ans[ans_size]='-';
						ans_size++;
						Down(now);
					}
				}else{
					for(i=0;i<ansprob_alphabatmove[minplat];i++){
						ans[ans_size]='+';
						ans_size++;
						Up(now);
					}
				}
				break;
			case 2:
				for(i=0;i<ansprob_alphabatmove[minplat];i++){
					ans[ans_size]='+';
					ans_size++;
					Up(now);
				}
				break;
			case 3:
				for(i=0;i<ansprob_alphabatmove[minplat];i++){
					ans[ans_size]='-';
					ans_size++;
					Down(now);
				}
				break;
			default:
				break;
		}
		
		ans[ans_size]='.';
		ans_size++;
		
		size++;
	}
	for(i=0;i<ans_size;i++){					//輸出length 
		printf("%c",ans[i]);
	}
	printf("\nlength:%d",ans_size);
	
	system("pause");
	return 0;
}
int Up(Platform *now){
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
