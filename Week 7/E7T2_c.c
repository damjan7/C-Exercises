#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node *next;
};
struct node *root; //pointer of "head of list" in linked lists: ROOT


void push(int x){
	if (root == NULL){
		root = (struct node *)malloc(sizeof(struct node));
		root -> val = x;
		root -> next = NULL;
	}
	else {
		struct node *new_node;
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> val = x;
		new_node -> next = root;
		root = new_node;
	}
	
}

int pop(){
	if (root != NULL){
		int el = root -> val;
		struct node *tmp;
		tmp = (struct node*)malloc(sizeof(struct node)); //diesen teil brauchts nicht..
		tmp = root;
		root = root -> next;
		free(tmp);
		return el;		
	}
	else{
		printf("Stack is empty!\n");
	}

}


void printStack(){
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp = root;
	printf("Stack: ");
	while (tmp != NULL){
		printf("%d,", tmp -> val);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(){
	push(23);
	push(54);
	push(72);
	printStack();
	int a = pop();
	printf("Popped element: %d\n", a);
	printStack();
	pop();
	pop();
	printStack();
	pop();
	push(89);
	printStack();
	return 0;
}
