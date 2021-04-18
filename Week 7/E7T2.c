#include <stdio.h>

//stack and pointer are global variables
int stack[10] = {0};
int t = 0; //points to the top of the stack [not a 'real' pointer]

	void push(int x, int n){
	if (t == n-1){
		printf("Stack is full! Cannot push an element.");
	}
	else{
		stack[t] = x;
		++t;
	}
}


	void pop(int n){
		if(t == 0){
			printf("Stack is empty! Cannot pop an element.");
		}
		--t;
	}

	void printStack(){
		for (int i=0; i<=t-1; ++i){
			printf("%d,", stack[i]);
		}
		printf("\n");
	}

int main(){
	push(5, 10);
	push(99, 10);
	printStack();
	pop(10);
	printStack();
	push(123, 10);
	printStack();
	pop(10);
	pop(10);
	printStack();
	pop(10);


	printf("\nres: %d", 9+1 %10);
	return 0;
}
