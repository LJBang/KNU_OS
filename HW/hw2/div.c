#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int a=atoi(argv[1]), b=atoi(argv[2]);

 	int n=a/b;
	int m=a%b;

	printf("%d %d \n",n,m); 

	return 0;
}
