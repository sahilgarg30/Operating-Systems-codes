#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int buf[10],f,r;
sem_t mutex,full,empty;
void *produce(void *arg){
	int i=1;
	while(1){
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("Produced item - %d\n",i);
		buf[(++r)%10]=i;
		i++;
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void *consume(void *arg){
	int item,i;
	while(1){
		sem_wait(&full);
		sem_wait(&mutex);
		item = buf[(++f)%10];
		printf("Consumed item - %d\n",item);
		sleep(1); 
		sem_post(&mutex);
		sem_post(&empty);
	}
}

int main(){
	pthread_t tid1,tid2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	pthread_create(&tid1,NULL,produce,NULL);
	pthread_create(&tid2,NULL,consume,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}