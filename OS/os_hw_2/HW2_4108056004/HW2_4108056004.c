#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
int find;
void loopread(char* start, char* target, char *tmpname){
	//printf("start: %s\n",start);
	// printf("%d\n",count);
	DIR *pDir = opendir(start);
	if(pDir != NULL){
		struct dirent* pEntry = NULL;
		while((pEntry = readdir(pDir)) != NULL){
			// printf("%s\n", pEntry->d_name);
			if(strcmp(pEntry->d_name,".") && strcmp(pEntry->d_name,"..") && pEntry->d_type != DT_LNK){
				if(pEntry->d_type == DT_DIR){
					//printf("dir:%s\n",pEntry->d_name);
					char dirname[500];
					strcpy(dirname, tmpname);
					strcat(dirname, pEntry->d_name);
					strcat(dirname, "/");
					//printf("dir:%s\n",dirname);
					loopread(dirname, target, dirname);
				}else{
					if(!strcmp(pEntry->d_name,target)){
						char name[500];
						strcpy(name, tmpname);
						strcat(name, target);
						printf("%s\n",name);
						find = 1;
					}
				}
			}
		}
	}
	closedir(pDir);
}
int main(int argc, char* argv[]){
	char target[100];
	char start[100];
	char tmpname[500];
	find = 0;
	if(argc==2){
		strcpy(start, ".");
		printf("start: %s\n",start);
		strcat(start, "/");
		strcpy(target, argv[1]);
	}else if(argc==3){
		strcpy(start, argv[1]);
		printf("start: %s\n",start);
		strcpy(target, argv[2]);
	}else{
		printf("input not correct\n");
		return 0;
	}
	strcpy(tmpname, start);
	printf("target: %s\n",target);
	loopread(start, target, tmpname);
	if(find == 0){
		printf("cannot find the corresponding file\n");
	}
	//printf("target: %s\n",*target);
	return 0;
}


