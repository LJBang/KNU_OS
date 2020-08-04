#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int a=atoi(argv[1]);
	int fact=1;
	for(int i=a;i>1;i--){
		fact *= a;
		a--;
	}
	printf("%d \n", fact);
	return 0;
} 
