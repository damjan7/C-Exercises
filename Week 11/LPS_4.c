#include <stdio.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))

int L[10][10] = {0};

int LPS(char A[], int n, int i, int j){
	
	printf("current string: ");
	for (int l=i; l<=j; ++l){
		printf("%c", A[l]);
	}
	printf(", current n: %d. cur i: %d, cur j: %d", n, i, j);
	printf("\n");
	if (i == j){
		L[i][j] = 1;
		return 1;
	}
	
	int s = j;
	for (int k = i; k < (j+1)/2; ++k){
		if (A[k] != A[s]){
			if (L[i][j-1] == 0){
				L[i][j-1] = LPS(A, n-1, i, j-1);
			}
			
			if (L[i+1][j] == 0){
				L[i+1][j] = LPS(A, n-1, i+1, j);
			}		
			
			return new_max( L[i][j-1], L[i+1][j] );
		}
		s--;
	}
	
}

int main(){
	char s[] = "klfabbaasd";
	
	int res = LPS(s, 10, 0, 9);
	
	for (int i=0; i<10;++i){
		printf("row %d: ",i);
		for (int j=0; j<10; ++j){
			printf("%d", L[i][j]);
		}
		printf("\n");
	}
	
	printf("\nLPS is %d\n", res);
	
	return 0;
}
