#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	execlp("/usr/bin/wc", "wc", "-l","-w","-c","q2.c",NULL);
}