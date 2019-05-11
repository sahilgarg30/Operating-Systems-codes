#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
	pid_t pid;
	pid = fork();
	if(pid==-1){printf("Error"); return;}

	if(pid==0){
		printf("I'm the child! Pid: %d\n", getpid());
		printf("I'm the child! PPid: %d\n", getppid());
		sleep(5);
		exit(0);
	}else{
		sleep(40);
		printf("I'm the parent! Pid: %d\n", getpid());
	}
}