#include <stdio.h>
int LENGTH = 10;
int Q[10] = {0};
int h = 0;
int t = 0;
int ELEMENT_COUNTER = 0;

void enqueue(int x){
	if (ELEMENT_COUNTER < LENGTH){
		Q[t] = x;
		t = (t+1) % LENGTH;
		++ELEMENT_COUNTER;
	}
	else{
		printf("Queue is already full!\n");
	}	
}


int dequeue(){
	if (ELEMENT_COUNTER != 0){
		int i = h;
		h = (h+1) % LENGTH;
		--ELEMENT_COUNTER;
		return Q[i];
	}
	else{
		printf("No elements in the queue!\n");
	}

}

void printQ(){
	if (t>h){
		for (int i=h; i<=t-1; ++i){
		printf("%d,", Q[i]);
	}
	printf("\n");
	}
	
	else{
		for (int i=0; i<=t-1; ++i){
		printf("%d,", Q[i]);
	}
	for (int j=h; j<=LENGTH-1; ++j){
		printf("%d,", Q[j]);
	}
	printf("\n");
		
	}

}
	
int main(){
	enqueue(1);
	printQ();
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	printQ();
	dequeue();
	printQ();
	printQ();
	enqueue(666);
	dequeue();
	enqueue(23);
	enqueue(29);
	printQ();
	dequeue();
	enqueue(420);
	printQ();

	
	return 0;
}
