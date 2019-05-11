#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int readcount = 0;
sem_t mutex,wrt;
void *writer(void *arg){
	//do{
	sem_wait(&wrt);
	printf("Writer.\n");
	sleep(1);
	sem_post(&wrt);
	//}while(1);
}

void *reader(void *arg){
	//do{
		sem_wait(&mutex);
		readcount++;
		if(readcount==1) sem_wait(&wrt);
		sem_post(&mutex);

		printf("Reader - %d\n",readcount);
		sleep(1);
		sem_wait(&mutex);
		printf("Reader done - %d\n",readcount);
		readcount--;
		if(readcount == 0) sem_post(&wrt);
		sem_post(&mutex);

	//}while(1);
}

int main(){
	pthread_t tid1,tid2,tid3,tid4,tid5;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_create(&tid1,NULL,reader,NULL);
	pthread_create(&tid2,NULL,writer,NULL);
	pthread_create(&tid3,NULL,reader,NULL);
	pthread_create(&tid4,NULL,writer,NULL);
	pthread_create(&tid5,NULL,reader,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	return 0;
}