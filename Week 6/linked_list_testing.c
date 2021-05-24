#include <stdio.h>
#include <stdlib.h>

	
struct node {
	int val;
	struct node *next; 
};

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct node* swapNodes(struct node* head, int k){
    struct node *tmp = head;
    if (head == NULL){ //empty list
        return 0;
    }
    
    int len = 0;
    while(tmp != NULL){
        len++;
        tmp = tmp->next;
    }
    
    struct node *n1,*prev1,*n2,*prev2;
    tmp = head;
    int idx=1;
    n1 = tmp;
    prev1 = NULL;
    n2 = tmp;
    prev2 = NULL;
    
    while(tmp != NULL){
        if (idx==k){
            n1 = tmp;
        }
        if(idx == len-k+1){
            n2 = tmp;
        }
        
        prev1 = tmp;
        prev2 = tmp;
        tmp = tmp->next;
        ++idx;
    }
    
    //finally, change pointers
    struct node *tmp2 = n1->next;
    n1->next = n2->next;
    n2->next = tmp2;
    prev1->next = n2;
    prev2->next = n1;
    
    return head;
}


int main(){
	struct node n1; //create 3 nodes:
	struct node n2;
	struct node n3;
	struct node *root; //root pointer, we will make it point to the first element
	
	//let's set the values of the nodes
	n1.val = 45;
	n2.val = 8;
	n3.val = 32;
	
	//link them up, 3. element will be the root!
	root = &n3;
	n3.next = &n2; //then we set each nodes 'next' pointer to the address of the next element
	n2.next = &n1;
	n1.next = NULL; //so we know when the list ends
	
	//insert value at beginning
	struct node n4;
	n4.val = 666;
	n4.next = &n3;
	root = &n4;
	
	printList(root);
	
	
	swapNodes(root, 2);
	printList(root);

	
	return 0;
}
