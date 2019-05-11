#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fh = creat("file1.txt", O_RDWR|777); // second parameter can be - 0_RDWR | S_IRWXO | S_IRWXU | S_IRWXG
	if(fh<0){printf("Error.\n");return 0;}
	char buff[256];
	gets(buff);
	write(fh, buff, strlen(buff));
	close(fh);
}