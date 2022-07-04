#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

FILE *fptr;

int main(){
	int numtest=1;
	while(numtest<=1){
		char s[]={0};
		sprintf(s,"test%d.txt",numtest);

		fptr=fopen("test88.txt","r");
		
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
	char maze2[floor][n][n]={0};	//路徑圖
	int nmaze[floor][n][n]={0};    //數字圖 
	char end[floor][n][n]={0};     //最短結果 
	for(int i=0;i<floor;i++){        
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				nmaze[i][j][k]=99;
			}	
		}
		n-=2;
	}
	n=temp_n;
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
	while(find==1){
		find=0;
		for(int i=0;i<floor;i++){   
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
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
		
		for(int a=0;a<floor;a++){        //數字地圖讀檔確認 
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
		system("cls");
	}
	for(int i=0;i<floor;i++){        //數字地圖讀檔最終確認 
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				printf("%3d ",nmaze[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		n-=2;
	}
	n=temp_n;

	count--;
	
	if(find_2){
		maze2[num_floor][0][0]='*';
		maze2[end_f][end_r][end_c]='*';
		int findS=0;
		now_f=end_f;now_r=end_r;now_c=end_c;
		while(!findS){
			int temp[6]={0};
			for(int i=0;i<6;i++){
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
			for(int i=0;i<6;i++){
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
		for(int i=0;i<floor;i++){        //result
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
		
		int min=nmaze[end_f][end_r][end_c];
		printf("Path length: %d",min);
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
	printf("The test %d is done\n",numtest);
	numtest++;
}
	
	system("pause");
	return 0;
	
}
