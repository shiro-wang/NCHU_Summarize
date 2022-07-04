#include<stdio.h>
#include<stdlib.h>
#define MAX 10

FILE *fptr;
FILE *fptr2;

typedef struct Node Node;
struct Node{
	int end;
	int total;
	int mcount;
	char monster;
	int mirror;
	int path1_i, path1_j, path1_m, path2_i, path2_j, path2_m, path3_i, path3_j, path3_m, path4_i, path4_j, path4_m;
	int repeat;
};
Node* map[MAX][MAX];

void find(struct Node* n, int i, int j){
	int a=1;
	int tempi=i,tempj=j;
	int c1,c2;
	int m;
	while(a<=4){
		i=tempi;j=tempj;
		m=0;
		switch(a){
			case 1:					//up
				c1=-1;c2=0;
				while(map[i][j]->end!=1){
					switch(map[i][j]->mirror){
						case 0:
							break;
						case 1:
							if(c1==-1){
								c1=0;c2=1;
							}else if(c1==1){
								c1=0;c2=-1;
							}else if(c2==-1){
								c2=0;c1=1;
							}else if(c2==1){
								c2=0;c1=-1;
							}
							m=1;
							break;
						case 2:
							if(c1==-1){
								c1=0;c2=-1;
							}else if(c1==1){
								c1=0;c2=1;
							}else if(c2==-1){
								c2=0;c1=-1;
							}else if(c2==1){
								c2=0;c1=1;
							}
							m=1;
							break;
					}
					i=i+c1;j=j+c2;
				}
				n->path1_i=i; n->path1_j=j;
				if(m==0){
					n->path1_m=0;
				}else{
					n->path1_m=1;
				}
				break;
			case 2:					//right
				c1=0;c2=1;
				while(map[i][j]->end!=1){
					switch(map[i][j]->mirror){
						case 0:
							break;
						case 1:
							if(c1==-1){
								c1=0;c2=1;
							}else if(c1==1){
								c1=0;c2=-1;
							}else if(c2==-1){
								c2=0;c1=1;
							}else if(c2==1){
								c2=0;c1=-1;
							}
							m=1;
							break;
						case 2:
							if(c1==-1){
								c1=0;c2=-1;
							}else if(c1==1){
								c1=0;c2=1;
							}else if(c2==-1){
								c2=0;c1=-1;
							}else if(c2==1){
								c2=0;c1=1;
							}
							m=1;
							break;
					}
					i=i+c1;j=j+c2;
				}
				n->path2_i=i; n->path2_j=j;
				if(m==0){
					n->path2_m=0;
				}else{
					n->path2_m=1;
				}
				break;
			case 3:					//down
				c1=1;c2=0;
				while(map[i][j]->end!=1){
					switch(map[i][j]->mirror){
						case 0:
							break;
						case 1:
							if(c1==-1){
								c1=0;c2=1;
							}else if(c1==1){
								c1=0;c2=-1;
							}else if(c2==-1){
								c2=0;c1=1;
							}else if(c2==1){
								c2=0;c1=-1;
							}
							m=1;
							break;
						case 2:
							if(c1==-1){
								c1=0;c2=-1;
							}else if(c1==1){
								c1=0;c2=1;
							}else if(c2==-1){
								c2=0;c1=-1;
							}else if(c2==1){
								c2=0;c1=1;
							}
							m=1;
							break;
					}
					i=i+c1;j=j+c2;
				}
				n->path3_i=i; n->path3_j=j;
				if(m==0){
					n->path3_m=0;
				}else{
					n->path3_m=1;
				}
				break;
			case 4:					//left
				c1=0;c2=-1;
				while(map[i][j]->end!=1){
					switch(map[i][j]->mirror){
						case 0:
							break;
						case 1:
							if(c1==-1){
								c1=0;c2=1;
							}else if(c1==1){
								c1=0;c2=-1;
							}else if(c2==-1){
								c2=0;c1=1;
							}else if(c2==1){
								c2=0;c1=-1;
							}
							m=1;
							break;
						case 2:
							if(c1==-1){
								c1=0;c2=-1;
							}else if(c1==1){
								c1=0;c2=1;
							}else if(c2==-1){
								c2=0;c1=-1;
							}else if(c2==1){
								c2=0;c1=1;
							}
							m=1;
					}
					i=i+c1;j=j+c2;
				}
				n->path4_i=i; n->path4_j=j;
				if(m==0){
					n->path4_m=0;
				}else{
					n->path4_m=1;
				}
				break;
		}
		a++;
	}
}

