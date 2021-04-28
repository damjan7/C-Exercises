#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node *next;
};

/*struct node** createStack(){  //DIESE DOGSHIT FUNKTIONIERT NED!!!! SEE OTHER IMPLEMENTATION OF CREATE STACK BELOW!
	struct node* head;
	head = malloc(sizeof(struct node*));
	struct node **root_ptr;
	head -> val = NULL;
	head -> next = NULL;
	root_ptr = &head;
	return root_ptr;
}*/

struct node** createStack(){
	struct node **p2r;
	p2r = malloc(sizeof(struct node **));
	*p2r = NULL;
	return p2r;
}

void push(struct node **root_ptr, int x){
	struct node *new_node;
	new_node = malloc(sizeof(struct node*)); //wir brauchen hier malloc weil sonst die node nur auf dem stack ist und sobald push fertig ist "verlieren"
	new_node->val = x; //wir die node, deshalb müssen wir sie auf den HEAP tun und den root darauf pointen lassen!
	new_node->next = NULL;
	if (*root_ptr == NULL){
	*root_ptr = new_node;
	}else{
		struct node *tmp = *root_ptr;
		new_node->next = tmp;
		*root_ptr = new_node;
	}
}

int pop(struct node **root_ptr){
	int ret_val = (*root_ptr) -> val;
	struct node *tmp = *root_ptr;
	*root_ptr = (*root_ptr)-> next;
	free(tmp);
	return ret_val;
}

void printStack(struct node **root_ptr){
	struct node *tmp = *root_ptr;
	printf("Stack: ");
	while(tmp->next != NULL){
		printf("%d-", tmp->val);
		tmp = tmp->next;
	}
	if (tmp != NULL){
		printf("%d\n", tmp->val);
	}
}

int main(){
	struct node **root_ptr = createStack();
	push(root_ptr, 23);
	push(root_ptr, 87);
	//push(root_ptr, 6);
	push(root_ptr, 1290);
	//printf( "%d\n", (*root_ptr)->val );
	printStack(root_ptr);
	int a = pop(root_ptr);
	printf("Popped value: %d\n", a);
	printStack(root_ptr);

	return 0;
}
