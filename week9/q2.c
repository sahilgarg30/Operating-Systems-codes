#include <stdio.h>
int n,m;
int alloc[100][100],request[100][100],available[100];

void detectionalgo(){
	int work[100],finish[100];
	for(int i=0;i<m;i++) work[i] = available[i];
	for(int i=0;i<n;i++){
		int j=0;
		for(j=0;j<m;j++) if(alloc[i][j]!=0) break;
		if(j==m) finish[i] = 1;
		else finish[i] = 0;
	}

	printf("Safe state execution order is - \n");
	int change = 1;
	while(change){
	change = 0;
	for(int i=0;i<n;i++){
		if(!finish[i]){
			int j;
			for(j=0;j<m;j++){
				if(request[i][j] > work[j])
					break;
			}
			if(j==m){
				change = 1;
				finish[i] = 1;
				printf("P%d  ",i+1);
				for(int k=0;k<m;k++) work[k] += alloc[i][k];			
			}		
		}	
	}}
	int i;
	for(i=0;i<n;i++){
		if(!finish[i]) break;
	}
	if(i==n) printf("\nSystem is in safe state.\n");
	else printf("System is not in safe state.");
}

int main(){
	
	printf("Enter the number of processes and resources - \n");
	scanf("%d %d",&n,&m);
	printf("Enter the allocation matrix - \n");
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);
	printf("Enter the REQUEST matrix - \n");
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&request[i][j]);
	printf("Enter the available vector - \n");
	for(int i=0;i<m;i++) scanf("%d",&available[i]);

	detectionalgo();
	return 0;
}
