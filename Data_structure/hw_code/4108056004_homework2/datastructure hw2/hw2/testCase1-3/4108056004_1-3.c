#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fptr;

int a[1000];
int ans[1000][100]={1};
int ans_i=0,ans_j=0;

void f(int n,int r,int m) {     //�ƦC�զX 
	int i,j=0;

	if (n<r) return ;

	if (r==0) {
		for (i=0; i<m; i++){
		
			//printf("%d", a[i]);
			ans[ans_i][ans_j]=a[i];
			//printf("%d",ans[ans_i][ans_j]);
			ans_j++;
		}
		ans_j=0;
		ans_i++;
		//printf("\n");
	} else {
	
		a[m] = n;
		f(n-1, r-1, m+1);
	
		f(n-1, r, m);
	}
}

int main(){
	
	int i,j,k,l;
	fptr=fopen("test1.txt","r");                            //�Щ�o��ק��ɦW 
	if(fptr==NULL){
		printf("test1.txt open fail.\n");
		exit(0);
	}
	char num[100];
	int m=0,n=0;
	fscanf(fptr,"%d %d",&m,&n);
	if(m>=21||m<=1||n>=m){
		printf("input num fault!\n");
		exit(0);
	}
	int tempm=m;
	int tempn=n;
	long int mm=1;
	long int nn=1;
	int mn=n;
	
	while(mn>0){
		mm*=m;
		m--;
		mn--;
	}
	while(n>0){
		nn*=n;
		n--;
	}
	m=tempm;
	n=tempn;
	int totaltime=mm/nn;
	
	//printf("%d %d %d\n",m,n,totaltime);
	f(m,n,0);
	
	int con=0;
	char ch;
	char condition[1000]={};
	char totalcondition[100][1000]={};
	while(!feof(fptr)){
		fgets(condition,1000,fptr);
		//printf("%s %d\n",condition,strlen(condition));
		if(condition[strlen(condition)-1]=='\n'){
			for(i=0;i<strlen(condition)-1;i++){
				totalcondition[con][i]=condition[i];
			}
		}else{
			for(i=0;i<strlen(condition);i++){
				totalcondition[con][i]=condition[i];
			}
		}
		con++;
	}												//�N�Ҧ�condition���Hstring�覡�O�U 
	int strlong[con];
	for(i=0;i<con;i++){
		//printf("%s %d\n",totalcondition[i],strlen(totalcondition[i]));
		strlong[i]=strlen(totalcondition[i]);
		//printf("%d\n",strlong[i]);          //check all conditions
	}
	//printf("%d\n",strlong[0]);
	int liers[n];
	
														//�٨S�o�{�O���̥��~�Atotalcondition�O�q�}�C1�}�l��J���H �������� 
														
														
	/////////////////////////////////////�}�l�@�ӭӥνa�|�覡�ˬd														
	for(i=0;i<totaltime;i++){
		int alltf[m];
		for(j=0;j<m;j++){						//���]�@�Ӧ@m����ư}�C  �åH1�N��u�� 
			alltf[j]=1;
		}
		for(j=0;j<n;j++){						//���]�������]0 
			alltf[ans[i][j]-1]=0;
		}
		//printf("falls num:%d %d %d\n",ans[i][0]-1,ans[i][1]-1,ans[i][2]-1);
		char innum[2]={0};
		
		
		
		int inn=0;
		int fail=0;
		for(j=0;j<con-1;j++){
			int allf=0;
			
			for(k=0;k<strlong[j+1];k++){
				if(totalcondition[j+1][k]>='0'&&totalcondition[j+1][k]<='9'){
					if(inn==0){
						innum[inn]=totalcondition[j+1][k];
						inn++;
					}else{							//�קK�Q��ƪ��p 
						innum[inn]=totalcondition[j+1][k];
						inn++;
					}
				}else{
					int correctnum=0;
					{                                    
						if(inn==1){
							correctnum=(int)innum[0]-48;
							//printf("%d\n",correctnum);
												
							if(alltf[correctnum]==0){
								allf++;
							}
							
						}else{
							correctnum=(int)(innum[0]-48)*10+(int)innum[1]-48;
							
							if(alltf[correctnum]==0){
								allf++;
							}
						}
						innum[0]=0;
						innum[1]=0;
						inn=0;
					
					}
				}
			}
			//printf("allf:%d\n",allf);

			int endtf=2;
			//printf("%c",totalcondition[j+1][strlong[j+1]-1]);
			if(totalcondition[j+1][strlong[j+1]-1]=='T'){
				endtf=1;
			}else{
				endtf=0;
			}
			
			
			//printf("%d %d\n",allf,endtf);
			if(allf%2==0&&endtf==0) {
				fail=1; //printf("fail\n");
			}
			if(allf%2==1&&endtf==1) {
				fail=1; //printf("fail\n");
			}
		}
		if(fail==0){
			for(j=0;j<n;j++){
				liers[j]=ans[i][j]-1;
			}break;						//�Y�L�~�N���X 
		}else{
			fail=0;
		}
		//////////////////////�����t��k----�Y�`��������(�H��)�����ƭӫh���G��T�A�Ϥ���L(�[�� ((�t�t�o������? 
	}
	printf("liers:");
		for(i=0;i<n;i++){
			printf("%d ",liers[i]);
		}
		printf("\n");
	
	
	
	system("pause");
	return 0;
}
