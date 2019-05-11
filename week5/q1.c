#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int arr[100];
void *thread_code(void *param){
	int n = (int)param;
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<n;i++)
		arr[i] = arr[i-1]+arr[i-2];
}

int main(int argv,char* argc[]){
	int n = atoi(argc[1]);
	pthread_t thread;
	pthread_create(&thread,0,&thread_code,(void*)n);
	pthread_join(thread,0);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}