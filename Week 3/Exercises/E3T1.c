#include <stdio.h>

int whatIDo(int A[], int n, int k){
	int sum = 0;
	int i;
	int max_idx;
	int j;
	int swp = 0;
	
	for (i = 0; i < k; ++i){
		max_idx = i;
		for (j = i+1; j < n+1; ++j){
			if (A[j] > A[max_idx]){
				max_idx = j;
			}
		}
		sum = sum + A[max_idx];
		swp = A[i];
		A[i] = A[max_idx];
		A[max_idx] = swp;
	}
	return sum;
}

int main(){
	int A[] = {0,0,100,50,23,0,0};
	int res = whatIDo(A, 7, 3);
	return res;
}
