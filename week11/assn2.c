#include <pthread.h>
#include <stdio.h>

int order[100];

void sortProcess(int n,int priority[]){
	for(int i=0;i<n;i++) order[i]=i;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(priority[order[j]]<priority[order[j+1]]){
				int temp = order[j];
				order[j] = order[j+1];
				order[j+1] = temp;
			}
		}
	}
}

void *printTAT(void *arg){
	int *TAT = (int *)arg;
	printf("Turn around time - %d \n",*TAT);
}

int main(){
	int n;
	int time[100],wait[100],priority[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&time[i],&priority[i]);
		wait[i]=0;
	}

	sortProcess(n,priority);
	pthread_t thread;
	for(int i=0;i<n;i++){
		int x = order[i];
		int t = time[x]+wait[x];
		pthread_create(&thread,0,&printTAT,(void *)&t);
		printf("Process %d - Wait time = %d \n",x,wait[x]);
		//printf("Turn around time - %d \n",t);
		pthread_join(thread,NULL);
		for(int i=0;i<n;i++) if(x!=i) wait[i]+=time[x];
	}
}