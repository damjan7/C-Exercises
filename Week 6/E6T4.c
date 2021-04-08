#include <stdlib.h>
#include <stdio.h>

struct node {
	int val; // 'val' is the data we want to store
	struct node *next; //the '*next' is the pointer to the same structure type
					   // '*next' will store location of next node if it exists, otherwise NULL
};

int return_sum(struct node *l1, struct node *l2 ){
	int sum = 0;
	int carryover = 0;
	struct node *tmp1, *tmp2;
	tmp1 = l1;
	tmp2 = l2;
	struct node *root_result;
	root_result->next = NULL;
	struct node *tmp_res;
	tmp_res = root_result;
	
	
	while(tmp1 || tmp2){
		next_node = (struct node *)malloc(sizeof(struct node));
		if (tmp1 != NULL && tmp2 != NULL){
			sum = sum + tmp1 -> val + tmp2 -> val;
			tmp_res -> next = next_node
			next_
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		else if (tmp1 != NULL && tmp2 == NULL){
			sum = sum + tmp1->val;
			tmp1 = tmp1->next;
		}
		else{
			sum = sum + tmp2->val;
			tmp2 = tmp2->next;
		}
	}

	printf("cross sum: %d", sum);
	return 69;
}


void printList(struct node *root){
	//the print function just needs the address of the first element
	//as input.. this is the root pointer
	struct node *temp_ptr = root;
	
	while (temp_ptr != NULL){
		printf("%d - ", temp_ptr -> val);
		temp_ptr = temp_ptr -> next;
	}
	printf("\n");
}

int main(){
	struct node n1; //create 3 nodes:
	struct node n2;
	struct node n3;
	struct node *root_n; //root pointer, we will make it point to the first element
	
	//let's set the values of the nodes
	n1.val = 45;
	n2.val = 8;
	n3.val = 32;
	
	//link them up, 3. element will be the root!
	root_n = &n3;
	n3.next = &n2; //then we set each nodes 'next' pointer to the address of the next element
	n2.next = &n1;
	n1.next = NULL; //so we know when the list ends
	
	struct node g1; //create 3 nodes:
	struct node g2;
	struct node g3;
	struct node *root_g; //root pointer, we will make it point to the first element
	
	//let's set the values of the nodes
	g1.val = 3;
	g2.val = 2;
	g3.val = 14;
	
	//link them up, 3. element will be the root!
	root_g = &g3;
	g3.next = &g2; //then we set each nodes 'next' pointer to the address of the next element
	g2.next = &g1;
	g1.next = NULL; //so we know when the list ends
	
	printList(root_n);
	printList(root_g);
	return_sum(root_n, root_g);
	return 0;
}
