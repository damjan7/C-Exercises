#include <math.h>
#include <stdio.h>

int Merge(int A[1001], int l, int m, int r){
	int B[1001];
	int i;
	int j;
	int k;
	int inversionCounter = 0;
	for (i=l; i<m+1; ++i){
		B[i] = A[i];
	}
	for (i=m+1; i<r+1; ++i){
		B[r+m-i+1] = A[i];
		}
	i = l;
	j = r;
	for (k=l; k<r+1; ++k){
		if(B[i] < B[j]){
			A[k] = B[i];
			++i;
		}
		else{
			A[k] = B[j];
			--j;
			++inversionCounter;
		}
	}
	return inversionCounter;
}

int MergeSort(int A[1001], int l, int r){
	if (l >= r){
		return 0;
	}
	int m;
	int inversionCounter = 0;
	if (l<r){
		m = floor((l+r)/2);
		inversionCounter = inversionCounter + MergeSort(A, l, m);
		inversionCounter = inversionCounter + MergeSort(A, m+1, r);
		inversionCounter = inversionCounter + Merge(A,l,m,r);
	}
	return inversionCounter;
}

int main(){
	int A[3] = {3,2,1};
	int i;
	printf("List before sorting:\n");
		for (i=0; i<3; ++i){
		printf("%d ", A[i]);
	}
	printf("\n");
	
	int invCount = MergeSort(A,0,2);
	
	printf("\nList after sorting:\n");
	for (i=0; i<3; ++i){
		printf("%d ", A[i]);
	}
	return invCount;
}
