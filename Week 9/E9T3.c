#include <stdio.h>
#include <stdlib.h>

struct rb_node {
	int key, color;
	struct rb_node *left, *right, *parent;
};

struct rb_tree{
	int bh;
	struct rb_node *root;
	struct rb_node *nil;
};

const int red = 0;
const int black = 1;

struct rb_tree* rb_initialize(){
	struct rb_tree* tree;
	struct rb_node *NIL_node = malloc(sizeof(struct rb_node));
	NIL_node->left = NIL_node->right = NIL_node->parent = tree->nil;
	NIL_node->color = black;
	tree->nil = NIL_node;
	tree->bh = 0;
	return tree;
}

void rb_leftRotate(struct rb_tree *tree, struct rb_node* x){
	struct rb_node *s = x->right;
	x->right = s->left;
	s->parent = x->parent;
	if (s->left != tree->nil){
		s->left->parent = x;
	}
	if (x->parent == tree->nil){
		tree->root = s;
	}else{
		if (x == x->parent->left){
			x->parent->left = s;
		}else{
			x->parent->right = s;
		}
	}
	
	s->left= x;
	x->parent = s;
}

void rb_rightRotate(struct rb_tree *tree, struct rb_node* x){
	struct rb_node *s = x->left;
	x->left = s->right;
	s->parent = x->parent;
	if (s->right != tree->nil){
		s->right->parent = x;
	}
	if (x->parent == tree->nil){
		tree->root = s;
	}else{
		if (x == x->parent->right){
			x->parent->right = s;
		}else{
			x->parent->left = s;
		}
	}
	s->right= x;
	x->parent = s;
}

void rb_insert_fixup(struct rb_tree *tree, struct rb_node *x){
	struct rb_node *p = x->parent;
	struct rb_node *g = x->parent->parent;
	struct rb_node *u;
	printf("curr node to fix:%d\n", x->key);
	if (g->left = p){ //NORMAL CASE, NOT MIRRORED!
		u = g->right;
	}else{
		u = g->left;
	}
	
	if(p->color == black){ //nothing to do
		return;
	}
	else if(u->color == red){
		p->color = u->color = black;
		g->color = red;
		rb_insert_fixup(tree, g);
		return;
	}
	
	else if(u->color==black){ //CASE 2 AND CASE 3: t's uncle is black
		if (g->left == p && p->right == x){ //NORMAL case 2
			rb_leftRotate(tree, p);
			rb_insert_fixup(tree, p);	
			return;		
		}else if(g->right == p && p->right == x){ //MIRRORED case 2
			rb_rightRotate(tree, p);
			rb_insert_fixup(tree, p);
			return;
		}
	}
	else{ //CASE 3
		if(g->left == p && p->left == x){ //NORMAL case 3
			p->color=black;
			g->color=red;
			rb_rightRotate(tree, g);
			return;
		}else if (g->right == p && p->left == x){ //MIRRORED case 3
			p->color=black;
			g->color=red;
			rb_leftRotate(tree, g);
			return;
		}
		
	}
	
}

void rb_insert(struct rb_tree *T, int key){
	//create the node, which we will insert!
	struct rb_node *new_node = malloc(sizeof(struct rb_node));
	new_node->key = key;
	new_node->color = red; //new nodes are always made red!
	new_node->left = new_node->right = new_node->parent = T->nil; //parent of root also points to NIL
	if (T->root == NULL){
		new_node->color = black; //root node is black!
		T->root = new_node;
		return;
	}
	struct rb_node *tmp = T->root; //temporary node to find where to insert new node!
	struct rb_node *parent_tmp = tmp;
	while(tmp != T->nil){
		if(tmp->key > key){ //look on the left
			parent_tmp = tmp;
			tmp = tmp->left;
		}else{
			parent_tmp = tmp;
			tmp = tmp->right;
		}
	}
	
	//after inserting we must directly call fixup!
	if(parent_tmp->key > key){
		parent_tmp->left = new_node;
		new_node->parent = parent_tmp;
		rb_insert_fixup(T, new_node);
	}else{
		parent_tmp->right = new_node;
		new_node->parent = parent_tmp;
		rb_insert_fixup(T, new_node);
	}

}


void printTree(struct rb_node *root, struct rb_tree *tree_ptr){ //we will try InOrderTreeWalk
		if (root != tree_ptr->nil){
			printTree(root->left, tree_ptr);
			printf("%d(%d)-", root->key, root->color);
			printTree(root->right, tree_ptr);
		}
}

int main(){
	struct rb_tree *tree_ptr = rb_initialize();
	rb_insert(tree_ptr, 5);
	rb_insert(tree_ptr, 90);
	rb_insert(tree_ptr, 20);
	printTree(tree_ptr->root, tree_ptr);
	printf("\n");
	//printf("cur root: %d\n", tree_ptr->root->key);
	//rb_rightRotate(tree_ptr, tree_ptr->root->right->left);
	//rb_leftRotate(tree_ptr, tree_ptr->root);

	
	
	return 0;
}


