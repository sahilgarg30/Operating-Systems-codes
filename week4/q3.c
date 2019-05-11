#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
	pid_t pid,c_id=0;
	pid = fork();
	c_id = pid;
	if(pid==-1){printf("Error"); return;}

	if(pid==0){
		printf("\nChild :\n");
		printf("process pid - %d\n",getpid());
		printf("parent process pid - %d\n",getppid());
		printf("child process pid - %d\n",c_id);
		exit(0);
	}else{
		wait(NULL);
		printf("\nParent :\n");
		printf("process pid - %d\n",getpid());
		printf("parent process pid - %d\n",getppid());
		printf("child process pid - %d\n",c_id);
	}
}