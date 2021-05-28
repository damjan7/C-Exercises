#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdbool.h>

int kp_rec(int W, int n, int v[], int w[], int used[]){
	if (W == 0 || n == 0) return 0;
	if (W < 0) return -9999;
	int cur_max = -1;
	
	for(int i=0; i<n; ++i){
		if(used[i] == false){
			used[i]
			cur_max = MAX(cur_max, v[i] + kp_rec(W-w[i], n, v, w, used) )
		}
		
	}
	
	return cur_max;
}


int main(){
	
	return 0;
}
