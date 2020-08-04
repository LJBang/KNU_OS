#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){

	pid_t pid;

	printf("=========shell=========\n");
	char input[128];
	char* a;
	char* b;
	while(1){
		fgets(input,128,stdin);
		char* ptr = strtok(input," ");
	
		pid=fork();
		if(pid==0){
			if(!strcmp(ptr,"sum")){
				a= strtok(NULL," ");
				b= strtok(NULL," ");
				execl("sum","sum", a, b,NULL);
			}
			else if(!strcmp(ptr,"sub")){
				a=strtok(NULL," ");
				b=strtok(NULL," ");
				execl("sub","sub", a, b,NULL);
			}
			else if(!strcmp(ptr,"fact")){
				a=strtok(NULL," ");
				b=strtok(NULL," ");
				execl("fact","fact", a,NULL);
			}
			else if(!strcmp(ptr,"div")){
				a=strtok(NULL," ");
				b=strtok(NULL," ");
				execl("div","div", a, b,NULL);
			}
		}
	}

	return 0;
}