int main(){
	int numtest=1;			//在此更改檔名 
	char s[MAX];
	
	sprintf(s,"test%d.txt",numtest);
	fptr=fopen(s,"r");
	if(fptr==NULL)
	{
		printf("檔案test%d開啟失敗!",numtest);
		exit(0);
	}
	sprintf(s,"output%d.txt",numtest);
	fptr2=fopen(s,"w");
	if(fptr2==NULL)
	{
		printf("檔案output%d開啟失敗!",numtest);
		exit(0);
	}
	///////////////
	int i,j,k,l;
	
	for(i=0;i<MAX;i++){						//初始化 
		for(j=0;j<MAX;j++){
			map[i][j]=(Node*)malloc(sizeof(Node));
			map[i][j]->total=0;
			map[i][j]->monster='.';
			map[i][j]->mirror=0;
			map[i][j]->end=0;
			map[i][j]->mcount=0;
			map[i][j]->repeat=0;
		}
	}
	
	int V,Z,G;
	int vcount=0,zcount=0,gcount=0;
	int R;
	int endnum[MAX][MAX];
	char ch;
	fscanf(fptr,"%d %d %d",&V,&Z,&G);
	fscanf(fptr,"%d",&R);
	////////////////////     				//外圍一圈設end=1 
	for(i=0;i<4;i++){
		for(j=0;j<R;j++){
			fscanf(fptr,"%d",&endnum[i][j]);
		}
	}	getc(fptr);
	for(i=0;i<R;i++){
		map[0][i+1]->total=endnum[0][i];
		map[0][i+1]->end=1;
	}
	for(i=0;i<R;i++){
		map[R+1][i+1]->total=endnum[1][i];
		map[R+1][i+1]->end=1;
	}
	for(i=0;i<R;i++){
		map[i+1][0]->total=endnum[2][i];
		map[i+1][0]->end=1;
	}
	for(i=0;i<R;i++){
		map[i+1][R+1]->total=endnum[3][i];
		map[i+1][R+1]->end=1;
	}
	///////////////////
	for(i=1;i<=R;i++){
		j=1;
		while((ch=getc(fptr))!='\n'&&ch!=EOF){		//鏡子情況 
			if(ch!='.'){
				if(ch=='/'){						//1-> '/'
					map[i][j]->mirror=1;
				}else{
					map[i][j]->mirror=2;		//2-> '\'
				}	
			}
			j++;
		}
	}
	
	struct element{
		Node *s;
		int d;
	};
	struct element stack[MAX*MAX];				//利用stack做dfs 
	int e=0;
	
	/*for(i=1;i<=R;i++){					//check
		for(j=1;j<=R;j++){
			printf("%d ",map[i][j]->mirror);
		}
		printf("\n");
	}*/
	
	for(i=1;i<=R;i++){					//find 4 directions' exit
		for(j=1;j<=R;j++){
			if(map[i][j]->mirror==0){
				stack[e++].s=map[i][j];
				find(map[i][j],i,j);
			}
		}
	}
	int top=0;
	int found=0;
	
	stack[top].d=-1;			//d1-3 Z->V->G
	
	//printf("\n%d %d %d %d %d %d %d %d\n",map[2][3]->path1_i,map[2][3]->path1_j,map[2][3]->path1_m,map[2][3]->path2_m,map[2][3]->path3_i,map[2][3]->path3_j,map[2][3]->path4_i,map[2][3]->path4_j);
	
	while(top>=0&&top<e){				//DFS	
		found=0;
		while(!found&&stack[top].d<3){
			stack[top].d++;
			//printf("top: %d d: %d\n",top,stack[top].d);
			switch(stack[top].d){
				case 0:				//Z
					if(zcount<Z){
						if(map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount<map[stack[top].s->path1_i][stack[top].s->path1_j]->total){
							if(map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount<map[stack[top].s->path2_i][stack[top].s->path2_j]->total){
								if(map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount<map[stack[top].s->path3_i][stack[top].s->path3_j]->total){
									if(map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount<map[stack[top].s->path4_i][stack[top].s->path4_j]->total){
										found=1;
										//printf("zfind\n");
									}
								}
							}
						}
					}
					break;
				case 1:				//V			//如果有經過鏡子 不會往上加 用or 
					if(vcount<V){
						if((map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount < map[stack[top].s->path1_i][stack[top].s->path1_j]->total) || stack[top].s->path1_m==1){
							if((map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount < map[stack[top].s->path2_i][stack[top].s->path2_j]->total) || stack[top].s->path2_m==1){
								if((map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount < map[stack[top].s->path3_i][stack[top].s->path3_j]->total) || stack[top].s->path3_m==1){
									if((map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount < map[stack[top].s->path4_i][stack[top].s->path4_j]->total) || stack[top].s->path4_m==1){
										found=1;
										//printf("vfind\n");
									}
								}
							}
						}
					}
					break;
				case 2:				//G			//如果沒有經過鏡子 不會往上加 用or
					if(gcount<G){
						if((map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount < map[stack[top].s->path1_i][stack[top].s->path1_j]->total)||stack[top].s->path1_m==0){
							//printf("gfind\n");
							if((map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount < map[stack[top].s->path2_i][stack[top].s->path2_j]->total)||stack[top].s->path2_m==0){
								//printf("gfind\n");
								if((map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount < map[stack[top].s->path3_i][stack[top].s->path3_j]->total)||stack[top].s->path3_m==0){
									//printf("gfind\n");
									if((map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount < map[stack[top].s->path4_i][stack[top].s->path4_j]->total)||stack[top].s->path4_m==0){
										found=1;
										//printf("gfind\n");
									}
								}
							}
						}
					}
					break;
			}
		}
		
		///////////////////////////////////////原本寫的是若經過鏡子回到同一個output點 有加過的話就不會重複計算 後來發現不用管-3- 
		if(found){
			int plus1,plus2,plus3;
			switch(stack[top].d){
				case 0:				//Z
					map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount++;
					map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
						map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount++;
						map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
					}
					if(1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/){
						map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount++;
						map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
					}
					if(1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/){
						map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount++;
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					stack[top].s->monster='Z';
					top++; 
					stack[top].d=-1;
					zcount++;
					break;
				case 1:				//V
					if(stack[top].s->path1_m!=1){
						map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount++;
						map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					}
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
						if(stack[top].s->path2_m!=1){
							map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount++;
							map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
						if(stack[top].s->path3_m!=1){
							map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount++;
							map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
						if(stack[top].s->path4_m!=1){
							map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount++;
							map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
						}	
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					
					stack[top].s->monster='V';
					top++;
					stack[top].d=-1;
					vcount++;
					break;
				case 2:				//G
					if(stack[top].s->path1_m==1){
						map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount++;
						map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					}
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
						if(stack[top].s->path2_m==1){
							map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount++;
							map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
						if(stack[top].s->path3_m==1){
							map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount++;
							map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
						if(stack[top].s->path4_m==1){
							map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount++;
							map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
						}	
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					
					stack[top].s->monster='G';
					top++;
					stack[top].d=-1;
					gcount++;
					break;
			}
			/*for(i=0;i<=R+1;i++){					//check
				for(j=0;j<=R+1;j++){
					if(map[i][j]->end==1){
						printf("%d ",map[i][j]->mcount);
					}else{
						if(map[i][j]->mirror==0){
							printf("%c ",map[i][j]->monster);
						}else if(map[i][j]->mirror==1){
							printf("/ ");
						}else{
							printf("%c ",92);
						}
					}
				}
				printf("\n");
			}
			printf("z: %d v: %d g: %d\n",zcount,vcount,gcount);*/
			
			if(top==e){						//endcheck
				int endc=1;
				for(i=0;i<R;i++){
					if(map[0][i+1]->mcount!=map[0][i+1]->total){
						endc=0;
					}	
				}
				for(i=0;i<R;i++){
					if(map[R+1][i+1]->mcount!=map[R+1][i+1]->total){
						endc=0;
					}
				}
				for(i=0;i<R;i++){
					if(map[i+1][0]->mcount!=map[i+1][0]->total){
						endc=0;
					}
				}
				for(i=0;i<R;i++){
					if(map[i+1][R+1]->mcount!=map[i+1][R+1]->total){
						endc=0;
					}
				}
				if(!endc){						//全填完了可是endpoint mcount!=題目提供的話還是要倒退 
					//printf("go back\n");
					top--;
					if(stack[top].s->monster=='Z'){				//Z
						map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
						map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
						if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
							map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
							map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
						}
						if(1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/){
							map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
							map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
						}
						if(1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/){
							map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
						}
						for(i=0;i<MAX;i++){						//初始化 
							for(j=0;j<MAX;j++){
								map[i][j]->repeat=0;
							}
						}
						zcount--;
					}else if(stack[top].s->monster=='V'){		//V
						if(stack[top].s->path1_m!=1){
							map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
							map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
						}
						if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0 */){		//避免重複路徑 
							if(stack[top].s->path2_m!=1){
								map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
								map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
							}	
						}
						if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0 */){		
							if(stack[top].s->path3_m!=1){
								map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
								map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
							}	
						}
						if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
							if(stack[top].s->path4_m!=1){
								map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
								map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
							}	
						}
						for(i=0;i<MAX;i++){						//初始化 
							for(j=0;j<MAX;j++){
								map[i][j]->repeat=0;
							}
						}
						vcount--;
					}else if(stack[top].s->monster=='G'){		//G
						if(stack[top].s->path1_m==1){
							map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
							map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
						}
						if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
							if(stack[top].s->path2_m==1){
								map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
								map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
							}	
						}
						if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
							if(stack[top].s->path3_m==1){
								map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
								map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
							}	
						}
						if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
							if(stack[top].s->path4_m==1){
								map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
								map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
							}	
						}
						for(i=0;i<MAX;i++){						//初始化 
							for(j=0;j<MAX;j++){
								map[i][j]->repeat=0;
							}
						}
						gcount--;
					}
					stack[top].s->monster='.';
				}
			}
		}
		
		if(found==0){				//not found
			if(stack[top].s->monster=='Z'){				//Z
				map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
				map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
				if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
					map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
					map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
				}
				if(1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/){
					map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
					map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
				}
				if(1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/){
					map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
				}
				for(i=0;i<MAX;i++){						//初始化 
					for(j=0;j<MAX;j++){
						map[i][j]->repeat=0;
					}
				}
				zcount--;
			}else if(stack[top].s->monster=='V'){		//V
				if(stack[top].s->path1_m!=1){
					map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
					map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
				}
				if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
					if(stack[top].s->path2_m!=1){
						map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
						map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
					}	
				}
				if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
					if(stack[top].s->path3_m!=1){
						map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
						map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
					}	
				}
				if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
					if(stack[top].s->path4_m!=1){
						map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
						map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
					}	
				}
				for(i=0;i<MAX;i++){						//初始化 
					for(j=0;j<MAX;j++){
						map[i][j]->repeat=0;
					}
				}
				vcount--;
			}else if(stack[top].s->monster=='G'){		//G
				if(stack[top].s->path1_m==1){
					map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
					map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
				}
				if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
					if(stack[top].s->path2_m==1){
						map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
						map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
					}	
				}
				if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
					if(stack[top].s->path3_m==1){
						map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
						map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
					}	
				}
				if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
					if(stack[top].s->path4_m==1){
						map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
						map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
					}	
				}
				for(i=0;i<MAX;i++){						//初始化 
					for(j=0;j<MAX;j++){
						map[i][j]->repeat=0;
					}
				}
				gcount--;
			}
			stack[top].s->monster='.';
			top--;
			if(top>=0){
				if(stack[top].s->monster=='Z'){				//Z
					map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
					map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
						map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
						map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
					}
					if(1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/){
						map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
						map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
					}
					if(1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/){
						map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					zcount--;
				}else if(stack[top].s->monster=='V'){		//V
					if(stack[top].s->path1_m!=1){
						map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
						map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					}
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0 */){		//避免重複路徑 
						if(stack[top].s->path2_m!=1){
							map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
							map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0 */){		
						if(stack[top].s->path3_m!=1){
							map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
							map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
						if(stack[top].s->path4_m!=1){
							map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
							map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
						}	
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					vcount--;
				}else if(stack[top].s->monster=='G'){		//G
					if(stack[top].s->path1_m==1){
						map[stack[top].s->path1_i][stack[top].s->path1_j]->mcount--;
						map[stack[top].s->path1_i][stack[top].s->path1_j]->repeat=1;
					}
					if( 1/*map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat==0*/ ){		//避免重複路徑 
						if(stack[top].s->path2_m==1){
							map[stack[top].s->path2_i][stack[top].s->path2_j]->mcount--;
							map[stack[top].s->path2_i][stack[top].s->path2_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat==0*/ ){		
						if(stack[top].s->path3_m==1){
							map[stack[top].s->path3_i][stack[top].s->path3_j]->mcount--;
							map[stack[top].s->path3_i][stack[top].s->path3_j]->repeat=1;
						}	
					}
					if( 1/*map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat==0*/ ){		
						if(stack[top].s->path4_m==1){
							map[stack[top].s->path4_i][stack[top].s->path4_j]->mcount--;
							map[stack[top].s->path4_i][stack[top].s->path4_j]->repeat=1;
						}	
					}
					for(i=0;i<MAX;i++){						//初始化 
						for(j=0;j<MAX;j++){
							map[i][j]->repeat=0;
						}
					}
					gcount--;
				}
				stack[top].s->monster='.';
			}
			
			/*for(i=0;i<=R+1;i++){					//check
				for(j=0;j<=R+1;j++){
					if(map[i][j]->end==1){
						printf("%d ",map[i][j]->mcount);
					}else{
						if(map[i][j]->mirror==0){
							printf("%c ",map[i][j]->monster);
						}else if(map[i][j]->mirror==1){
							printf("/ ");
						}else{
							printf("%c ",92);
						}
					}
				}
				printf("\n");
			}
			printf("z: %d v: %d g: %d\n",zcount,vcount,gcount);*/
		}
	}
	
	if(top<0){
		fprintf(fptr2,"not found\n");
	}else if(top==e){
		for(i=1;i<=R;i++){					//endoutput
			for(j=1;j<=R;j++){	
				if(map[i][j]->mirror==0){
					fprintf(fptr2,"%c",map[i][j]->monster);
				}else if(map[i][j]->mirror==1){
					fprintf(fptr2,"/");
				}else{
					fprintf(fptr2,"%c",92);
				}
			}
			fprintf(fptr2,"\n");
		}
	}
	
	fclose(fptr);
	fclose(fptr2);
	return 0;
}
