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

struct TreeNode* search(struct TreeNode* root, int val){
	struct TreeNode* tmp = root;
	//printf("%d\n", tmp -> val);
	while(tmp != NULL){
		if (tmp->val == val){
			printf("Found value in Tree!\n");
			return tmp;
		}
		else if(tmp -> val < val){
			tmp = tmp -> right;
		}
		else{
			tmp = tmp -> left;
		}
	}
	printf("Value %d not found in Tree.\n", val);
	return NULL;
}

void printTree(struct TreeNode *root){ //we will try InOrderTreeWalk
		if (root != NULL){
			printTree(root->left);
			printf("%d-", root->val);
			printTree(root->right);
		}
}

struct TreeNode* maximum(struct TreeNode* t){
	struct TreeNode* start_node = t;
	while (t -> right != NULL){
		t = t->right;
	}
	printf("The Maximum Value in the subtree with root node %d is: %d\n", start_node->val,t->val);
	return t;
}

int distanceToRoot(struct TreeNode* root, int val){
	struct TreeNode* tmp = root;
	int i = 0;
	while (tmp->val != val){
		if (tmp -> val > val){
			tmp = tmp -> left;
			++i;
		}else{
			tmp = tmp -> right;
			++i;
		}
	}
	printf("Distance from %d to Root is: %d\n", val ,i);
	return i;
}

int delete(struct TreeNode** root, int val){ //THERE ARE 3 CASES!
	struct TreeNode* p_del = search(*root, val);
	if (p_del == NULL){
		printf("Value %d is not in the tree!\n", val);
		return 0;
	}

	struct TreeNode* tmp = *root;
	struct TreeNode* tmp_parent = NULL;
	while (tmp->val != val){
		if(tmp->val > val){ //search on left in this case
			tmp_parent = tmp;
			tmp = tmp -> left;
		}else{
			tmp_parent = tmp;
			tmp = tmp -> right;
		}
	}
	//we arrived at the node we need to delete, now we have 3 cases
	//CASE 1:
	printf("%d\n", tmp->val);
	if (tmp->left == tmp->right){ //only way --> both are NULL, just delete node in this case..
		if(tmp_parent->val > val){
			tmp_parent -> left = NULL;
			return 1;
		}else{
			tmp_parent -> right = NULL;
			return 1;
		}
	}
	else if(tmp->left == NULL || tmp->right==NULL){ //CASE 2: node t has one child
		if(tmp_parent->val > val){
			if (tmp -> left == NULL){
				tmp_parent -> right = tmp -> right;
			}else{
				tmp_parent -> left = tmp -> left;
			}
		}else{
			if (tmp -> left == NULL){
				tmp_parent -> right = tmp -> right;
			}else{
				tmp_parent -> left = tmp -> left;
			}
		}
	}
	else{ //CASE 3: Node t has 2 children
	//lets first find the successor to replace it with p_del
	//p_succ can only have 1 child [right child]
	//since its the LEFTMOST node in the right subtree
	struct TreeNode *p_succ = p_del;
	p_succ = p_succ ->right;
	while (p_succ->left != NULL){
		tmp_parent = p_succ;
		p_succ = p_succ -> left;
	}
	if (p_succ -> right != NULL){ //if successor has a right subchild
		tmp_parent -> left = p_succ -> right;
	}
	p_succ -> right = NULL;
	p_del->val = p_succ->val;
	
	}

	
	
	return 1;
}

int main(){
	struct TreeNode **p2r = createTree();
	insert(p2r, 4);
	insert(p2r, 2);
	insert(p2r, 3);
	insert(p2r, 8);
	insert(p2r, 6);
	insert(p2r, 7);
	insert(p2r, 9);
	insert(p2r, 12);
	printTree(*p2r);
	printf("\n");
	maximum((*p2r)-> left);
	delete(p2r, 4);
	printTree(*p2r);
	printf("\n");
	printf("Root Node: %d\n", (*p2r)->val);
	distanceToRoot(*p2r, 12);
	printTree(*p2r);
	printf("\n");
	
	return 0;
}
