#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin_change_tab(int A, int coins[], int nr_of_coins){
	int opt_arr[A+1];
	memset(opt_arr, 0, (A+1)*sizeof(int));
	int cur_min;
	
	for (int i=1; i<=A; ++i){
		cur_min = 99999;
		for (int k=0; k<nr_of_coins; ++k){ //this loop finds for every coin which is the optimal, not a greedy solution!!!!
			if(coins[k] <= i && 1+opt_arr[i-coins[k]] < cur_min){
				cur_min = 1+opt_arr[i-coins[k]]; //the plus 1 is the same for every case, since we add a coin, we just have to find out which combination!!
				//opt_arr[i-coins[k]] finds the optimal solution of the SUBproblem without current coin k!
			}
		}
		opt_arr[i] = cur_min;
	}
	for (int i=0; i<=A; ++i){
		printf("%d: %d\n", i, opt_arr[i]);
	}
	return opt_arr[A];
}


int main(){
	int coins[] = {10,6,1};
	int res = coin_change_tab(19, coins, 3);
	printf("\nres: %d", res);
	return 0;
	return 0;
}
