#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int LCS(char s1[], char s2[], int i, int j, int memo[100][100]){
	if (memo[i][j] != -1){
		return memo[i][j];
	}
	
	if (i == 0 || j == 0){
		return 0;
	}
	else if(s1[i-1] == s2[j-1]){
		memo[i][j] = 1 + LCS(s1, s2, i-1, j-1, memo);
		return memo[i][j];
	}else{
		memo[i][j] = MAX(LCS(s1, s2, i-1, j, memo), LCS(s1, s2, i, j-1, memo));
		return memo[i][j];
	}
	
}


int main(){
	int memo[100][100];
	for (int i=0; i<100; ++i){
		for (int j=0; j<100; ++j){
			memo[i][j] = -1;
		}
	}
	
	
	char s1[] = "hellopartypeples";
	char s2[] = "ellpartypple";
		
	int res = LCS(s1, s2, strlen(s1), strlen(s2), memo);
	printf("The LCS is: %d\n", res);
	
	return 0;
}
