#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdbool.h>

int kp_rec(int W, int n, int v[], int w[]){
	if (W == 0 || n == 0) return 0;
	if (W < 0) return -9999;
	int cur_max = -1;
	
	return MAX(v[n-1] + kp_rec(W - w[n-1], n-1, v, w), kp_rec(W, n-1, v, w));
	
}


int main(){
	int v[] = {11,10, 55,20, 30};
	int w[] = {1,1, 4,2, 3};
	
	int res = kp_rec(5,3,v,w);
	printf("res: %d", res);
	
	
	return 0;
}
