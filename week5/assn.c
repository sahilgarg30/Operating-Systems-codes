#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int n;
	scanf("%d",&n);
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("Error\n");
		return 1;
	}else if(pid == 0){
		int x = n;
		int ans = 10;
		while(x>0){
			int dig = x%10;
			if(dig<ans) ans = dig;
			x = x/10;
		}
		printf("Minimum digit - %d\n",ans);
		exit(0);
	}else{
		int x = n;
		int ans = -1;
		while(x>0){
			int dig = x%10;
			if(dig>ans) ans = dig;
			x = x/10;
		}
		printf("Maximum digit - %d\n",ans);
	}
	return 0;
}