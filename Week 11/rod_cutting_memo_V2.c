#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y) (((x) >= (y)) ? (x) : (y))
	int memo[100];

int cut_rod(int i, int p[], int memo[]){
	if(i==0) return p[0]; //base case
	int cur_max = -1;
	if (memo[i] == 0){
		return memo[i];
	}else{
		for (int k=1; k<=i; ++k){
			memo[i-k] = cut_rod(i-k, p, memo);
			cur_max = MAX(cur_max, p[k] + memo[i-k] );
		}
	}
	return cur_max;
	
}


int main(){
	int prices[] = {0,1,5,8,9,10,17,17,20,24,30};
	for (int i=0; i<100; ++i){
		memo[i] = -1;
	}
	
	int res = cut_rod(10, prices, memo);
	printf("res: %d\n", res);
	

	for (int i=0; i<100; ++i){
		memo[i] = -1;
	}
	
	int p1[] = {0,3,5,8,9,10,17,17,20}; //for length i = 1,2,..8
	int rod_len1 = 8;
	res = cut_rod(8,p1, memo);
	printf("res: %d\n", res);

	
	return 0;
}
