#include <stdio.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))


int LPS(char A[], int n){
	printf("current string: ");
	for (int l=0; l<n; ++l){
		printf("%c", A[l]);
	}
	printf(", current n: %d", n);
	printf("\n");
	
	
	if (n == 1){
		return 1;
	}
	
	int s = n-1;
	for (int i = 0; i < n/2; ++i){
		if (A[i] != A[s]){
			return new_max( LPS(A+1, n-1), LPS(A, n-1) );
		}
		s--;
	}
	return n;
}

int main(){
	char s[] = "klfabbaere";
	
	int res = LPS(s, 10);
	printf("LPS is %d\n", res);
	
	return 0;
}
