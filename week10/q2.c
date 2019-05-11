#include <stdio.h>

int main(){
	int size,no;
	printf("Enter size and number of pages - \n");
	scanf("%d %d",&size,&no);
	int addr = 0;
	while(addr!=-1){
		printf("Enter logical address (-1 to end)- \n");
		scanf("%d",&addr);
		if(addr == -1) break;
		int pageno = addr/size;
		if(pageno>=no){printf("Invalid memory.\n");continue;}
		int offset = addr - (pageno*size);
		printf("Page number - %d \t Offset - %d \n",pageno,offset);
	}
	return 0;
}