#include <stdio.h>
#include <stdlib.h>

	
struct node {
	int val; // 'val' is the data we want to store
	struct node *next; //the '*next' is the pointer to the same structure type
					   // '*next' will store location of next node if it exists, otherwise NULL
};
struct node* root;

struct node createNodeList(int n){
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
	
	return *root;
}

void displayList(struct node *head){
	struct node *tmp;
	tmp = head;
	while(tmp != NULL){
		printf("%d - ", tmp->val);
		tmp = tmp -> next;
	}
	printf("\n");
}

int insertNode(int num, int pos, struct node *head){
	if (head == NULL){
		printf("Inserting node at pos %d is not possible (ERROR 1)!", pos);
		return 0;
	}
	struct node *tmp;
	tmp = head;
	
	if (pos == 1){
		printf("Inserted node at position %d!\n", pos);
		struct node *new_node;
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> val = num;
		new_node -> next = head ->next;
		head -> next = new_node;
		return 0;
	}
	
	
	for (int i=2; i<=pos-1; ++i){
		if (tmp -> next == NULL){
			printf("Inserting node at pos %d is not possible (ERROR 2)!\n", pos);
			return 0;
		}
		tmp = tmp -> next;
	}

	
	
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> val = num;
	new_node -> next = tmp -> next;
	tmp -> next = new_node;
	printf("Inserted node!\n");
	return 0;
}


void deleteNode(int pos, struct node *head){
	struct node *tmp;
	struct node *prevNode;
	tmp = (struct node*)malloc(sizeof(struct node));
	prevNode = (struct node*)malloc(sizeof(struct node));
	
	tmp = head;
	prevNode = head;
	
	if (pos == 1){
		printf("%d\n", head->val);
		head = head ->	next;
		printf("%d\n", head->val);

	}
	else{
		if (head == NULL){
		printf("There are no nodes in the list\n");
		}
		else{
			for (int i=2; i<=pos-1; ++i){
				if (tmp -> next == NULL){
					printf("No node at this position");
				}
			prevNode = tmp;
			tmp = tmp -> next;
			}
		
			printf("Deleted node at position %d\n", pos);
			prevNode -> next = tmp -> next;
			tmp -> next = NULL;
			free(tmp);
	}		
	}
}





int main(){
	struct node n1; //create 3 nodes:
	struct node n2;
	struct node n3;
	struct node *head; //root pointer, we will make it point to the first element
	
	//let's set the values of the nodes
	n1.val = 45;
	n2.val = 8;
	n3.val = 32;
	
	//link them up, 3. element will be the root!
	head = &n3;
	n3.next = &n2; //then we set each nodes 'next' pointer to the address of the next element
	n2.next = &n1;
	n1.next = NULL; //so we know when the list ends
	
	//createNodeList(4);
	displayList(head);
	//insertNode(999, 1, head);
	//displayList(head);
	deleteNode(1, head);
	displayList(head);

	
	//struct node root = createNodeList(4);
	//insertNode(999, 1, &root);
	//displayList(&root);
	
	return 0;
}
