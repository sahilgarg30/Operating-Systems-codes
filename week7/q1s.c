#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>

#define MAX_TEXT 100

struct my_msg_st{
	long int my_msg_type;
	char text[BUFSIZ];
};

int main(){
	int running = 1;
	int msgid;
	struct my_msg_st data;
	char buffer[BUFSIZ];
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1){
		fprintf(stderr,"msgget failed with error :%d\n",errno);
		exit(EXIT_FAILURE);
	}
	printf("Enter the number -\n");
	fgets(buffer,BUFSIZ,stdin);
	data.my_msg_type = 1;
	strcpy(data.text,buffer);
	if(msgsnd(msgid,(void *)&data,MAX_TEXT,0)==-1){
		fprintf(stderr, "msgsnd failed\n");
		exit(1);
	}
	exit(0);
}