#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char** argv){
	char buf[BUFSIZ];
	char i = 0;
	int fd = -1;
	printf("gpio set\n");
	fd =open("/dev/ledtest", O_RDWR);
	printf("fd: %d\n", fd);
	
	while(1){	// by repitition, maintain the execution
		write(fd, 1, sizeof(int), NULL);
	}	
	close(fd);
}
