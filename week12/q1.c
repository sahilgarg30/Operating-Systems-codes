#include <stdio.h>
#include <stdlib.h>
int n,length;
int arr[100];
int cur;

int sort(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int fcfs(){
	int cyl = 0;
	 for(int i=0;i<n;i++){
	 	if(arr[i]>cur) cyl += arr[i]-cur;
	 	else cyl += cur-arr[i];
	 	cur = arr[i];
	 	printf("%d  ",cur);
	 }
	 return cyl;
}

int sstf(){
	int cyl = 0;
	for(int i=0;i<n;i++){
		int min = 999,index = -1;
		for(int j=0;j<n;j++){
			if(abs(cur-arr[j])<min){
				index = j;
				min = abs(cur-arr[j]);
			}
		}
		cyl += min;
		cur = arr[index];
		printf("%d  ",arr[index]);
		arr[index] = 99999;
	}
	return cyl;
}

int cscan(){
	sort(); int i,index,cyl=0;
	for(i=0;i<n;i++) if(arr[i]>=cur) break;
	index = i;
	if(index == n){
		cyl += length-cur;
		cur = 0;
		index = 0;
	}
	for(int i=index;;){
		if(arr[i]>cur) cyl += arr[i]-cur;
	 	else cyl += cur-arr[i];
	 	cur = arr[i];
		printf("%d  ",arr[i]);
		i = (i+1)%n;
		if(i==index) break;
		if(i==0){cyl += length-cur;cur=0;}
	}
	return cyl;
}

int scan(){
	sort(); int i,index,cyl = 0;
	for(i=0;i<n;i++) if(arr[i]>cur) break;
	index = i-1;
	for(i=index;i>=0;i--){
		cyl += cur-arr[i];
	 	cur = arr[i];
		printf("%d  ",arr[i]);
	}
	cyl += arr[0];cur=0;
	for(int i=index+1;i<n;i++){
		cyl += arr[i]-cur;
	 	cur = arr[i];
		printf("%d  ",arr[i]);
	}
	return cyl;
}

int main(){
	scanf("%d %d",&n,&length);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);	
	scanf("%d",&cur);
	printf("The order of requests - \n");
	printf("\nCylinder movements - %d",cscan());
	return 0;
}