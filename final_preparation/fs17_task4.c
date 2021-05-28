#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int max_val(int B, int n, int s[], int v[], int used[]){
	if (B == 0) return 0;
	if (B < 0) return -999;
	
	printf("used status for B = %d:	" , B);
	for (int j=0; j<n; ++j){
		printf("%d-", used[j]);
	}
	printf("\n");
	
	int cur_max = -1;
	
	for (int i=0; i<n; ++i){
		if (used[i] == 0){
			used[i] = 1;
			cur_max = MAX(cur_max, v[i] + max_val(B-s[i], n, s, v, used));
		}
	}
	return cur_max;
}


int main(){
	int v[] = {10, 7, 4};
	int s[] = {8, 3, 5};
	int used[] = {0, 0, 0};
	
	int res = max_val(8, 3, s, v, used);
	printf("res: %d", res);
	
	return 0;
}
