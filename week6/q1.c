#include <stdio.h>
#include <stdlib.h>
int arr[100],time[100],priority[100];
int n;
int order[100];
void sortArrival(){
	for(int i=0;i<n;i++) order[i]=i;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[order[j+1]]<arr[order[j]]){
				int temp = order[j];
				order[j] = order[j+1];
				order[j+1] = temp;
			}
		}
	}
}

void printAvgWaitAndTAT(int waiting[]){
	printf("Process     Waiting times      turnaround time - \n");
	double wtsum=0,turnaroundsum=0;
	for(int i=0;i<n;i++){
		printf("Process %d -      %d                  %d\n",i+1,waiting[i],time[i]+waiting[i]);
		wtsum += waiting[i];
		turnaroundsum += waiting[i]+time[i];
	}
	printf("Waiting time average - %f\n",(double)wtsum/n);
	printf("turnaround time average %f\n",(double)turnaroundsum/n);
}

void fcfs(){
	sortArrival();
	int endtime[100],curtime=0;
	printf("Gantt chart is (start time and process)-\n");
	for(int i=0;i<n;i++){
		endtime[order[i]] = curtime+time[order[i]];
		printf("%d Process - %d\n",curtime,order[i]+1);
		curtime = endtime[i];
	}
	printf("End time - %d\n",curtime);

	printf("Process     Waiting times      turnaround time - \n");
	double wtsum=0,turnaroundsum=0;
	for(int i=0;i<n;i++){
		printf("Process %d -      %d                  %d\n",i+1,endtime[i]-arr[i]-time[i],endtime[i]-arr[i]);
		wtsum += endtime[i]-arr[i]-time[i];
		turnaroundsum += endtime[i]-arr[i];
	}
	printf("Waiting time average - %f\n",(double)wtsum/n);
	printf("turnaround time average %f\n",(double)turnaroundsum/n);
}

void srtf(){
	int timeLeft[100];
	int waiting[100];
	for(int i=0;i<n;i++){
		timeLeft[i] = time[i];
		waiting[i]=0;
	}
	int complete = 0,t=0,shortest = -1,prevshortest = -1,minm = 999999;
	int check = 0;

	printf("Gantt chart is - \n");
	while(complete != n){
		for(int i=0;i<n;i++){
			if(t >= arr[i]){
				if(timeLeft[i]>0 && timeLeft[i]<minm){
					minm = timeLeft[i];
					shortest = i;
					check = 1;
				}else if(timeLeft[i]>0 && timeLeft[i]==minm && priority[i]>priority[shortest]){
					minm = timeLeft[i];
					shortest = i;
					check = 1;
				}
			}
		}
		if(check ==0){
			t++;
			continue;
		}

		timeLeft[shortest]--;
		minm = timeLeft[shortest];
		if(timeLeft[shortest]==0){ 
			complete++;
			minm = 999999;
			check = 0;
		}

		if(shortest != prevshortest){
			printf("%d Process - %d\n",t,shortest+1);
		}
		prevshortest = shortest;
		for(int i=0;i<n;i++){
			if(t>=arr[i] && timeLeft[i]>0 && i != shortest)
				waiting[i]++;
		}
		t++;
	}
	printf("End time -  %d\n",t);
	printAvgWaitAndTAT(waiting);
}

void roundRobin(int quantum){
	sortArrival();
	int timeLeft[100];
	int waiting[100];
	for(int i=0;i<n;i++){
		timeLeft[i] = time[i];
		waiting[i]=0;
	}
	int f=0,r=n;
	int t=0;
	printf("Gantt chart is - \n");

	while(f<r){
		while(t < arr[order[f]]) t++;
		int process = order[f++];
		int timeTaken = 0;
		printf("%d Process - %d\n",t,process+1);
		if(timeLeft[process]<=quantum){
			t+=timeLeft[process];
			timeTaken = timeLeft[process];
			timeLeft[process] = 0;
		}else{
			t+=quantum;
			timeTaken = quantum;
			timeLeft[process] -= quantum;
			order[r++] = process;
		}

		for(int i=0;i<n;i++){
			if(i != process && arr[i]<=t && timeLeft[i]>0){
				if(t-arr[i]>=timeTaken)
					waiting[i]+=timeTaken;
				else
					waiting[i]+=t-arr[i];
			}
		}
	}

	printf("End time -  %d\n",t);
	printAvgWaitAndTAT(waiting);
}

int main(){
	printf("Enter number of processes - \n");
	scanf("%d",&n);
	printf("Enter arrival time, burst time and priority - \n");
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&arr[i],&time[i],&priority[i]);
	}

	fcfs();
	//roundRobin(10);
	//srtf();
}