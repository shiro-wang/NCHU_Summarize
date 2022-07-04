#include<stdio.h>
#include<stdlib.h>
#define M 10

FILE *fptr;
FILE *fptr2;

int main(){
    int numtest=3;			//在此更改檔名 
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
    
    int i,j,k,l,m;
    int start_a, start_b, start_c, start_d;
    int end_a, end_b, end_c, end_d;
    int N;
    int pass[M][M][M][M];
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            for(k=0;k<M;k++){
                for(l=0;l<M;l++){
                    pass[i][j][k][l]=10000;
                }
            }
        }
    }
    
    fscanf(fptr,"%d %d %d %d",&start_a, &start_b, &start_c, &start_d);
    //printf("%d %d %d %d\n",start_a,start_b,start_c,start_d);
    fscanf(fptr,"%d %d %d %d",&end_a, &end_b, &end_c, &end_d);
    //printf("%d %d %d %d\n",end_a,end_b,end_c,end_d);
    pass[start_a][start_b][start_c][start_d]=0;
    
    fscanf(fptr,"%d",&N);
    //printf("N %d\n",N);
    									//bfs+禁忌 
    for(i=0;i<N;i++){
        int forbidden_a, forbidden_b, forbidden_c, forbidden_d;
        fscanf(fptr,"%d %d %d %d",&forbidden_a, &forbidden_b, &forbidden_c, &forbidden_d);
        //printf("%d %d %d %d\n\n",forbidden_a, forbidden_b, forbidden_c, forbidden_d);
        pass[forbidden_a][forbidden_b][forbidden_c][forbidden_d]=10001;				//禁忌是10001 
    }
    int count=0;
    int d;
    int i2,j2,k2,l2;
    short int found=0;
    while(!found&&count<=9999){
        for(i=0;i<M;i++){
            for(j=0;j<M;j++){
                for(k=0;k<M;k++){
                    for(l=0;l<M;l++){
                        if(pass[i][j][k][l]==count){
                            d=0;
                            while(d<8){				//從一個點開始 共有8種下一個可能 //做好0->9 9->0情況 
                                switch (d)
                                {
                                case 0:
                                    i2=i+1;j2=j+1;
                                    if(i2==10){
                                        i2=0;
                                    }
                                    if(j2==10){
                                        j2=0;
                                    }
                                    if(pass[i2][j2][k][l]!=10001&&pass[i2][j2][k][l]>count+1){		//似迷宮的數字矩陣 
                                        pass[i2][j2][k][l]=count+1;
                                    }
                                    if(i2==end_a && j2==end_b && k==end_c && l==end_d){		//找到就直接跳出 
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 1:
                                    i2=i+1;j2=j+1;k2=k+1;
                                    if(i2==10){
                                        i2=0;
                                    }
                                    if(j2==10){
                                        j2=0;
                                    }
                                    if(k2==10){
                                        k2=0;
                                    }
                                    if(pass[i2][j2][k2][l]!=10001&&pass[i2][j2][k2][l]>count+1){
                                        pass[i2][j2][k2][l]=count+1;
                                    }
                                    if(i2==end_a && j2==end_b && k2==end_c && l==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 2:
                                    j2=j+1;k2=k+1;l2=l+1;
                                    if(j2==10){
                                        j2=0;
                                    }
                                    if(k2==10){
                                        k2=0;
                                    }
                                    if(l2==10){
                                        l2=0;
                                    }
                                    if(pass[i][j2][k2][l2]!=10001&&pass[i][j2][k2][l2]>count+1){
                                        pass[i][j2][k2][l2]=count+1;
                                    }
                                    if(i==end_a && j2==end_b && k2==end_c && l2==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 3:
                                    k2=k+1;l2=l+1;
                                    if(k2==10){
                                        k2=0;
                                    }
                                    if(l2==10){
                                        l2=0;
                                    }
                                    if(pass[i][j][k2][l2]!=10001&&pass[i][j][k2][l2]>count+1){
                                        pass[i][j][k2][l2]=count+1;
                                    }
                                    if(i==end_a && j==end_b && k2==end_c && l2==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 4:
                                    i2=i-1;j2=j-1;
                                    if(i2==-1){
                                        i2=9;
                                    }
                                    if(j2==-1){
                                        j2=9;
                                    }
                                    if(pass[i2][j2][k][l]!=10001&&pass[i2][j2][k][l]>count+1){
                                        pass[i2][j2][k][l]=count+1;
                                    }
                                    if(i2==end_a && j2==end_b && k==end_c && l==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 5:
                                    i2=i-1;j2=j-1;k2=k-1;
                                    if(i2==-1){
                                        i2=9;
                                    }
                                    if(j2==-1){
                                        j2=9;
                                    }
                                    if(k2==-1){
                                        k2=9;
                                    }
                                    if(pass[i2][j2][k2][l]!=10001&&pass[i2][j2][k2][l]>count+1){
                                        pass[i2][j2][k2][l]=count+1;
                                    }
                                    if(i2==end_a && j2==end_b && k2==end_c && l==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 6:
                                    j2=j-1;k2=k-1;l2=l-1;
                                    if(j2==-1){
                                        j2=9;
                                    }
                                    if(k2==-1){
                                        k2=9;
                                    }
                                    if(l2==-1){
                                        l2=9;
                                    }
                                    if(pass[i][j2][k2][l2]!=10001&&pass[i][j2][k2][l2]>count+1){
                                        pass[i][j2][k2][l2]=count+1;
                                    }
                                    if(i==end_a && j2==end_b && k2==end_c && l2==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                case 7:
                                    k2=k-1;l2=l-1;
                                    if(k2==-1){
                                        k2=9;
                                    }
                                    if(l2==-1){
                                        l2=9;
                                    }
                                    if(pass[i][j][k2][l2]!=10001&&pass[i][j][k2][l2]>count+1){
                                        pass[i][j][k2][l2]=count+1;
                                    }
                                    if(i==end_a && j==end_b && k2==end_c && l2==end_d){
                                        found=1;
                                        d=8;
                                    }
                                    break;
                                default:
                                    break;
                                }
                                d++;
                            }
                        }
                    }
                }
            }
        }
        count++;			//步數統計 
    }
    if(found==0){
    	fprintf(fptr2,"Impossible\n");
    	exit(0);
	}
    fprintf(fptr2,"%d\n",count);
    int step=count;
    int result[count][4];
    result[0][0]=end_a;
    result[0][1]=end_b;
    result[0][2]=end_c;
    result[0][3]=end_d;
    i=end_a;j=end_b;k=end_c;l=end_d;		//從end開始往回找 
    for(m=1;m<=count;m++){
        d=0;
        while(d<8){
            switch (d)
            {
            case 0:
                i2=i+1;j2=j+1;
                if(i2==10){
                    i2=0;
                }
                if(j2==10){
                    j2=0;
                }
                if(pass[i2][j2][k][l]==step-1){		//找到上一步(step-1) 存下這點然後繼續找 
                    result[m][0]=i2;
                    result[m][1]=j2;
                    result[m][2]=k;
                    result[m][3]=l;
                    i=i2;j=j2;
                    d=8;
                    step--;
                }
                break;
            case 1:
                i2=i+1;j2=j+1;k2=k+1;
                if(i2==10){
                    i2=0;
                }
                if(j2==10){
                    j2=0;
                }
                if(k2==10){
                    k2=0;
                }
                if(pass[i2][j2][k2][l]==step-1){
                    result[m][0]=i2;
                    result[m][1]=j2;
                    result[m][2]=k2;
                    result[m][3]=l;
                    i=i2;j=j2;k=k2;
                    d=8;
                    step--;
                }
                break;
            case 2:
                l2=l+1;j2=j+1;k2=k+1;
                if(l2==10){
                    l2=0;
                }
                if(j2==10){
                    j2=0;
                }
                if(k2==10){
                    k2=0;
                }
                if(pass[i][j2][k2][l2]==step-1){
                    result[m][0]=i;
                    result[m][1]=j2;
                    result[m][2]=k2;
                    result[m][3]=l2;
                    j=j2;k=k2;l=l2;
                    d=8;
                    step--;
                }
                break;
            case 3:
                k2=k+1;l2=l+1;
                if(k2==10){
                    k2=0;
                }
                if(l2==10){
                    l2=0;
                }
                if(pass[i][j][k2][l2]==step-1){
                    result[m][0]=i;
                    result[m][1]=j;
                    result[m][2]=k2;
                    result[m][3]=l2;
                    k=k2;l=l2;
                    d=8;
                    step--;
                }
                break;
            case 4:
                i2=i-1;j2=j-1;
                if(i2==-1){
                    i2=9;
                }
                if(j2==-1){
                    j2=9;
                }
                if(pass[i2][j2][k][l]==step-1){
                    result[m][0]=i2;
                    result[m][1]=j2;
                    result[m][2]=k;
                    result[m][3]=l;
                    i=i2;j=j2;
                    d=8;
                    step--;
                }
                break;
            case 5:
                i2=i-1;j2=j-1;k2=k-1;
                if(i2==-1){
                    i2=9;
                }
                if(j2==-1){
                    j2=9;
                }
                if(k2==-1){
                    k2=9;
                }
                if(pass[i2][j2][k2][l]==step-1){
                    result[m][0]=i2;
                    result[m][1]=j2;
                    result[m][2]=k2;
                    result[m][3]=l;
                    i=i2;j=j2;k=k2;
                    d=8;
                    step--;
                }
                break;
            case 6:
                l2=l-1;j2=j-1;k2=k-1;
                if(l2==-1){
                    l2=9;
                }
                if(j2==-1){
                    j2=9;
                }
                if(k2==-1){
                    k2=9;
                }
                if(pass[i][j2][k2][l2]==step-1){
                    result[m][0]=i;
                    result[m][1]=j2;
                    result[m][2]=k2;
                    result[m][3]=l2;
                    j=j2;k=k2;l=l2;
                    d=8;
                    step--;
                }
                break;
            case 7:
                k2=k-1;l2=l-1;
                if(k2==-1){
                    k2=9;
                }
                if(l2==-1){
                    l2=9;
                }
                if(pass[i][j][k2][l2]==step-1){
                    result[m][0]=i;
                    result[m][1]=j;
                    result[m][2]=k2;
                    result[m][3]=l2;
                    k=k2;l=l2;
                    d=8;
                    step--;
                }
                break;
            default:
                break;
            }
            d++;
        }
    }
    for(i=count-1;i>=0;i--){
        fprintf(fptr2,"%d%d%d%d\n",result[i][0],result[i][1],result[i][2],result[i][3]);
    }
    
    fclose(fptr);
    return 0;
}
