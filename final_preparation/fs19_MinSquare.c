#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int MinSquare(int n, int m, int memo[][200]){
	if (m==n) return 1;
	if (memo[n][m] != 99999){
		return memo[n][m];
	}
	
	int horiz_min = 9999;
	int vert_min = 9999;
	int cur;
	
	
	//horizontal Min
	for (int i=1; i<n; ++i){
		memo[i][m] = MinSquare(i, m, memo);
		memo[n-i][m] = MinSquare(n-i, m, memo);
		cur = memo[i][m] + memo[n-i][m];
		
		if (cur < horiz_min){
			horiz_min = cur;
		}
	}
	
	//vertical min
	for (int i=1; i<m; ++i){
		memo[n][i] = MinSquare(n, i, memo);
		memo[n][m-i] = MinSquare(n, m-i, memo);
		cur =  memo[n][i] + memo[n][m-i];
		if (cur < vert_min){
			vert_min = cur;
		}
	}
	
	memo[n][m] = MIN(horiz_min, vert_min);
	return memo[n][m];
}


int main(){
	int memo[200][200];
	for (int i=0; i<200; ++i){
		for (int j=0; j<200; ++j){
			memo[i][j] = 99999;
		}
	}
	
	int res = MinSquare(5,4, memo);
	printf("res: %d\n", res);
	
}
