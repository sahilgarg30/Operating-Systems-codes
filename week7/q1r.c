#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	char text[BUFSIZ];
};

int isPal(char text[]){
	int len=0;
	for(len=0;text[len]!='\0';len++);
	len--;
	for(int i=0;i<=len/2;i++){
		if(text[i]!=text[len-i-1])
			return 0;
	}
	return 1;
}
int main(){
	int running = 1;
	int msgid;
	struct my_msg_st data;
	long int msg_to_receive = 0;
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1){
		fprintf(stderr,"msgget failed with error :%d\n",errno);
		exit(EXIT_FAILURE);
	}
	if(msgrcv(msgid,(void *)&data,BUFSIZ,msg_to_receive,0)==-1){
			fprintf(stderr, "msgrcv failed with error: %d\n",errno);
			exit(EXIT_FAILURE);
	}
	printf("The number is %s\n",data.text);
	if(isPal(data.text)){
		printf("It is a palindrome.\n");
	}else{
		printf("It is not a palindrome.\n");
	}
	if(msgctl(msgid,IPC_RMID,0)==-1){
		fprintf(stderr, "msgctl failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}