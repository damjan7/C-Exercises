#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int power(int base, int exp)
{
    int result = 1;
    while(exp) { result *= base; exp--; }
    return result;
}

int sum(int A[], int B[], int n){
	int cur_sum = 0;
	for (int i=n-1; i>=0; --i){
		cur_sum = cur_sum + B[i]*power(10, n-i-1)  + A[i]*power(10, n-i-1);
	}
	return cur_sum;
}
	
	
	
		


int main(){
	int A[] = {1,2,3};
	int B[] = {2,2,2};
	
	int res = sum(A,B,3);
	printf("res: %d\n", res);
	
	return 0;
}
