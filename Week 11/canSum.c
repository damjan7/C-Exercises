#include <stdio.h>
#define false 0
#define true 1

int canSum(int targetSum, int numbers[], int n){
	if (targetSum == 0){
		return true; //return true
	}
	
	for (int i=0; i<n; ++i){
		if (targetSum - numbers[i] >= 0){
			if(canSum(targetSum-numbers[i], numbers, n) == true){
				return true;
			}
		}
	}
	
	return false; //if no such case was found, return ZERO
}


int main(){
	int target = 7;
	int nr[] = {5,3,4,7};
	int res = canSum(target, nr, 4);
	printf("%d\n", res);
	
	int t2 = 300;
	int nr2[] = {7,14};
	res = canSum(t2, nr2, 2);
	printf("%d\n", res);
		
	return 0;
}
