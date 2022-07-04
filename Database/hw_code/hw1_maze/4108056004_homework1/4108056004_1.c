#include<stdio.h>
#include<stdlib.h>

FILE *fptr;

int main(){
	int i,j,k;
	fptr=fopen("test.txt","r");
	if(fptr==NULL)
	{
		printf("�ɮ�test�}�ҥ���!");
		exit(0);
	}
	int n;
	fscanf(fptr,"%d",&n);   //�s�Jn�� 
	if(n<1||n>20){
		printf("the n: %d is over the size",n);
		exit(0);
	}
	//printf("%d \n",n);
	
	char maze[n][n];
	char maze2[n][n];   //���|�� 
	int nmaze[n][n];
	char end[n][n];     //�̵u���G 
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			nmaze[i][j]=n*n;
		}
	}
	
	char ch;
	int end_or_not=0;
	int start_r,start_c,end_r,end_c;
	//int num=1;
	for(i=-1;i<n;i++){   //i=-1 �h���e�z 
		j=0;
		while((ch=getc(fptr))!='\n'){       //��J 
			
			if(ch!=32){                    //�h���Ů� 
				//printf("the %d:%c \n",num++,ch);
				
				maze[i][j]=ch;
				maze2[i][j]=ch;
				if(ch=='S'){
					start_r=i;
					start_c=j;
				}else if(ch=='F'){
					end_r=i;
					end_c=j;
				}
				j++;
			}
		}
	}
	//printf("S:%d %d\n",start_r,start_c);
	//printf("F:%d %d\n",end_r,end_c);      //ok 

	maze2[start_r][start_c]='*';
	nmaze[start_r][start_c]=1;
	
	typedef struct{
		short int r;
		short int c;
		short int d;	
	} element;
	element stack[n*n];
	
	int top=0;
	int min=n*n;
	int find=1,find_2=0;
	int now_r,now_c,now_d;
	int count=1;
	
	
	stack[top].r=start_r;
	stack[top].c=start_c;
	stack[top].d=-1;
	
	while(find==1){                    //�s�׷j�M 
		find=0;
		for(i=0;i<n;i++){   
			for(j=0;j<n;j++){
				if(nmaze[i][j]==count){                   ///�C���̧ǧ��m��Ʀr 
					if(i==end_r&&j==end_c){                      
						find_2=1;
						break;
					}
					if(i-1>=0&&(nmaze[i][j]<nmaze[i-1][j])&&maze[i-1][j]!='X'){  //������U�@��p�~���� 
						nmaze[i-1][j]=count+1;
						find=1;
					}
					if(i+1<n&&(nmaze[i][j]<nmaze[i+1][j])&&maze[i+1][j]!='X'){
						nmaze[i+1][j]=count+1;
						find=1;	
					}
					if(j-1<n&&(nmaze[i][j]<nmaze[i][j-1])&&maze[i][j-1]!='X'){
						nmaze[i][j-1]=count+1;
						find=1;	
					}
					if(j+1<n&&(nmaze[i][j]<nmaze[i][j+1])&&maze[i][j+1]!='X'){
						nmaze[i][j+1]=count+1;
						find=1;	
					}
					
				}
			}	
		}
		//printf("now count:%d\n find:%d\n",count,find);
		count++;
		
		/*int a,b;
		for(a=0;a<n;a++){        //�Ʀr�a��Ū�ɽT�{ 
			for(b=0;b<n;b++){
				printf("%3d ",nmaze[a][b]);
			}
			printf("\n");
		}*/
		//system("cls");
	}
	/*for(i=0;i<n;i++){        //�Ʀr�a��Ū�ɳ̲׽T�{ 
		for(j=0;j<n;j++){
			printf("%3d ",nmaze[i][j]);
		}
		printf("\n");
	}*/

	count--;
	
	if(find_2){
		maze2[end_r][end_c]='*';
		int findS=0;
		now_r=end_r;now_c=end_c;
		while(!findS){                       //���ewhile 
			int temp[4]={0};
			for(i=0;i<4;i++){
				temp[i]=99;
			}
			if(now_r-1>=0){
				temp[0]=nmaze[now_r-1][now_c];
			}
			if(now_r+1<=n){
				temp[1]=nmaze[now_r+1][now_c];
			}
			if(now_c-1>=0){
				temp[2]=nmaze[now_r][now_c-1];
			}
			if(now_c+1<=n){
				temp[3]=nmaze[now_r][now_c+1];
			}
			
			int nummin=99,numi=-1;                     //�]�O�q�p��j����A�q���I���^���4�P�̤p���ƨ� 
			for(i=0;i<4;i++){
			//	printf("temp%d = %d\n",i,temp[i]);      //check
				if(temp[i]<nummin){
					
					nummin=temp[i];
					numi=i;
				}
			}
			
			if(numi==0){
				maze2[now_r-1][now_c]='*';
				now_r=now_r-1;
			}else if(numi==1){
				maze2[now_r+1][now_c]='*';
				now_r=now_r+1;
			}else if(numi==2){
				maze2[now_r][now_c-1]='*';
				now_c=now_c-1;
			}else if(numi==3){
				maze2[now_r][now_c+1]='*';
				now_c=now_c+1;
			}
			
			if(maze[now_r][now_c]=='S'){
				findS=1;
			}
			/*for(int i=0;i<floor;i++){        //�a��Ū�ɽT�{ 
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
		for(i=0;i<n;i++){        //result
			for(j=0;j<n;j++){
				printf("%c ",maze2[i][j]);
			}
			printf("\n");
		}
		int min=nmaze[end_r][end_c];
		printf("Path length: %d",min);
	}else{
		printf("There's no way from S to F.\n");
	}
	fclose(fptr);
	
	system("pause");
	return 0;
	
}
