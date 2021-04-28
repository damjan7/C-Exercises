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
		printf("test");
		*p2r = new_node;
	}
}


int main(){
	struct TreeNode **p2r = createTree();
	insert(p2r, 24);
	
	return 0;
}
