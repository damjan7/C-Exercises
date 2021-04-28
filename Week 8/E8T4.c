#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode** createTree(){
	struct TreeNode** p2r;
	p2r = malloc(sizeof(struct TreeNode*));
	*p2r = NULL;
	return p2r;
}

void insert(struct TreeNode** p2r, int val){
	// create TreeNode which we will insert
	struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
	new_node -> val = val;
	new_node -> left = NULL;
	new_node -> right = NULL;
	//define onestep delayed pointer
	struct TreeNode* parent_ptr = NULL;
	struct TreeNode* tmp = NULL;
	tmp = *p2r;
	// find right place to insert node
	while (tmp != NULL){
		parent_ptr = tmp;
		if (tmp -> val < val) tmp = tmp->right;
		else tmp = tmp->left;
	}
	if (parent_ptr == NULL){
		//(*p2r)->val = val;  ---> GEHT GLAUB NICHT da *p2r NULL ist und kein struct.. es hat lediglich SPACE reserviert für ein struct!!!!!!!!!!!!!!!!!!!
  		*p2r = new_node;
	}
	else if (parent_ptr->val < val){ //then insert on the right
		parent_ptr -> right = new_node;
	}else{
		parent_ptr -> left = new_node;
	}
}

void printTree(struct TreeNode *root){ //we will try InOrderTreeWalk
		if (root != NULL){
			printTree(root->left);
			printf("%d-", root->val);
			printTree(root->right);
		}
}



struct TreeNode* lca(struct TreeNode *root, int n1, int n2){
	//first search node 1:
	struct TreeNode *tmp = root;
	struct TreeNode *low_anc = root;
	while (1==1){
		if (tmp -> val > n1 && tmp -> val > n2){
			tmp = tmp -> left;
			low_anc = tmp;
		}
		else if(tmp -> val < n1 && tmp -> val < n2){
			tmp = tmp -> right;
			low_anc = tmp;
		}
		else{
			printf("The lowest ancestor of %d and %d is %d\n", n1, n2, tmp->val);
			return tmp;
		}	
	}
}


int main(){
	struct TreeNode **p2r = createTree();
	insert(p2r, 7);
	insert(p2r, 5);
	insert(p2r, 6);
	insert(p2r, 1);
	insert(p2r, 9);
	insert(p2r, 10);
	insert(p2r, 8);
	printTree(*p2r);
	lca(*p2r, 8,9);
	lca(*p2r, 6,8);
	lca(*p2r, 1,6);
	lca(*p2r, 1,5);


	return 0;
}
