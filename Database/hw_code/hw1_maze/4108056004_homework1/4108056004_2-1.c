#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//using namespace std;

FILE *fptr;
FILE *fptr2;

int main(){
	short int numtest=1;
	short int i,j,k;
	short int floor=0;
	short int num_floor=0;
	short int temp_n=0;
	short int space=0;
	short int start_r=0,start_c=0,start_f=0,end_f=0,end_r=0,end_c=0;
	short int end_or_not=0;
	int top=0;
	short int find=1,find_2=0;
	short int now_f=0,now_r=0,now_c=0,now_d=0;
	int path=1;
	int count=1;
	
	while(numtest<=100){
		char s[]={0};
		char s2[]={0};
		sprintf(s,"test%d.txt",numtest);

		fptr=fopen(s,"r");
		
		if(fptr==NULL)
		{
			printf("檔案test%d開啟失敗!",numtest);
			//break;
		}
		sprintf(s2,"test%d_ans.txt","numtest");
		fptr2=fopen(s,"w");
		if(fptr2==NULL)
		{
			printf("檔案test%d_ans開啟失敗!",numtest);
			//break;
		}
		
	int n=0;
	char ch;
	while((ch=getc(fptr))!='\n'){
		if(ch!=' '){
			n++;
		}
	}
	floor=n/2+1;    //蓋樓層 
	temp_n=n;
	rewind(fptr);  //檔案存取位置重新設為開頭 
	
	char maze[floor][n][n];    //原圖 
	char maze2[floor][n][n];	//路徑圖
	int nmaze[floor][n][n];    //數字圖 
	char end[floor][n][n];     //最短結果 
	for(i=0;i<floor;i++){        
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				nmaze[i][j][k]=99;
			}	
		}
		n-=2;
	}
	n=temp_n;
	space=0;
	
	end_or_not=0; //是否有終點 
	
	for(i=0;i<floor;i++){                   //開始讀檔 
		for(j=space;j<n;j++){
			k=0;
			
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
	
	/*typedef struct{
		short int f;
		short int r;
		short int c;
		short int d;	
	} element;
	element stack[n*n*floor];*/
	
	top=0;

	find=1,find_2=0;
	now_f=0,now_r=0,now_c=0,now_d=0;//現在位置 
	
	num_floor=floor-1;        //if floor=3,num_floor=2
	end_f=num_floor-1;end_r=1;end_c=1; //直接定義終點 
	
	//printf("S:%d %d %d\n",start_f,start_r,start_c);
	//printf("F:%d %d %d\n",end_f,end_r,end_c);      //ok 
	
	nmaze[start_f][start_r][start_c]=1;
	
	/*stack[top].f=start_f;
	stack[top].r=start_r;
	stack[top].c=start_c;
	stack[top].d=-1;*/
	path=1;
	count=1;
	
	int nowmaxcount=0;   //cause of T
	while(find==1){                        //廣度搜尋 
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
								if(nmaze[i][j-1][k]>count+3){                          //特別留意T的狀況 
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

	count--;
	
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
		int min=nmaze[end_f][end_r][end_c];
		fprintf(fptr2,"=====outMaze=====\nPath length: %d\n\n",min);
		for(i=0;i<floor;i++){        //result
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					fprintf(fptr2,"%c ",maze2[i][j][k]);
				}
				fprintf(fptr2,"\n");
			}
		fprintf(fptr2,"\n");
		n-=2;
		}
		n=temp_n;
		
		
		
	}else{
		fprintf(fptr2,"There's no way from S to F.\n");
	}
	
	
	
	
	/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c ",maze[i][j]);
			}
			printf("\n");
		}*/
	fclose(fptr);
	fclose(fptr2);
	printf("The test %d is done\n",numtest);
	numtest++;
}
	
	//system("pause");
	return 0;
	
}
