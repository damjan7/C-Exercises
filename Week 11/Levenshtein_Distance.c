#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int memo[100][100];
	
int LD(char s1[], char s2[], int i, int j, int memo[100][100]){
	//some base cases
	if(i == 0 || j == 0){ //we start indexing at 1; so base case is if any of the strings is empty
		return MAX(i, j);
	}
	int cur_min = 9999;
	int tmp;
	
	if (memo[i][j] != -1){
		return memo[i][j];
	}

	if(s1[i-1] == s2[j-1]){
		return LD(s1, s2, i-1, j-1, memo);
	}
	
	else{
		printf("cur i and j: %d, %d.\n", i,j);
		//three possibilities:.. if I put these 3 cases in the memo obj. I get weird results....
		tmp = LD(s1,s2,i-1,j, memo) + 1;
		//memo[i-1][j] = tmp;
		cur_min = MIN(tmp, cur_min);
		
		tmp = LD(s1,s2,i,j-1, memo) + 1;
		//memo[i][j-1] = tmp;
		cur_min = MIN(tmp, cur_min);
		
		tmp = LD(s1,s2,i-1,j-1, memo) + 1;
		//memo[i-1][j-1] = tmp;
		cur_min = MIN(tmp, cur_min);
		
		memo[i][j] = cur_min;
		return cur_min;
	}
}

int main(){
	char s1[] = "gumbo";
	char s2[] = "gambol";
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	for (int i=0; i<100; ++i){
		for (int j=0; j<100; ++j){
			memo[i][j] = -1;
		}
	}
	
	int res = LD(s1, s2, len1, len2, memo);
	printf("The Levenshtein Distance is: %d", res);
	
	return 0;
}
