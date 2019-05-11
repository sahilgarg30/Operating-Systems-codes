#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n;
void *thread_code1(void *param){
	int* arr = (int *)param;
	int sum = 0;
	for(int i=0;i<n;i++)
		if(arr[i]%2 ==0) sum += arr[i];
	return (void *)sum;
}

void *thread_code2(void *param){
	int* arr = (int *)param;
	int sum = 0;
	for(int i=0;i<n;i++)
		if(arr[i]%2 != 0) sum += arr[i];
	return (void *)sum;
}

int main(){
	int arr[100],sum1,sum2;
	printf("Enter no of elements - \n");
	scanf("%d",&n);
	printf("Enter the array - \n");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	pthread_t thread1,thread2;
	pthread_create(&thread1,0,&thread_code1,(void*)arr);
	pthread_join(thread1,(void **)&sum1);
	pthread_create(&thread2,0,&thread_code2,(void*)arr);
	pthread_join(thread2,(void **)&sum2);
	printf("The sum of even numbers is - %d.\n",sum1);
	printf("The sum of odd numbers is - %d.\n",sum2);
	return 0;
}