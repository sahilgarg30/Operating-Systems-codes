#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *thread_code(void *param){
	int* arr = (int *)param;
	int sum = 0;
	for(int i=0;arr[i]>0;i++)
		sum += arr[i];
	return (void *)sum;
}

int main(){
	int arr[100],sum;
	int i=0,inp=1;
	while(inp > 0){
		scanf("%d",&inp);
		arr[i++]=inp;
	}
	pthread_t thread;
	pthread_create(&thread,0,&thread_code,(void*)arr);
	pthread_join(thread,(void **)&sum);
	printf("The sum is - %d.\n",sum);
	return 0;
}