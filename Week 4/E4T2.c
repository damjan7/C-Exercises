#include <stdio.h>
//wichtig!!!!! ARRAY im funktionsdef mit [..] passen!!!!!
int countInversions(int A[1000], int n){
	int i;
	int j;
	int counter = 0;
	for (i=0; i<n-1; ++i){
		for (j=i+1; j<n; ++j){
			if (A[i] > A[j]){
				++counter;
			}
		}
	}
	return counter;
}


int main(){
	int arr[12] = { 0 };
	printf("fick mueter");
	int A[3] = {3,2,1};
	int count = countInversions(A,3);
	return count;
}
