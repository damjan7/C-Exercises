#include <stdio.h>



int MatrixMultiplication(int A[3][3], int B[3][3]){
	int Res [3][3];
	int i;
	int j;
	int b;
	for (i=0; i=2; ++i){
		for (j=0; j=2; ++j){
		}
		
		for (b=0; b=2; ++b){
			Res[i][j] = A[i][b]*A[b][i];
		}
	}
	//return Res;
	int test [3][3] = {{6,6,6}, {6,6,6}, {6,6,6}};
	
	return test;
}


int main(){
	int MatrixA [3][3] = {
	{0,1,2},
	{3,4,5},
	{6,7,8}
	};
	
	int MatrixB [3][3] = {
	{4,2,9},
	{1,1,3},
	{2,2,7}
	};

	int ResultMat [3][3] = MatrixMultiplication(MatrixA, MatrixB);
	
	printf("%d", ResultMat);
	return 123;
}


