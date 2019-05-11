#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	char buff[256];
	int fh1 = open("file1.txt", O_RDONLY);
	if(fh1<0){printf("Error in file1\n");return 0;}
	int fh2 = creat("file2.txt", O_RDWR|777);
	if(fh2<0){printf("Error in file2\n");return 0;}
	int check=1;
	while(check){
		check = read(fh1, buff, 256);
		write(fh2, buff,check);
	}
	close(fh1);
	close(fh2);
}