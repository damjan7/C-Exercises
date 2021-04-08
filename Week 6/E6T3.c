#include <stdio.h>
#include <stdlib.h>

	
struct node {
	int val; // 'val' is the data we want to store
	struct node *next; //the '*next' is the pointer to the same structure type
					   // '*next' will store location of next node if it exists, otherwise NULL
};
struct node* root;

void createNodeList(int n){
	struct node *tail, *tmp;
	int num, i;
	root = (struct node *)malloc(sizeof(struct node));
	if (root == NULL){
		printf("Memory could not be allocated!");
	}
	else{
		printf("Input the value of the first node: ");
		scanf("%d", &num);
		root -> val = num;
		root -> next = NULL;
		tmp = root; //we need the tmp pointer to link all nodes!!!
		//we will always use it to link next node to previous one!
	}
	
	for (i=2; i<=n; ++i){
		tail = (struct node *)malloc(sizeof(struct node)); //allocate memory for next struct
		
		if (tail == NULL){ //check if memory allocation worked
			printf("Memory could not be allocated!");
			break;
		}
		else{
			printf("Input the value of the %d. node: ", i);
			scanf("%d", &num);
			tail -> val = num;
			tail -> next = NULL;
			tmp -> next = tail; //link previous node with newly created node
			tmp = tmp -> next; //making current node the previous node, actually JUST MOVING THE POINTER!!!!!
		}
		
	}
}

void displayList(){
	struct node *tmp;
	tmp = root;
	while(tmp != NULL){
		printf("%d - ", tmp->val);
		tmp = tmp -> next;
	}
	printf("\n");
}

void insertNode(int num, int pos){
	int i;
	struct node *tail, *tmp;
	tail = (struct node*)malloc(sizeof(struct node));
	if (tail == NULL){
		printf("Memory could not be allocated!");
	}
	else{
		tail -> val = num; //links the data part
		tail -> next = NULL;
		tmp = root;
		for (i=2; i<=pos-1; ++i){
			tmp = tmp -> next;

		if (tmp == NULL){
			break;
		}

		if (tmp != NULL){
			tail -> next = tmp -> next; //links the address part of new node
			tmp -> next = tail;
		}
		else{
			printf("Insert is not possible at the given position. \n");
			break;
		}
		}
	}
	
}


int main(){
	createNodeList(4);
	insertNode(999, 2);
	displayList();
	return 0;
}
