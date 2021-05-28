#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int wine(int left, int right, int prices[], int year){
	if (right < left){
		return 0;
	}
	//otherwise, determine whether its better to sell leftmost or rightmost wine
	int left_max = prices[left]*year + wine(left+1, right, prices, year+1);
	int right_max = prices[right]*year + wine(left, right-1, prices, year+1);
	
	printf("hi\n");
	return MAX(left_max, right_max);
	
	
}

int main(){
	//int wines[] = {1,1,1,1}; //indicating that the wines are available to sell
	int p[] = {1,4,2,3,4,2,1,4,6};
	
	int res = wine(0, 9, p, 1);
	printf("Max Profit is %d!", res);
	
	return 0;
}
