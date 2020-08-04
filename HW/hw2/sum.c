#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int a=0, b=0;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	
	printf("%d \n", a+b);

	return 0;
}
