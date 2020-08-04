#include<stdio.h>
#include<stdlib.h>
volatile int num;
int main(int argc, char* argv[]){
	num = argv[1];

	return 0;
}
