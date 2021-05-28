#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int cc_rec(int A, int coins[], int num_coins){
	if (A==0) return 0;
	
	if (A<coins[0]) return 9999;
	
	int cur_min = 9999;
	
	for(int i=0; i<num_coins; ++i){
		cur_min = MIN(cur_min, 1+cc_rec(A-coins[i], coins, num_coins));
	}
	return cur_min;
	
	
}

int main(){
	int coins[] = {1,6,10};
	int res = cc_rec(40, coins, 3);
	printf("res: %d\n", res);
	
	return 0;
}
