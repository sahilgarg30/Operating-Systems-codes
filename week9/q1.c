#include <stdio.h>
int n,m;
int alloc[100][100],max[100][100],available[100];

void bankers(){
	int work[100],finish[100];
	for(int i=0;i<m;i++) work[i] = available[i];
	for(int i=0;i<n;i++) finish[i] = 0;

	printf("Safe state execution order is - \n");
	int change = 1;
	while(change){
	change = 0;
	for(int i=0;i<n;i++){
		if(!finish[i]){
			int j;
			for(j=0;j<m;j++){
				if(max[i][j]-alloc[i][j] > work[j])
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
	printf("Enter the MAX matrix - \n");
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&max[i][j]);
	printf("Enter the available vector - \n");
	for(int i=0;i<m;i++) scanf("%d",&available[i]);

	bankers();
	printf("\nEnter special request - (Y/N) - \n");
	char c; scanf("%c",&c);
	scanf("%c",&c);
	if(c=='y' || c=='Y'){
		printf("Enter process that requests - \n");
		int p;
		scanf("%d",&p);
		p--;
		printf("Enter the request - \n");
		int request[100],i;
		for(i=0;i<m;i++) scanf("%d",&request[i]);	
		for(i=0;i<m;i++){if(request[i]<=available[i] && request[i]<=(max[p][i]-alloc[p][i])) continue; else break;}
		if(i==m){
			for(int j=0;j<m;j++){
				available[j] -= request[j];
				alloc[p][j] += request[j];
			}
			bankers();
		}else printf("Request cant be granted - no resource available/exceeds max.");
	}
	return 0;
}
