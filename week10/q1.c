#include <stdio.h>
int n;
int parts[100];

int firstFit(int size){
	for(int i=0;i<n;i++){
		if(parts[i]>=size){
			parts[i]-=size;
			return i;
		}
	}
	return -1;
}

int worstFit(int size){
	int maxsize = 0,index = -1;
	for(int i=0;i<n;i++) if(parts[i]>maxsize){
		maxsize = parts[i];
		index = i;
	}
	if(maxsize < size) index = -1;
	if(index != -1) parts[index]-=size;
	return index;
}

int bestFit(int size){
	int minsize = 99999,index = -1;
	for(int i=0;i<n;i++) if(parts[i]<minsize && parts[i]>=size){
		minsize = parts[i];
		index = i;
	}
	if(index != -1) parts[index]-=size;
	return index;
}

int main(){
	printf("Enter the number of partitions - \n");
	scanf("%d",&n);
	printf("Enter partition sizes in Kb - \n");
	for(int i=0;i<n;i++){
		scanf("%d",&parts[i]);
	}

	int size = 0;
	while(size != -1){
		printf("Enter process size (-1 to end)- \n");
		scanf("%d",&size);
		if(size==-1) break;
		int no = worstFit(size);
		if(no == -1) printf("No space for process.\n");
		else printf("Assigned in partition no - %d.\nNew partition size = %d.\n",no+1,parts[no]);
	}
	return 0;
}