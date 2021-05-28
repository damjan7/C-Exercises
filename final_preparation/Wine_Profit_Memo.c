#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int wine(int left, int right, int prices[], int year, int memo[100][100]){
	if (right < left){
		return 0;
	}
	if (memo[left][right] != -1){
		return memo[left][right];
	}
	//otherwise, determine whether its better to sell leftmost or rightmost wine
	int left_max = prices[left]*year + wine(left+1, right, prices, year+1, memo);
	int right_max = prices[right]*year + wine(left, right-1, prices, year+1, memo);
	
	memo[left][right] = MAX(left_max, right_max);
	printf("hi\n");
	return memo[left][right];
	
	
}

int main(){
	//int wines[] = {1,1,1,1}; //indicating that the wines are available to sell
	int p[] = {1,4,2,3,4,2,1,4,6};
	int memo[100][100];
	for (int i=0; i<100; ++i){
		for (int j=0; j<100; ++j){
			memo[i][j] = -1;
		}
	}
	

	int res = wine(0, 9, p, 1, memo);
	printf("Max Profit is %d!", res);
	
	return 0;
}
