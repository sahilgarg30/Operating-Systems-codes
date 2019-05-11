#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
	int status;
	pid_t pid;
	pid = fork();
	if(pid==-1){printf("Error"); return;}

	if(pid==0){
		printf("child");
		exit(0);
	}else{
		wait(&status);
		printf("\nParent \nChild returned - %d\n",status);
	}
}