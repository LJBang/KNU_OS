#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char** argv){
	char buf[BUFSIZ];
	char i = 0;
	int fd = -1;
	char input, input2[2]={'3','\0'}, on[2]={'1','\0'}, off[2]={'0','\0'};

	scanf("%c", &input);
	if(input == 'A'){	// input A, filcker 3times
		printf("gpio set: flicker \n");
		fd =open("/dev/ledtest", O_RDWR);
		printf("fd: %d\n", fd);
		for(i=0;i<3;i++){
			write(fd, on, strlen(on), NULL);	// put str on to module
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 4, NULL);
			printf("read: %s \n", buf);
			usleep(500000);
			write(fd, off, strlen(off), NULL);	// put str off to module
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 4, NULL);
			printf("read: %s \n", buf);
			usleep(500000);
		}
	}
	else if(input=='B'){	// input B, input 0 is off, 1 is on
		printf("gpio set: command \n");
		scanf("%*c%c", &input);
		fd = open("/dev/ledtest", O_RDWR);
		printf("fd: %d\n", fd);
		if(input=='1'){
			write(fd, on, strlen(on), NULL);	// put str on to module
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 4, NULL);
			printf("read: %s \n",buf);
		}
		else if(input=='0'){
			write(fd, off, strlen(off), NULL);	// put str off to module
			memset(buf, 0 ,BUFSIZ);
			read(fd, buf, 4, NULL);
			printf("read: %s \n",buf);
		}
	}	
	close(fd);
}
