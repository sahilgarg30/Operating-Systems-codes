#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *thread_code(void *param){
	int no = (int)param;
	int isPrime = 1;
	if(no == 2) isPrime = 1;
	else{
		for(int i=2;i<=no/2;i++)
			if(no % i == 0){
				isPrime = 0;
				break; 
			}
	}
	return (void *)isPrime;
}

int main(){
	int a,b,primes[100];
	scanf("%d %d",&a,&b);
	pthread_t thread[100];
	for(int i=a;i<=b;i++){
		pthread_create(&thread[i-a],0,&thread_code,(void*)i);
		pthread_join(thread[i-a],(void **)&primes[i-a]);
	}
	printf("The prime numbers are - \n");
	for(int i=a;i<=b;i++){
		if(primes[i-a]) printf("%d ",i);
	}
	return 0;
}