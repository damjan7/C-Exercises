#include <stdio.h>

int gridTravel(int m, int n){
	if (m == 0 || n == 0){
		return 0;
	}
	if (m == 1 || n == 1){
		return 1;
	}
	return gridTravel(m-1, n) + gridTravel(m, n-1);
}

int gridTravelMemo(int m, int n, int A[15][15]){
	if (m == 0 || n == 0){
		return 0;
	}
	if (m == 1 || n == 1){
		return 1;
	}
	if (A[m-1-1][n-1] == 0){
		A[m-1-1][n-1] = gridTravelMemo(m-1, n, A);
	}
	if (A[m-1][n-1-1] == 0){
		A[m-1][n-1-1] = gridTravelMemo(m, n-1, A);
	}
	return  A[m-1-1][n-1] + A[m-1][n-1-1];
}

int main(){
	int res = gridTravel(15,15);
	printf("There is a total of %d ways to traverse the grid (Grid size is 15 by 15).\n", res);

	int res2 = gridTravel(18,18);
	printf("There is a total of %d ways to traverse the grid (Grid size is 18 by 18).\n", res2);
	
	int A[15][15] = {0};
	int res_memo = gridTravelMemo(15,15,A);
	printf("There is a total of %d ways to traverse the grid (Grid size is 15 by 15).\n", res_memo);

	return 0;
}
