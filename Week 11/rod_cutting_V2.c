#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y) (((x) >= (y)) ? (x) : (y))

int cut_rod(int i, int p[], int memo[]){
	if(i==0) return p[0]; //base case
	int cur_max = -1;
	if (memo[i] == 0){
		return memo[i];
	}else{
		for (int k=1; k<=i; ++k){
			cur_max = MAX(cur_max, p[k] + cut_rod(i-k, p, memo) );
		}
	}
	return cur_max;
}


int main(){
	int prices[] = {0,1,5,8,9,10,17,17,20,24,30};
	int memo[100];
	for (int i=0; i<100; ++i){
		memo[i] = -1;
	}
	
	int res = cut_rod(7, prices, memo);
	printf("res: %d\n", res);
	
	return 0;
}
