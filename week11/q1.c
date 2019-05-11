#include <stdio.h>

int n,size;
int pages[100],frames[100];
int next = 0;
int reference[100];

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

int empty(){
	for(int i=0;i<size;i++) if(frames[i]==-1) return i;
	return -1;
}

void optimal(int index){
	if(empty()!=-1){
		frames[empty()] = pages[index];
		return;
	}
	int r = -1;
	int occur[100];
	int last = -1;
	for(int i=0;i<size;i++) occur[i] = 0;
	for(int i=index+1;i<n;i++){
		r = find(pages[i]);
		if(r != -1 && !occur[r]){
			last = r;
			occur[r] = 1;
		}
	}
	for(int i=0;i<size;i++) if(!occur[i]){last = i;break;}
	if(last==-1) fifo(pages[index]);
	else frames[last] = pages[index];
}

void LRU(int index){
	if(empty()!=-1){
		frames[empty()] = pages[index];
		return;
	}
	int r = -1;
	int occur[100];
	int last = -1;
	for(int i=0;i<size;i++) occur[i] = 0;
	for(int i=index-1;i>=0;i--){
		r = find(pages[i]);
		if(r != -1 && !occur[r]){
			last = r;
			occur[r] = 1;
		}
	}
	for(int i=0;i<size;i++) if(!occur[i]){last = i;break;}
	if(last==-1) fifo(pages[index]);
	else frames[last] = pages[index];
}

void secondChance(int index){
	while(1){
		if(reference[next]==0){
			reference[next] = 1;
			fifo(pages[index]);
			break;
		}else{
			reference[next]=0;
			next = (next+1)%size;
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&pages[i]);
	scanf("%d",&size);
	for(int i=0;i<n;i++) frames[i] = -1;
	int faults = 0,hits = 0;
	for(int i=0;i<n;i++){
		int isFound = find(pages[i]);
		if(isFound == -1){
			faults++;
			//fifo(pages[i]);
			//optimal(i);
			//LRU(i);
			secondChance(i);
		}else {
			hits++;
			reference[isFound]=1;
		}
		printFrames();
	}
	printf("Faults - %d \nHits - %d",faults,hits);
}