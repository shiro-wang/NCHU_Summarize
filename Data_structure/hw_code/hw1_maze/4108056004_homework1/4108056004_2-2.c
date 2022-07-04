#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//using namespace std;

FILE *fptr;
FILE *fptr2;

int main(){
	int numtest=1;
	int i,j,k;
	fptr2=fopen("output.txt","w");
	if(fptr==NULL)
	{
		printf("檔案output.txt開啟失敗!",numtest);
		//break;
	}
	while(numtest<=100){
		char s[]={0};
		sprintf(s,"test%d.txt",numtest);

		fptr=fopen(s,"r");
		
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
	
	char maze[floor][n][n];     //原圖 
	char maze2[floor][n][n];	//最短路徑圖
	char maze3[floor][n][n];    //所有 
	int nmaze[floor][n][n];    //數字圖 
	char end[floor][n][n];     //最短結果 
		for(i=0;i<floor;i++){        //地圖讀檔確認 
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				nmaze[i][j][k]=99;
			}
			
		}
		
		n-=2;
	}
	n=temp_n;
	int space=0;    //讀檔小工具 
	int start_r,start_c,start_f,end_f,end_r,end_c;
	int end_or_not=0; //是否有終點 
	
	for(i=0;i<floor;i++){                   //開始讀檔 
		for(j=space;j<n;j++){
			k=0;
			
			while((ch=getc(fptr))!='\n'){       //輸入 //因特定格式(地圖)所設計，若測資與題目所給予測資不同格式將會掛掉 
				if(ch!=32){                    //去掉空格 	
					maze[i][j][k]=ch;
					maze2[i][j][k]=ch;
					maze3[i][j][k]=ch;
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

	int find=1,find_2=0;
	int now_f,now_r,now_c,now_d;
	
	int num_floor=floor-1;        //if floor=3,num_floor=2
	end_f=num_floor-1;end_r=1;end_c=1; //直接定義終點 
	
	//printf("S:%d %d %d\n",start_f,start_r,start_c);
	//printf("F:%d %d %d\n",end_f,end_r,end_c);      //ok 
	
	nmaze[start_f][start_r][start_c]=1;
	
	stack[top].f=start_f;
	stack[top].r=start_r;
	stack[top].c=start_c;
	stack[top].d=-1;
	int path=1;
	int count=1;
	
	int nowmaxcount=0;   //cause of T
	while(find==1){                   //廣度搜尋 
		find=0;
		for(i=0;i<floor;i++){   
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if(nmaze[i][j][k]==count){
						if(i==end_f&&j==end_r&&k==end_c){
							find_2=1;
							break;
						}
						if(j-1>=0&&j-1<=(num_floor-i)*2&&(nmaze[i][j][k]<nmaze[i][j-1][k])&&maze[i][j-1][k]!='X'){
							if(maze[i][j-1][k]=='T'){
								if(nmaze[i][j-1][k]>count+3){
									nmaze[i][j-1][k]=count+3;
									nowmaxcount=count+3;
								}	
							}else{
								nmaze[i][j-1][k]=count+1;
							}
							find=1;
						}
						if(j+1>=0&&j+1<=(num_floor-i)*2&&(nmaze[i][j][k]<nmaze[i][j+1][k])&&maze[i][j+1][k]!='X'){
							if(maze[i][j+1][k]=='T'){
								if(nmaze[i][j+1][k]>count+3){
									nmaze[i][j+1][k]=count+3;
									nowmaxcount=count+3;
								}
							}else{
								nmaze[i][j+1][k]=count+1;
							}
							find=1;	
						}
						if(k-1>=0&&k-1<=(num_floor-i)*2&&(nmaze[i][j][k]<nmaze[i][j][k-1])&&maze[i][j][k-1]!='X'){
							if(maze[i][j][k-1]=='T'){
								if(nmaze[i][j][k-1]>count+3){
									nmaze[i][j][k-1]=count+3;
									nowmaxcount=count+3;
								}
							}else{
								nmaze[i][j][k-1]=count+1;
							}
							find=1;
						}
						if(k+1>=0&&k+1<=(num_floor-i)*2&&(nmaze[i][j][k]<nmaze[i][j][k+1])&&maze[i][j][k+1]!='X'){
							if(maze[i][j][k+1]=='T'){
								if(nmaze[i][j][k+1]>count+3){
									nmaze[i][j][k+1]=count+3;
									nowmaxcount=count+3;
								}
							}else{
								nmaze[i][j][k+1]=count+1;
							}
							find=1;
						}
						if(maze[i][j][k]=='U'){
							if(i+1<=num_floor&&j-1>=0&&j-1<=(num_floor-i-1)*2&&k-1>=0&&k-1<=(num_floor-i-1)*2&&maze[i+1][j-1][k-1]!='X'&&(nmaze[i][j][k]<nmaze[i+1][j-1][k-1])){
								if(maze[i+1][j-1][k-1]=='T'){
									nmaze[i+1][j-1][k-1]=count+3;
									nowmaxcount=count+3;
								}else{
									nmaze[i+1][j-1][k-1]=count+1;
								}
								
							}
							find=1;
						}
						if(maze[i][j][k]=='D'){
							if(i-1>=0&&j+1>=0&&j+1<=(num_floor-i+1)*2&&k+1>=0&&k+1<=(num_floor-i+1)*2&&maze[i-1][j+1][k+1]!='X'&&(nmaze[i][j][k]<nmaze[i-1][j+1][k+1])){
								if(maze[i-1][j+1][k+1]=='T'){
									nmaze[i-1][j+1][k+1]=count+3;
									nowmaxcount=count+3;
								}else{
									nmaze[i-1][j+1][k+1]=count+1;
								}
								
							}
							find=1;
						}
					}
				}
			}
			n-=2;
		}
		n=temp_n;
		//printf("now count:%d\n nowmaxcount:%d\n find:%d\n",count,nowmaxcount,find);
		count++;
		if(find==0){
			if(count<=nowmaxcount){         //避免只有一個T狀況發生 
				find=1;
			}       
			
		}
		
		/*for(int a=0;a<floor;a++){        //數字地圖讀檔確認 
			for(int b=0;b<n;b++){
				for(int c=0;c<n;c++){
					printf("%3d ",nmaze[a][b][c]);
				}
				printf("\n");
			}
			printf("\n");
			n-=2;
		}
		n=temp_n;
		//system("cls");*/
	}
	/*for(int i=0;i<floor;i++){        //數字地圖讀檔最終確認 
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				printf("%3d ",nmaze[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		n-=2;
	}
	n=temp_n;*/
	
	if(find_2){
		maze2[num_floor][0][0]='*';
		maze2[end_f][end_r][end_c]='*';
		int findS=0;
		now_f=end_f;now_r=end_r;now_c=end_c;
		while(!findS){
			int temp[6]={0};
			for(i=0;i<6;i++){
				temp[i]=99;
			}
			if(now_r-1>=0&&now_r-1<=(num_floor-now_f)*2){
				temp[0]=nmaze[now_f][now_r-1][now_c];
			}
			if(now_r+1>=0&&now_r+1<=(num_floor-now_f)*2){
				temp[1]=nmaze[now_f][now_r+1][now_c];
			}
			if(now_c-1>=0&&now_c-1<=(num_floor-now_f)*2){
				temp[2]=nmaze[now_f][now_r][now_c-1];
			}
			if(now_c+1>=0&&now_c+1<=(num_floor-now_f)*2){
				temp[3]=nmaze[now_f][now_r][now_c+1];
			}
			if(now_f>=0&&maze[now_f-1][now_r+1][now_c+1]=='U'){
				temp[4]=nmaze[now_f-1][now_r+1][now_c+1];
			}
			if(now_f<=num_floor&&maze[now_f+1][now_r-1][now_c-1]=='D'){
				temp[5]=nmaze[now_f+1][now_r-1][now_c-1];
			}
			
			int nummin=99,numi=-1;
			for(i=0;i<6;i++){
			//	printf("temp%d = %d\n",i,temp[i]);      //check
				if(temp[i]<nummin){
					
					nummin=temp[i];
					numi=i;
				}
			}
			
			if(numi==0){
				maze2[now_f][now_r-1][now_c]='*';
				now_r=now_r-1;
			}else if(numi==1){
				maze2[now_f][now_r+1][now_c]='*';
				now_r=now_r+1;
			}else if(numi==2){
				maze2[now_f][now_r][now_c-1]='*';
				now_c=now_c-1;
			}else if(numi==3){
				maze2[now_f][now_r][now_c+1]='*';
				now_c=now_c+1;
			}else if(numi==4){
				maze2[now_f-1][now_r+1][now_c+1]='*';
				now_f=now_f-1;
				now_r=now_r+1;
				now_c=now_c+1;
			}else if(numi==5){
				maze2[now_f+1][now_r-1][now_c-1]='*';
				now_f=now_f+1;
				now_r=now_r-1;
				now_c=now_c-1;
			}
			
			if(maze[now_f][now_r][now_c]=='S'){
				findS=1;
			}
			/*for(int i=0;i<floor;i++){        //地圖讀檔確認 
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
		}
		/*for(int i=0;i<floor;i++){        //result
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
		
		int min=nmaze[end_f][end_r][end_c];
		//printf("Path length: %d\n",min);                        //上方幾乎就是2_1 
		int limit=min+5;                              //藉由廣度找到最短路徑、最短路徑長、Limit，以優化下方的深度搜尋 
		////////////////////////////////////////////////////////////////////////////
		int all_path=0;
		while(top>-1){                            //深度搜尋 //找所有路徑 
		
		now_f=stack[top].f;
		now_r=stack[top].r;
		now_c=stack[top].c;
		now_d=stack[top].d;
		//printf("now: %d %d %d \n",now_f,now_r,now_c);      //確認路徑 
		if(now_f==end_f && now_r==end_r && now_c==end_c){
			all_path++;
			maze3[stack[top].f][stack[top].r][stack[top].c]='U';

			top--;
			path--;
			now_f=stack[top].f;
			now_r=stack[top].r;
			now_c=stack[top].c;
			now_d=stack[top].d;
			
			end_or_not=1;
		}

		find=0,find_2=0;
		while(now_d<=5&&find==0){           //dir1~5
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
				
				if(now_f<=num_floor&&now_r<=(num_floor-now_f)*2&&now_c<=(num_floor-now_f)*2&&now_r>=0&&now_c>=0){
					if(maze[now_f][now_r][now_c]!='X'&&maze3[now_f][now_r][now_c]!='*'){
						
						stack[top].d=now_d;
						top++;
						stack[top].f=now_f;
						stack[top].r=now_r;
						stack[top].c=now_c;
						stack[top].d=-1;
						maze3[now_f][now_r][now_c]='*';
						if(maze[now_f][now_r][now_c]=='T'){
							path+=3;
						}else{
							path++;
						}
					
						/*for(int i=0;i<floor;i++){                  //地圖讀檔確認 
							for(int j=0;j<n;j++){
								for(int k=0;k<n;k++){
									printf("%c ",maze3[i][j][k]);
								}
								printf("\n");
							}
							printf("\n");
							n-=2;
						}
						_sleep(100);
						system("cls");*/
					}else{
						stack[top].d=4;      //在未成功的情況下依舊把4值存入，才得以繼續跑回圈 
					}
					n=temp_n;
				}else{
					stack[top].d=4;
				}
				
				break;
				break;
			}else if(now_d==5&&maze[stack[top].f][stack[top].r][stack[top].c]=='D'){       //D
				now_f=stack[top].f-1;
				now_r=stack[top].r+1;
				now_c=stack[top].c+1;
				
				if(now_f>=0&&now_r>=0&&now_c>=0&&now_r<=(num_floor-now_f)*2&&now_c<=(num_floor-now_f)*2){
					if(maze[now_f][now_r][now_c]!='X'&&maze3[now_f][now_r][now_c]!='*'){
						stack[top].d=now_d;
						top++;
						stack[top].f=now_f;
						stack[top].r=now_r;
						stack[top].c=now_c;
						stack[top].d=-1;
						maze3[now_f][now_r][now_c]='*';
				
						if(maze[now_f][now_r][now_c]=='T'){
							path+=3;
						}else{
							path++;
						}
					
					
					/*for(int i=0;i<floor;i++){                //地圖讀檔確認 
						for(int j=0;j<n;j++){
							for(int k=0;k<n;k++){
								printf("%c ",maze3[i][j][k]);
								printf("\n");
							}
						printf("\n");
						n-=2;
						}
					}
					_sleep(100);
					system("cls");
					n=temp_n;	*/
					}else{
						stack[top].d=5;       //避免掉許多意外狀況 
					}
				}else{
					stack[top].d=5;            //ex 死路&&D&&下方有路BUT是X...等等狀況 
				}
				break;                     //這邊是專為now_d==4、5的狀況寫的，跑完就可以跳開了 
				break;
			}
			
			if(now_d<4&&now_r>=0&&now_r<=(num_floor-now_f)*2&&now_c>=0&&now_c<=(num_floor-now_f)*2){
				if(maze[now_f][now_r][now_c]!='X'&&maze3[now_f][now_r][now_c]!='*'&&maze3[now_f][now_r][now_c]!='T'){
				find=1;
				path++;
				}else if(maze[now_f][now_r][now_c]=='T'&&maze3[now_f][now_r][now_c]=='T'){
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
			maze3[now_f][now_r][now_c]='*';
			
			/*for(int i=0;i<floor;i++){   //i=-1 去掉前述       //地圖讀檔確認 
				for(int j=0;j<n;j++){
					for(int k=0;k<n;k++){
						printf("%c ",maze3[i][j][k]);
					}
					printf("\n");
					}
					printf("\n");
				n-=2;
			}
			n=temp_n;
			_sleep(100);
			system("cls");*/
		}
		if(now_d==6||path>limit){                                                         //倒退機制 
			if(maze[stack[top].f][stack[top].r][stack[top].c]=='O'){
				maze3[stack[top].f][stack[top].r][stack[top].c]='O';
				top--;
				path--;
			}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='U'){
				maze3[stack[top].f][stack[top].r][stack[top].c]='U';
				top--;
				path--;
			}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='D'){
				maze3[stack[top].f][stack[top].r][stack[top].c]='D';
				top--;
				path--;
			}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='T'){
				maze3[stack[top].f][stack[top].r][stack[top].c]='T';
				top--;
				path-=3;
			}else if(maze[stack[top].f][stack[top].r][stack[top].c]=='S'){     
				top--;
			}
			
		}
	}
	fprintf(fptr2,"Shortest path: %d, Limit: %d, The number of different paths: %d \n\n",min,limit,all_path);       //寫檔 
	}else{
		printf("There's no way from S to F.\n");
	}
	
	
	
	
	/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c ",maze[i][j]);
			}
			printf("\n");
		}*/
	fclose(fptr);
	printf("Test %d is done.\n",numtest);
	numtest++;
}
	fclose(fptr2);
	
	//system("pause");
	return 0;
	
}
