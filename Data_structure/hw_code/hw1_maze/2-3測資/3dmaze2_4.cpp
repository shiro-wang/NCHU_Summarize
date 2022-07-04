#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//#include<string.h>
//using namespace std;

FILE *fptr;

int main(){
	int numtest=1;
	//while(numtest<=100){
		char s[]={0};
		sprintf(s,"test%d.txt",numtest);

		fptr=fopen("test2.txt","r");
		
		if(fptr==NULL)
		{
			printf("檔案test%d開啟失敗!",numtest);
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
		int countP=1;     //****進入第一個P時不會算到****** 
		int totalP=0;    //P數量 
		
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
						if(ch=='P'){
							totalP++;
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
		int find=0,find_P=0;
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
		int path=2;
		int totalpath=0;
		
		while(top>-1){
			now_f=stack[top].f;
			now_r=stack[top].r;
			now_c=stack[top].c;
			now_d=stack[top].d;
			//printf("now: %d %d %d %d\n",now_f,now_r,now_c,now_d);      //確認路徑 
			if(now_f==end_f && now_r==end_r && now_c==end_c &&countP==totalP){
				maze2[num_floor][0][0]='*';
				totalpath++;
				if(path<min){
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
			
			find=0,find_P=0;
			int findPU=0,findPD=0,findP_nothing=0;
			if(maze[now_f][now_r][now_c]=='P'){
				find_P=1;
				if(now_r-1>=0&&maze2[now_f][now_r-1][now_c]=='P'){              //P的 
					if(now_d<5){
						now_r=now_r-1;
						now_d=5;
						find=1;
						countP++;
					}
				}else if(now_r+1<=(num_floor-now_f)*2&&maze2[now_f][now_r+1][now_c]=='P'){
					if(now_d<5){
						now_r=now_r+1;
						now_d=5;
						find=1;
						countP++;
					}
				}else if(now_c-1>=0&&maze2[now_f][now_r][now_c-1]=='P'){
					if(now_d<5){
						now_c=now_c-1;
						now_d=5;
						find=1;
						countP++;
					}
				}else if(now_c+1<=(num_floor-now_f)*2&&maze2[now_f][now_r][now_c+1]=='P'){
					if(now_d<5){
						now_c=now_c+1;
						now_d=5;
						find=1;
						countP++;
					}
				}else if(now_f-1>=0&&maze2[now_f-1][now_r+1][now_c+1]=='P'&&now_r+1<=(num_floor-now_f+1)*2&&now_c+1<=(num_floor-now_f+1)*2){
					if(now_d<5){
						now_f=now_f-1;
						now_r=now_r+1;
						now_c=now_c+1;
						now_d=5;
						find=1;
						countP++;
					}
				}else if(now_f+1<=num_floor&&maze2[now_f+1][now_r-1][now_c-1]=='P'&&now_r-1>=0&&now_c-1>=0){
					if(now_d<5){
						now_f=now_f+1;
						now_r=now_r-1;
						now_c=now_c-1;
						now_d=5;
						find=1;
						countP++;
					}
				}
			}
			//printf("countP=%d\n",countP);
			
			while(now_d<5&&find==0){          //dir1~5
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
				}else if(now_d==4&&(maze[stack[top].f][stack[top].r][stack[top].c]=='U'||(maze[stack[top].f][stack[top].r][stack[top].c]=='P'&&countP==totalP))){     //U
					now_f=stack[top].f+1;
					now_r=stack[top].r-1;
					now_c=stack[top].c-1;
					
					//printf("%d %d %d -- %d %d %d\n",stack[top].f,stack[top].r,stack[top].c,now_f,now_r,now_c);
					if(now_f<=num_floor&&now_r>=0&&now_c>=0){
						if(maze[now_f][now_r][now_c]!='X'&&maze2[now_f][now_r][now_c]!='*'){
							//printf("%d %d %d -- %d %d %d\n",stack[top].f,stack[top].r,stack[top].c,now_f,now_r,now_c);
							if(maze[stack[top].f][stack[top].r][stack[top].c]=='P'){
								findPU=1;
							}
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
							}n=temp_n;*/
						}else{
							stack[top].d=4;      //在未成功的情況下依舊把4值存入，才得以繼續跑回圈 
						}
						
					//_sleep(500);
					//system("cls");	
					}
					
					break;
				}else if(now_d==5&&(maze[stack[top].f][stack[top].r][stack[top].c]=='D'||(maze[stack[top].f][stack[top].r][stack[top].c]=='P'&&countP==totalP))){       //D
					now_f=stack[top].f-1;
					now_r=stack[top].r+1;
					now_c=stack[top].c+1;
		
					if(now_f>=0&&now_r<=(num_floor-now_f)*2&&now_c<=(num_floor-now_f)*2){
						if(maze[now_f][now_r][now_c]!='X'&&maze2[now_f][now_r][now_c]!='*'){
							if(maze[stack[top].f][stack[top].r][stack[top].c]=='P'){
								findPU=1;
							}
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
					}else{
						findP_nothing=1;
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
			}else if(find_P&&!findPU&&!findPD&&!findP_nothing){
				maze2[stack[top].f][stack[top].r][stack[top].c]='P';
				top--;
				countP--;
				if(maze[stack[top].f][stack[top].r][stack[top].c]!='P'){
					countP=1;
				}
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
			for(int i=0;i<floor;i++){         //地圖讀檔確認 
					for(int j=0;j<n;j++){
						for(int k=0;k<n;k++){
							printf("%c ",maze2[i][j][k]);
						}
						printf("\n");
						}
						printf("\n");
					n-=2;
				}
				n=temp_n;
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
			n=temp_n;*/
		printf("Path length: %d\n",min);
		}
		
		printf("totalpath: %d\n",totalpath);
		printf("test%d is done.\n",numtest);
		numtest++;
		
		/*for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%c ",maze[i][j]);
				}
				printf("\n");
			}*/
		fclose(fptr);
	//}
	system("pause");
	return 0;
	
}
