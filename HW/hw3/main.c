#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

volatile int num=0;

void *add(){
	for(int i=0;i<10;i++){
		num+=1;
	}
}

void *sub(){ 
	for(int i=0;i<10;i++){
		num-=1;
	}
}

int main(int argc, char* argv[]){
	pthread_t tid[10000];
	int thr_id; 
	for(int i=0;i<30;i++){
		num=atoi(argv[1]); 
		for(int j=0;j<5000;j++){ 
			thr_id= pthread_create(&tid[j], NULL, add, NULL);
			if(thr_id<0){
				perror("thread create error : ");
				exit(0);
			}
			
			thr_id= pthread_create(&tid[j+5000], NULL, sub, NULL);
			if(thr_id<0){
				perror("thread create error : ");
				exit(0);
			}
		}
		for(int j=0;j<10000;j++){ 
			pthread_join(tid[j],NULL);
		}
		printf(" %d\n",num);
	}
	return 0;
}
