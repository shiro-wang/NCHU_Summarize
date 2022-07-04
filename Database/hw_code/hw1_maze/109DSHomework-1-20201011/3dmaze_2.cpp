#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//#include<string.h>
//using namespace std;

FILE *fptr;
FILE *fptr2; 

int main(){
	int numtest=1;
	//while(numtest<=100){
		char s[]={0};
		char s2[]={0};
		sprintf(s,"test%d.txt",numtest);

		fptr=fopen(s,"r");
		
		if(fptr==NULL)
		{
			printf("檔案test%d開啟失敗!",numtest);
			//break;
		}
		sprintf(s2,"test%d_ans2.txt",numtest);
		
		fptr2=fopen(s2,"w");
		if(fptr==NULL)
		{
			printf("檔案output2開啟失敗!");
			//break;
		}
		
		int n=0;
		char ch;
		while((ch=getc(fptr))!='\n'){
			if(ch!=' '){
				n++;
			}
		}
		int floor=n/2+1;
		int temp_n=n;
		rewind(fptr);  //檔案存取位置重新設為開頭 
		
		char maze[floor][n][n]={0};
		char maze2[floor][n][n]={0};   //路徑圖 
		char end[floor][n][n]={0};     //最短結果 
	
		int space=0;
		int start_r,start_c,start_f,end_f,end_r,end_c;
		int end_or_not=0; //是否有終點 
		
		for(int i=0;i<floor;i++){                   //開始讀檔 
			for(int j=space;j<n;j++){
				int k=0;
				
				while((ch=getc(fptr))!='\n'){       //輸入 
					if(ch!=32){                    //去掉空格 	
						maze[i][j][k]=ch;
						maze2[i][j][k]=ch;
						if(ch=='S'){
							start_f=i;
							start_r=j;
							start_c=k;
						}
						//printf("%d %d %d: %c\n",i,j,k,ch);
						k++;
					}
				}	
			}
			space=-1;
			n-=2;
		}
		n=temp_n;
		/*for(int i=0;i<floor;i++){   //i=-1 去掉前述       //地圖讀檔確認 
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					printf("%c ",maze[i][j][k]);
				}
				printf("\n");
			}
			n-=2;
		}
		n=temp_n;*/
		
		typedef struct{
			short int f;
			short int r;
			short int c;
			short int d;	
		} element;
		element stack[n*n*floor];
		
		int top=0;
		int min=n*n*floor;
		int find=0,find_2=0;
		int now_f,now_r,now_c,now_d;
		
		int num_floor=floor-1;        //if floor=3,num_floor=2
		end_f=num_floor-1;end_r=1;end_c=1; //直接定義終點 
		
		//printf("S:%d %d %d\n",start_f,start_r,start_c);
		//printf("F:%d %d %d\n",end_f,end_r,end_c);      //ok 
		
		//maze[start_f][start_r][start_c]='*';
		maze2[start_f][start_r][start_c]='*';
		
		stack[top].f=start_f;
		stack[top].r=start_r;
		stack[top].c=start_c;
		stack[top].d=-1;
		int path=1;
		
		while(top>-1){
			
			now_f=stack[top].f;
			now_r=stack[top].r;
			now_c=stack[top].c;
			now_d=stack[top].d;
			//printf("now: %d %d %d \n",now_f,now_r,now_c);      //確認路徑 
			if(now_f==end_f && now_r==end_r && now_c==end_c){
				maze2[num_floor][0][0]='*';
				if(path+1<min){
					min=path;
					for(int i=0;i<floor;i++){           //find min 存下 
						for(int j=0;j<n;j++){
							for(int k=0;k<n;k++){
								end[i][j][k]=maze2[i][j][k];
							}
						}	
						n-=2;
					}                       
				}
				n=temp_n;
				maze2[stack[top].f][stack[top].r][stack[top].c]='U';
	
				top--;
				path--;
				now_f=stack[top].f;
				now_r=stack[top].r;
				now_c=stack[top].c;
				now_d=stack[top].d;
				
				end_or_not=1;
			}
	
			find=0,find_2=0;
			while(now_d<5&&find==0){           //dir1~5
				now_d++;
				if(now_d==0){
					now_r=stack[top].r-1;
					now_c=stack[top].c;
				}else if(now_d==1){
					now_r=stack[top].r;
					now_c=stack[top].c+1;
				}else if(now_d==2){
					now_r=stack[top].r+1;
					now_c=stack[top].c;
				}else if(now_d==3){
					now_r=stack[top].r;
					now_c=stack[top].c-1;
				}else if(now_d==4&&maze[stack[top].f][stack[top].r][stack[top].c]=='U'){     //U
					now_f=stack[top].f+1;
					now_r=stack[top].r-1;
					now_c=stack[top].c-1;
					
					if(now_f<=num_floor){
						if(maze[now_f][now_r][now_c]!='X'&&maze2[now_f][now_r][now_c]!='*'){
							
							stack[top].d=now_d;
							top++;
							stack[top].f=now_f;
							stack[top].r=now_r;
							stack[top].c=now_c;
							stack[top].d=-1;
							maze2[now_f][now_r][now_c]='*';
							if(maze[now_f][now_r][now_c]=='T'){
								path+=3;
							}else{
								path++;
							}
						
							/*for(int i=0;i<floor;i++){                  //地圖讀檔確認 
								for(int j=0;j<n;j++){
									for(int k=0;k<n;k++){
										printf("%c ",maze2[i][j][k]);
									}
									printf("\n");
								}
								printf("\n");
								n-=2;
							}*/
						}else{
							stack[top].d=4;      //在未成功的情況下依舊把4值存入，才得以繼續跑回圈 
						}
						n=temp_n;
					//_sleep(500);
					//system("cls");	
					}
					
					break;
				}else if(now_d==5&&maze[stack[top].f][stack[top].r][stack[top].c]=='D'){       //D
					now_f=stack[top].f-1;
					now_r=stack[top].r+1;
					now_c=stack[top].c+1;
					
					if(now_f>=0){
						if(maze[now_f][now_r][now_c]!='X'&&maze2[now_f][now_r][now_c]!='*'){
							stack[top].d=now_d;
							top++;
							stack[top].f=now_f;
							stack[top].r=now_r;
							stack[top].c=now_c;
							stack[top].d=-1;
							maze2[now_f][now_r][now_c]='*';
					
							if(maze[now_f][now_r][now_c]=='T'){
								path+=3;
							}else{
								path++;
							}
						
						
						/*for(int i=0;i<floor;i++){                //地圖讀檔確認 
							for(int j=0;j<n;j++){
								for(int k=0;k<n;k++){
									printf("%c ",maze2[i][j][k]);
									printf("\n");
								}
							printf("\n");
							n-=2;
						//_sleep(500);
						//system("cls");
							
						}
						n=temp_n;*/
						
							
						}
					break;
					}
				}
				
				if(now_d<4&&now_r>=0&&now_r<=(num_floor-now_f)*2&&now_c>=0&&now_c<=(num_floor-now_f)*2){
					if(maze[now_f][now_r][now_c]!='X'&&maze2[now_f][now_r][now_c]!='*'&&maze2[now_f][now_r][now_c]!='T'){
					find=1;
					path++;
					}else if(maze[now_f][now_r][now_c]=='T'&&maze2[now_f][now_r][now_c]=='T'){
					find=1;
					path+=3;
					}
				}	
			}
			if(find==1){                                  //上右下左 
				stack[top].d=now_d;
				top++;
				stack[top].f=now_f;
				stack[top].r=now_r;
				stack[top].c=now_c;
				stack[top].d=-1;
				maze2[now_f][now_r][now_c]='*';
				
				/*for(int i=0;i<floor;i++){   //i=-1 去掉前述       //地圖讀檔確認 
					for(int j=0;j<n;j++){
						for(int k=0;k<n;k++){
							printf("%c ",maze2[i][j][k]);
						}
						printf("\n");
						}
						printf("\n");
					n-=2;
				}
				n=temp_n;*/
				//_sleep(500);
				//system("cls");
			}
			if(now_d==5){                                                         //倒退機制 
				if(maze[stack[top].f][stack[top].r][stack[top].c]=='O'){
					maze2[stack[top].f][stack[top].r][stack[top].c]='O';
					top--;
					path--;
				}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='U'){
					maze2[stack[top].f][stack[top].r][stack[top].c]='U';
					top--;
					path--;
				}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='D'){
					maze2[stack[top].f][stack[top].r][stack[top].c]='D';
					top--;
					path--;
				}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='T'){
					maze2[stack[top].f][stack[top].r][stack[top].c]='T';
					top--;
					path-=3;
				}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='S'){     
					top--;
				}
				
			}
		}
		
		if(!end_or_not){
			printf("There's no way from S to F!\n");
		}else{
			/*for(int i=0;i<floor;i++){                   //最終印出 
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					printf("%c ",end[i][j][k]);
				}
				printf("\n");
				}
				printf("\n");
			n-=2;
			}
			n=temp_n;
			printf("Path length: %d",min);*/
			
			fprintf(fptr2,"Path length : %d\n=====outmaze=====\n",min);
			for(int i=0;i<floor;i++){                   //最終印出 
				for(int j=0;j<n;j++){
					for(int k=0;k<n;k++){
						fprintf(fptr2,"%c ",end[i][j][k]);
					}
					fprintf(fptr2,"\n");
				}
				fprintf(fptr2,"\n");
				n-=2;
			}
			n=temp_n;
			
		}
		
		
		
		printf("test%d is done.\n",numtest);
		numtest++;
		
		/*for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%c ",maze[i][j]);
				}
				printf("\n");
			}*/
		fclose(fptr);
		fclose(fptr2);
	//}
	system("pause");
	return 0;
	
}
