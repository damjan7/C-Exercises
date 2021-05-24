#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin_change_rec(int A, int coins[], int m){
	printf("current A: %d\n", A);
	if (A<0){
		return 99999;
	}
	if (A==0){
		return 0;
	}
	int cur_min = 99999;
	int new_min = 999;
	
	for(int k=0; k<m; ++k){
			new_min = 1+coin_change_rec(A-coins[k], coins, m);
		if (new_min <= cur_min){
			cur_min = new_min;
		}
	}
	return cur_min;
	
	
}

int main(){
	int coins[] = {10,6,1};
	int res = coin_change_rec(26, coins, 3);
	printf("res: %d", res);
	return 0;
}
