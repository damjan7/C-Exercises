#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node *next;
};
struct node *root; //pointer of beginning of list [newest elements]
struct node *tail; //pointer to end of list [oldest elements]

void enqueue(int x){
	if (root == NULL){
		root = (struct node *)malloc(sizeof(struct node));
		root -> val = x;
		root -> next = NULL;
		tail = (struct node *)malloc(sizeof(struct node));
		tail = root;
	}
	else{
		struct node *tmp;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> val = x;
		tmp -> next = NULL;
		tail -> next = tmp;
		tail = tmp;
	}
}

int dequeue(int x){
	
}

void printQueue(){
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp = root;
	printf("Queue: ");
	while (tmp != NULL){
		printf("%d,", tmp -> val);
		tmp = tmp->next;
	}
	printf("\n");
}


int main(){
	enqueue(72);
	enqueue(89);
	enqueue(66);
	printQueue();
	

	
	return 0;
}
