#include <stdio.h>
#include <stdlib.h>

//Globally define the struct
struct node{
	int val;
	struct node *next;
};

void add_el_to_emptyList(struct node **root_ptr, int n){
	if ( 1 == 2){
		printf("List is not empty!");
	}
	else{
		int num;
		printf("Input the value of the first node: ");
		scanf("%d", &num);
		(*root_ptr) -> val = num;
		(*root_ptr) -> next = NULL; 
		struct node *prevNode;
		prevNode = *root_ptr;
		
		for (int j=2; j<=n; ++j){
			struct node *tmp;
			tmp = malloc(sizeof(struct node *));
			prevNode -> next = tmp;
			printf("Input the value of the %dth node: ", j);
			scanf("%d", &num);
			tmp -> val = num;
			tmp -> next = NULL;
			prevNode = tmp;
		}
	}
}

void displayList(struct node **root_ptr){
	struct node *tmp;
	tmp = *root_ptr;
	printf("Linked List: ");
	while (tmp != NULL && tmp -> next != NULL){
		printf("%d-", tmp -> val);
		tmp = tmp -> next;
	}
	if (tmp != NULL && tmp -> next == NULL){
		printf("%d", tmp -> val);
		tmp = tmp -> next;
	}
	printf("\n");
}

void addFront(struct node **root_ptr, int el){
	struct node *new_root;
	new_root = malloc(sizeof(struct node *));
	new_root -> val = el;
	new_root -> next = *root_ptr;
	*root_ptr = new_root;	
}

void addRear(struct node **root_ptr, int el){
	struct node *new_tail;
	new_tail = malloc(sizeof(struct node*));
	new_tail -> val = el;
	new_tail -> next = NULL;
	//now walk through list to find "old" last element to link it to the new last element
	struct node *tmp;
	tmp = *root_ptr;
	while (tmp -> next != NULL){
	tmp = tmp -> next;
	}
	tmp -> next = new_tail;
}

void insertNode(struct node **root_ptr, int el, int pos){
	if (pos == 1){
		addFront(root_ptr, el);
	}
	else{
		struct node *tmp, *prevNode;
		prevNode = *root_ptr;
		tmp = (*root_ptr) -> next;
		int cur_pos = 2;
		while (1 == 1){
			if (cur_pos == pos){
				struct node *new_node;
				new_node = malloc(sizeof(struct node*));  //OHNE MALLOC GEHT DAS NICHT GANZ WICHTIG!!!!!! ES ASSIGNED SONST GLAUB KEIN PATZ IM HEAP ODER SO!! VERY IMPORTANT TAKEAWAY!!!!
				new_node -> val = el;
				new_node -> next = tmp;
				prevNode -> next = new_node;
				printf("Inserted Node at Position %d.\n", pos);
				break;
			}
			else{
				++cur_pos;
				if (pos > cur_pos && tmp->next == NULL){ //WICHTIGE LINIE!
					printf("%d\n", tmp->val); //to check! should be last element
					printf("Error!! No Insertion at Position %d Possible.\n", pos);
					break;
				}
				else{
					prevNode = prevNode -> next;
					tmp = tmp -> next;	
				}
			}
		}
	}
}


void delFirst(struct node **root_ptr){
	struct node *tmp;
	tmp = *root_ptr;
	if(tmp == NULL){
		printf("Empty List! No Deletion Possible!");
	}
	else{
		*root_ptr = tmp -> next;
		free(tmp);
		printf("Deleted first element and freed up the space!\n");
	}
}

int findElement(struct node **root_ptr, int el){
	struct node *tmp;
	tmp = *root_ptr;
	int cur_pos = 1;
	while (tmp != NULL){
		if (tmp -> val == el){
			printf("Found the Element at Position %d!\n", cur_pos);
			return cur_pos;
		}
		tmp = tmp -> next;
		++cur_pos;
	}
	printf("Element %d is not in the List!", el);
}


int main(){
	struct node *root;
	root = malloc(sizeof(struct node*));
	struct node **p2r;
	p2r = malloc(sizeof(struct node **));
	p2r = &root;
	root -> val = NULL;
	root -> next = NULL;
	printf("root value: %d\n", (*p2r)->val);
	
	add_el_to_emptyList(p2r, 3);
	displayList(p2r);
	addFront(p2r, 72);
	displayList(p2r);
	addRear(p2r, 666);
	addRear(p2r, 436);
	displayList(p2r);
	insertNode(p2r, 17, 123);
	insertNode(p2r, 17, 3);
	displayList(p2r);
	delFirst(p2r);
	displayList(p2r);
	findElement(p2r, 666);
	printf("First element: %d\n", (*p2r)->next->val );

	return 0;
}
