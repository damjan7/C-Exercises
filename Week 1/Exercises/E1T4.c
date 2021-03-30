#include <stdio.h>

void ascSelectionSort(int A[], int n){
	int i;
	int t;
	int j;
	for (i = 0; i < n-1; ++i){
		int k = i;
		for (j = i+1; j < n; ++j){
			if (A[j] < A[k]){
				k = j;
			}
		}
		int t = A[i];
		A[i] = A[k];
		A[k] = t;
	}
	//print the sorted array
	for (i=0; i<n; ++i){
		printf("%d", A[i]);
		printf(" ");
	}
}




























void descSelectionSort(int A[], int n){
	int i;
	int j;
	int k;
	int t;
	
	for (i=n-1; i>0; --i){
		k = i; //idx of largest element
		for (j=i-1; j>-1; --j){
			if (A[j] < A[k]){
				k = j;
			}
		}
		t = A[k];
		A[k] = A[i];
		A[i] = t;
	}
	//print the sorted array
	for (i=0; i<n; ++i){
		printf("%d", A[i]);
		printf(" ");
	}
}

void main(){
	int A[5] = {24,21,2,64,2123};
	ascSelectionSort(A, 5);
	printf("\n");
	descSelectionSort(A, 5);
}
