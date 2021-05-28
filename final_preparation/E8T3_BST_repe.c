#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode** init(){
	struct TreeNode** p2r;
	p2r = malloc(sizeof(struct TreeNode*));
	*p2r = NULL;
	return p2r;
}

void insert(struct TreeNode** p2r, int val){
	struct TreeNode* parent = NULL;
	struct TreeNode* tmp = *p2r;
	struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
	new_node->val = val;
	new_node->left = new_node->right = NULL;
	
	if (tmp == NULL){
		*p2r = new_node;
	}else{	
		while(tmp != NULL){
			if(val > tmp->val){
				parent = tmp;
				tmp = tmp->right;
			}else{
				parent = tmp;
				tmp = tmp->left;
			}
		}
		if(val > parent->val){
			parent->right = new_node;
		}else{
			parent->left = new_node;
		}
	}
}

void InorderTreeWalk(struct TreeNode *root){
	if (root != NULL){
		InorderTreeWalk(root->left);
		printf("%d--", root->val);
		InorderTreeWalk(root->right);
	}
}


int main(){
	struct TreeNode **p2r = init();
	insert(p2r, 4);
	insert(p2r, 2);
	insert(p2r, 3);
	insert(p2r, 8);
	insert(p2r, 6);
	insert(p2r, 7);
	insert(p2r, 9);
	insert(p2r, 12);
	insert(p2r, 1);
	
	InorderTreeWalk(*p2r);
	printf("\n");

	return 0;
}
