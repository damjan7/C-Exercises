#include <stdio.h>

struct node{
	int key;
	struct node *next;
};



int main(){
	struct node *HT[500];
	/*for (int i=0; i<500; ++i){
		(HT[i]) = NULL;
	}*/

	struct node n1;
	n1.key = 2;
	n1.next = NULL;
	
	printf("%p", HT+1);
	
	*(HT) = n1.key;
	
		
	return 0;
}


