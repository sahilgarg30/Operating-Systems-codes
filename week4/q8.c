#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	char buff[1024],filename[100];
	printf("Enter filename - \n");
	gets(filename);
	int fh1 = open(filename, O_RDONLY);
	read(fh1, buff, 1024);
	close(fh1);

	int ch = 0, word = 0, line = 0;
	for (int i = 0; i < strlen(buff); i++) {
		if (buff[i] == ' ') {
			word++;
		} else if (buff[i] == '\n') {
			line++;
			word++;
		}
		ch++;
	}
	printf("The number of lines words and char are - %d, %d and %d.\n", line, word, ch);
}