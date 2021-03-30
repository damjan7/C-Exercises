#include <stdio.h>

int pascal(int i, int j){
	//condition for all the values at the edges
	if (i==0){
		return 1;
	}
	if (j == 0 || j == i){
		return 1;
	}
	return pascal(i-1, j-1) + pascal(i-1, j);
}

void printPascal(int n){
	int i;
	printf("Row %d: ", n);
	for (i = 0; i < n+1; ++i){
		printf("%d ", pascal(n,i));
	}
}

int recursive_find_indent(int current_row, int total_rows){
	if (current_row == total_rows){
		return 0;
	}
	if (current_row == 0){
		return total_rows*2;
	}
	return recursive_find_indent(current_row-1, total_rows) - 2;
}

void format_print_pascal(int n){
	int row;
	int j;
	int whitespace;
	for (row = 0; row < n+1; ++row){
		for(whitespace = 0; whitespace < 1+recursive_find_indent(row,n); ++whitespace){
			printf(" ");
		}
		for (j = 0; j < row+1; ++j){
			printf("%d   ", pascal(row,j));
		}
		printf("\n");
	}	
}


int main(){
	int k;
	format_print_pascal(10);
	for (k = 0; k < 26; ++k){
		printPascal(k);
		printf("\n");
	}
	return 0;
}
