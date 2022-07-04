#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 200

FILE *opfile;
FILE *srcfile;
FILE *objectfile;
typedef struct operation operation;
struct operation{
	char op_name[10];
	char op_value[10];
};
struct operation* optable[MAX];

typedef struct source source;
struct source{
	char label[10];
	char op[10];
	char mem[10];
	char code[10];
	char locsix[10];
	long int loc;
	int nextloc;
};
struct source* srctable[MAX];

typedef struct sym sym;
struct sym{
	char label[10];
	char address[10];
};
struct sym* symtable[MAX];

bool isachar(char ch){
	return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}

int sixteentoten(char ch){
	switch (ch){
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			return (int)ch-48;
	}
}	
char tentosixteen(int tts){
	switch (tts){
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		default:
			return (char)tts+48;
	}
}


int main(){
	opfile = fopen("opcode.txt","r");
	if(opfile==NULL){
		printf("Open opcode.txt fail.\n");
		exit(0);
	}
	for(int i=0;i<MAX;i++){
		optable[i]=(operation*)malloc(sizeof(operation));
	}
	for(int i=0;i<MAX;i++){
		strcpy(optable[i]->op_name,"");
		strcpy(optable[i]->op_value,"");
	}
	char ch;
	char line[100];
	
	int o=0;					//o:total optable num
	char str[20]={0};
	int i,j,k;
	
	while(fgets(line, sizeof(line), opfile) != NULL){
		i=0; 
    	while(line[i]!=' '){
    		str[i]=line[i];
    		i++;
		}
		for(j=0;j<o;j++){				//chech error
			if(!strcmp(optable[j]->op_name,str)){
				printf("Duplicate Symbol Error!\n");
				exit(0);
			}
		}
	    strcpy(optable[o]->op_name,str);
	    memset(str,0,sizeof(str));
	    i++;
	    k=0;
	    while(line[i]!='\n'){
    		str[k]=line[i];
    		i++; k++;
		}
		strcpy(optable[o]->op_value,str);
		memset(str,0,sizeof(str));
		o++;
	}
//	for(i=0;i<o;i++){
//		printf("%s %s",optable[i]->op_name,optable[i]->op_value);
//		printf("\n");
//	}
	////////////////////////
	srcfile = fopen("source.txt","r");
	if(srcfile==NULL){
		printf("Open source.txt fail.\n");
		exit(0);
	}
	for(i=0;i<MAX;i++){
		srctable[i]=(source*)malloc(sizeof(source));
	}
	for(i=0;i<MAX;i++){
		strcpy(srctable[i]->label,"");
		strcpy(srctable[i]->op,"");
		strcpy(srctable[i]->mem,"");
		strcpy(srctable[i]->code,"");
		strcpy(srctable[i]->locsix,"");
		srctable[i]->loc=0;
		srctable[i]->nextloc=0;
	}
	for(i=0;i<MAX;i++){
		symtable[i]=(sym*)malloc(sizeof(sym));
	}
	for(i=0;i<MAX;i++){
		strcpy(symtable[i]->label,"");
		strcpy(symtable[i]->address,"");
	}
	
	int s=0;		//s:total source code num
	int sy=0;		//sy:total stmtable
	
	while(fgets(line, sizeof(line), srcfile) != NULL){
		i=0;
		
    	while((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')){
    		str[i]=line[i];
    		i++;
		}
//		printf("1:%s ",str);
		strcpy(srctable[s]->label,str);
		memset(str,0,sizeof(str));
	    i++;	k=0;
	    while(!isachar(line[i])){
	    	i++;
		}
		
		while((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')){
    		str[k]=line[i];
    		i++;	k++;
		}
//		printf("2:%s!!!\n",str);
		strcpy(srctable[s]->op,str);
		memset(str,0,sizeof(str));
	    i++;	k=0;
	    while(line[i]==' '||line[i]=='	'){
	    	i++;
		}
		
		while(line[i]!='\n'){
    		str[k]=line[i];
    		i++;	k++;
		}
//		printf("3:%s ",str);
		strcpy(srctable[s]->mem,str);
		memset(str,0,sizeof(str));
//		printf("\n");
		s++;
	}
	///////////////////////////////////pass1-loc
	
	long int loc;
	char num_temp[10]={0};
	char program_name[10]={0};
	
	strcpy(program_name,srctable[0]->label);
	strcpy(num_temp,srctable[0]->mem);
	int l = strlen(num_temp);
	
	for(i=0;i<l;i++){
		int num=sixteentoten(num_temp[i]);
		loc += num*pow(16,l-i-1);
	}
	bool opexist;
	bool end=false;
	long int firstloc=loc;
	
	for(i=1;i<s;i++){
		srctable[i]->loc=loc;
		char sadd[6]={0};
		int t;
		int loc_t=loc;
		for(int a=0;a<6;a++){
			t=loc_t%16;
			sadd[5-a]=tentosixteen(t);
			loc_t=loc_t/16;
		}
		sadd[6]='\0';
		strcpy(srctable[i]->locsix,sadd);
		memset(sadd,0,sizeof(sadd));
		///////////////////////build symtable (use sy)
		if(strcmp("",srctable[i]->label)){
//			printf("%s: %ld: %s\n",srctable[i]->label,loc,add);
			strcpy(symtable[sy]->label,srctable[i]->label);
			strcpy(symtable[sy]->address,srctable[i]->locsix);
			sy++;
		}
		///////////////////////////////////////
		opexist=false;
		for(j=0;j<o&&!end;j++){
			if(!strcmp(optable[j]->op_name,srctable[i]->op)){
				opexist=true;
				break;
			}	
		}
		if(opexist){
			loc+=3;
		}else{
			if(!strcmp("WORD",srctable[i]->op)){
				loc+=3;
			}else if(!strcmp("BYTE",srctable[i]->op)){
				char tem=srctable[i]->mem[0];
				switch(tem){
					case 'C':
						loc+=3;
						break;
					case 'X':
						int b_len=strlen(srctable[i]->mem);
						b_len-=3;
						loc+=b_len/2;
						break;
				}
			}else if(!strcmp("RESW",srctable[i]->op)){
				int ll=strlen(srctable[i]->mem);
				int tt=0;
				for(int a=0;a<ll;a++){
					k=sixteentoten(srctable[i]->mem[a]);
					tt+=k*pow(10,ll-a-1);
				}
				loc+=tt*3;
			}else if(!strcmp("RESB",srctable[i]->op)){
				int ll=strlen(srctable[i]->mem);
				int tt=0;
				for(int a=0;a<ll;a++){
					k=sixteentoten(srctable[i]->mem[a]);
					tt+=k*pow(10,ll-a-1);
				}
				loc+=tt;
			}else if(!strcmp("END",srctable[i]->op)){
				end=true;
			}else{
				printf("%s\n",srctable[i]->op);
				printf("Undefined Symbol Errors!\n");		//set error flag
				exit(0);
			}
		}
	}
	
	//////////////////////////////pass2-obcode
	objectfile=fopen("object_program.txt","w");
	if(objectfile==NULL){
		printf("Open object_program.txt fail.\n");
		exit(0);
	}
	
	fputs("H",objectfile);
	fputs(program_name,objectfile);
	fputs(" ",objectfile);
	fputs(symtable[0]->address,objectfile);
	long int programlength = loc-firstloc;			//得到總長度並寫入第一行 
	char addpl[6];
	int tpl;
	for(int a=0;a<6;a++){
		tpl=programlength%16;
		addpl[5-a]=tentosixteen(tpl);
		programlength=programlength/16;
	}
	addpl[6]='\0';
	fputs(addpl,objectfile);
	fputs("\n",objectfile);
	
	char ob_code[6]={0};
	bool symexist;
	i=0;
	
	char textc[MAX]={0};
	int textl=0;
	char startlocsix[MAX]={0};
	bool space=true;
	
	while(strcmp(srctable[++i]->op,"END")){			//op=END結束 
		opexist=false;
		if(space){
			strcpy(startlocsix,srctable[i]->locsix);
			space=false;
		}
		for(j=0;j<o;j++){
			if(!strcmp(optable[j]->op_name,srctable[i]->op)){
				opexist=true;
				ob_code[0]=optable[j]->op_value[0];	ob_code[1]=optable[j]->op_value[1];
				symexist=false;
				for(k=0;k<sy;k++){
					if(!strcmp(symtable[k]->label,srctable[i]->mem)){
						ob_code[2]=symtable[k]->address[2];
						ob_code[3]=symtable[k]->address[3];
						ob_code[4]=symtable[k]->address[4];
						ob_code[5]=symtable[k]->address[5];
						symexist=true;
						break;
					}
				}
				int ml = strlen(srctable[i]->mem);
				if(srctable[i]->mem[ml-1]=='X'&&srctable[i]->mem[ml-2]==','){
					char mm[ml-2];
					for(int a=0;a<ml-2;a++){
						mm[a]=srctable[i]->mem[a];
					}
					for(k=0;k<sy;k++){
						if(!strcmp(symtable[k]->label,mm)){
							char x=symtable[k]->address[2];
							int xx=(int)x-48;
							xx+=8;
							char xxx=tentosixteen(xx);
							ob_code[2]=xxx;
							ob_code[3]=symtable[k]->address[3];
							ob_code[4]=symtable[k]->address[4];
							ob_code[5]=symtable[k]->address[5];
							symexist=true;
							break;
						}
					}
				}
				if(!symexist){
					ob_code[2]='0';
					ob_code[3]='0';
					ob_code[4]='0';
					ob_code[5]='0';
				}
				printf("%s!!\n",ob_code);
				strcpy(srctable[i]->code,ob_code);
				memset(ob_code,0,sizeof(ob_code));
				break;
			}
		}
		int wbl;
		if(!opexist){
			if(!strcmp("WORD",srctable[i]->op)){
				wbl=strlen(srctable[i]->mem);
				int loc_t=0;
				for(int b=0;b<wbl;b++){
					loc_t+=((int)(srctable[i]->mem[b])-48)*pow(10,wbl-b-1);
				}
				char addd[6]={0};
				int t;
				for(int a=0;a<6;a++){
					t=loc_t%16;
					addd[5-a]=tentosixteen(t);
					loc_t=loc_t/16;
				}
				addd[6]='\0';
				strcpy(srctable[i]->code,addd);
				memset(addd,0,sizeof(addd));
			}else if(!strcmp("BYTE",srctable[i]->op)){
				char tem=srctable[i]->mem[0];
				int cx;
				switch(tem){
					case 'C':
						wbl=strlen(srctable[i]->mem);
						cx=wbl-3;
						for(int a=0;a<cx;a++){
							int cinascii = (int)srctable[i]->mem[a+2];
							char asciiinsixteen[2]={0};
							int t;
							for(int aa=0;aa<2;aa++){
								t=cinascii%16;
								asciiinsixteen[1-aa]=tentosixteen(t);
								cinascii=cinascii/16;
							}
							asciiinsixteen[2]='\0';
							srctable[i]->code[a*2]= asciiinsixteen[0];	srctable[i]->code[a*2+1]= asciiinsixteen[1];
							memset(asciiinsixteen,0,sizeof(asciiinsixteen));
						}
						break;
					case 'X':
						wbl=strlen(srctable[i]->mem);
						cx=wbl-3;
						char xadd[2]={0};
						for(int a=0;a<cx;a++){
							xadd[a]=srctable[i]->mem[a+2];
						}
						xadd[2]='\0';
						strcpy(srctable[i]->code,xadd);
						memset(xadd,0,sizeof(xadd));
						break;
				}
			}else if(!strcmp("RESW",srctable[i]->op)||!strcmp("RESB",srctable[i]->op)){
			}
		}
	}
	for(i=0;i<sy;i++){
		printf("%s\n",symtable[i]->address);
	}
	fclose(objectfile);
	
	
}


