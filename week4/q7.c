#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	execlp("/bin/ls", "ls", NULL);
}