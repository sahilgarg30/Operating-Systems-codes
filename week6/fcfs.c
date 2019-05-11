#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int pid[],int arrival[],int burst[],int priority[],int jobs){
    int i=0,j;
    for(i=0;i<(jobs-1);i++){
         for(j=(i+1);j<jobs;j++){
            if(arrival[i]>arrival[j] || (arrival[i]==arrival[j] && priority[i]>priority[j])){
                swap(arrival+i,arrival+j);
                swap(pid+i,pid+j);
                swap(priority+i,priority+j);
                swap(burst+i,burst+j);
            }
         }
    }    
}

int main(){
    int njobs;
    scanf("%d",&njobs);
    int pid[njobs],arrival[njobs],burst[njobs],priority[njobs];
    int i=0,time=0;
    for(i=0;i<njobs;i++)
        scanf("%d %d %d %d",pid+i,arrival+i,burst+i,priority+i);
    sort(pid,arrival,burst,priority,njobs);
    for(i=0;i<njobs;i++){
        time = time>arrival[i]?time:arrival[i];
        time += burst[i]-1;
        printf("%d %d %d\n",time-burst[i]+1,time,pid[i]);
        time++;
    }
    return 0;
}
