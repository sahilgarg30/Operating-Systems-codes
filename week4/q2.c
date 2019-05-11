#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
	pid_t pid;
	pid = fork();
	if(pid==-1){printf("Error"); return;}

	if(pid==0){
		printf("\nChild process\n");
		execlp("/home/Student/sahilgarg/week4/q1", "q1", NULL);
		exit(0);
	}else{
		wait(NULL);
		printf("\nParent completed.");
	}
}