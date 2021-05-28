#include <stdio.h>

void merge(struct node **rootA, struct node **rootB){
	//leave list 1 as it is and insert elements of list 2
	struct node *tmp1;
	struct node *tmp2;
	struct node *tmp3;
	int val;
	
	while(1==1){
		if(*rootB == NULL){
			break;
		}
		tmp1 = *rootB;
		*rootB->next = *rootB->next->next;
		val = tmp1->val;
		tmp2 = *rootA;
		
		while(tmp2->val < val){ //find right place
			tmp2 = tmp2->next;
		}
		
		tmp1 -> next = tmp2 ->next;
		tmp2->next = tmp1;
	
	}
	
	*rootB = *rootA;
	
}
