#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin_change_rec(int A, int coins[], int m, int memo[]){
	printf("current A: %d\n", A);
	
	if (A<0){
		return 22222;
	}
	if (A==0){
		return 0;
	}
	if (memo[A] != 99999){
		return memo[A];
	}
	
	int cur_min = 2222;
	int new_min = 999;
	
	for(int k=0; k<m; ++k){
		new_min = 1+coin_change_rec(A-coins[k], coins, m, memo);
		
		if (A-coins[k] > 0){	
		memo[A-coins[k]] = new_min-1;
		}
		
		if(new_min < cur_min){
			cur_min = new_min;
		}
	}

	return cur_min;
}

int main(){
	int memo[1000];
	for(int p=0; p<=1000; ++p){
		memo[p] = 99999;
	}

	int coins[] = {10,6,1};
	int res = coin_change_rec(18, coins, 3, memo);
	printf("\nres: %d", res);
	return 0;
}
