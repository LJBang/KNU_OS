#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int num=0;

pthread_mutex_t mutex;

int swap(int k){ //전역변수가 쉽게 깨질 수 있도록
	int tmp;
	for(int i=0;i<10000;i++){
		tmp=k;
		k=tmp;
	}
	return k;
}

void *add(){
	pthread_mutex_lock(&mutex);
	for(int i=0;i<10;i++){
		num+=1;
		num=swap(num);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

void *sub(){ 
	pthread_mutex_lock(&mutex);
	for(int i=0;i<10;i++){
		num-=1;
		num= swap(num);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

int main(int argc, char* argv[]){
	pthread_t t_add[5000], t_sub[5000];
	int thr_id;
	pthread_mutex_init(&mutex,NULL);

	for(int i=0;i<30;i++){
		num=atoi(argv[1]); 
		for(int j=0;j<5;j++){ 
			thr_id = pthread_create(&t_add[j], NULL, add, NULL);
			thr_id= pthread_create(&t_sub[j], NULL, sub, NULL);
		}
		for(int j=0;j<5;j++){ 
			thr_id=pthread_join(t_add[j],NULL);
			thr_id=pthread_join(t_sub[j],NULL);
		}
		printf(" %d\n",num);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
