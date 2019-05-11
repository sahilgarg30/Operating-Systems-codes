#include <stdio.h>

int n,size;
int pages[100],frames[100];
int next = 0;

int empty(){
	for(int i=0;i<size;i++) if(frames[i]==-1) return i;
	return -1;
}

int find(int x){
	for(int i=0;i<size;i++){
		if(frames[i]==x) return i;
	}
	return -1;
}

void printFrames(){
	for(int i=0;i<size;i++) printf("%d ",frames[i]);
	printf("\n");
}

void fifo(int x){
	frames[next] = x;
	next = (next+1)%size;
}

void LRU(int index){
	if(empty()!=-1){
		frames[empty()] = pages[index];
		return;
	}
	int cur = -1;
	int occur[100];
	int last = -1;
	for(int i=0;i<size;i++) occur[i] = 0;
	for(int i=index-1;i>=0;i--){
		cur = find(pages[i]);
		if(cur != -1 && !occur[cur]){
			last = cur;
			occur[cur] = 1;
		}
	}
	for(int i=0;i<size;i++) if(!occur[i]){last = i;break;}
	if(last==-1) fifo(pages[index]);
	else frames[last] = pages[index];
}

int main(){
	scanf("%d %d",&n,&size);
	for(int i=0;i<n;i++) scanf("%d",&pages[i]);
	for(int i=0;i<n;i++) frames[i] = -1;
	int faults = 0,hits = 0;
	for(int i=0;i<n;i++){
		int isFound = find(pages[i]);
		if(isFound == -1){
			faults++;
			LRU(i);
			}else {
			hits++;}
		printFrames();
	}
	printf("Faults - %d \nHits - %d\n",faults,hits);
}