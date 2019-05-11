#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct proc{
	int pid,arr_time,b_time,level;
}proc;

int compare(const void* p,const void* q){
	proc *a,*b;
	a = (proc *)p;
	b = (proc *)q;
	if(a->arr_time == b->arr_time)
		return a->level - b->level;
	return a->arr_time - b->arr_time;
}

int compare2(const void* p,const void *q){
	proc *a,*b;
	a = (proc *)p;
	b = (proc *)q;
	if(a->b_time == b->b_time)
		return a->level - b->level;
	return a->b_time - b->b_time;
}

int main(){
	int njobs;
	scanf("%d",&njobs);
	printf("%d\n",njobs);
	int i=0;
	proc procs[njobs];
	for(i=0;i<njobs;i++)
		scanf("%d %d %d %d",&procs[i].pid,&procs[i].arr_time,&procs[i].b_time,&procs[i].level);
	qsort((void *)procs,sizeof(procs)/sizeof(proc),sizeof(proc),compare);
	proc arrived[njobs];
	int acount=0;
	int time=procs[0].arr_time;
	int count = njobs;
	int start,end;
	start = procs[0].arr_time;
	arrived[0] = procs[0];
	acount++;
	proc curr = arrived[0];
	start = curr.arr_time;
	int pos = 1;
	while(count){
		while(time>=procs[pos].arr_time && pos<njobs)
			arrived[acount++] = procs[pos++];
		qsort((void *)arrived,acount,sizeof(proc),compare2);
		if(curr.pid != arrived[0].pid){
			printf("pid = %d start = %d end = %d\n",curr.pid,start,time);
			start = time+1;
			curr = arrived[0];
		}
		curr.b_time--;
		time++;
		if(curr.b_time <= 0){
			int temp = acount-1;
			i=0;
			while(i<temp){
				arrived[i] = arrived[i+1];
				i++;
			}
			printf("pid = %d start = %d end = %d\n",curr.pid,start,time);
			start = time+1;
			count--;
			acount--;
			curr = arrived[0];
		}
		else
			arrived[0] = curr;
	}
}
