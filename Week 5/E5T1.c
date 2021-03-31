#include <stdio.h>

int Left(int i){
	if (i == 0){
		return 1;
	}
	return 2*i+1;	
}

int Right(int i){
	if (i == 0){
		return 2;
	}
	return 2*i+2;
}

void Heapify(int A[], int n, int i){

	int m = i;
	int t;
	int l = Left(i);
	int r = Right(i);

	if (l < n && A[l] > A[m]){
		m = l;
	}
	if (r < n && A[r] > A[m]){
		m = r;
	}
	if (m != i){
		t = A[i];
		A[i] = A[m];
		A[m] = t;
		Heapify(A, n, m);
	}
	printf("\n");
	for (int j=0; j<18; ++j){
		printf("%d ", A[j]);
	}
}

void BuildHeap(int A[], int n){
	for (int k=n/2-1; k>=0; k--){
		Heapify(A, n, k);
	}	
}

void heapSort(int A[], int n) {
  BuildHeap(A, n);
  for (int i = n - 1; i >= 0; i--) {
		int t = A[i];
		A[i] = A[0];
		A[0] = t;
    Heapify(A, 0, i);
  }
}

int main(){
	int arr[] = {4,3,5,7,2,1,9,23,53,16,4,3,6,76,2,8,43,9};
	printf("Array before BuildHeap: \n");

		for (int i=0; i<18; ++i){
		printf("%d ", arr[i]);
	}
	
	BuildHeap(arr, 18);
	printf("\nArray after BuildHeap: \n");
	for (int i=0; i<18; ++i){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
