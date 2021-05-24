#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


int LIS(int arr[], int n){
	int lis[n];
	memset(lis, 0, n*sizeof(int));
	
	for (int i=1; i<n; i++){
		lis[i] = 1;
		for(int j=0; j<i; j++){
			if (arr[i] > arr[j]){
				lis[i] = MAX(lis[i], lis[j]+1);	
			}
		}
	}
	return lis[n-1];
}

int main(){
	int arr[] = {3,1,8,2,5};
	int res = LIS(arr, 4);
	printf("sol: %d\n", res);
	
	return 0;
}
