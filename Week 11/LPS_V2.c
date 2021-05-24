#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int memo[200][200];

int lps_rec(char s1[], char s1_rev[],int i, int j){
	if (i==0 || j ==0){
		return 0;
	}
	if (memo[i][j] != -1){
		return memo[i][j];
	}
	else{
		if (s1[i-1] == s1_rev[j-1]){
			return 1+lps_rec(s1,s1_rev,i-1,j-1);
		}else{
			return MAX( lps_rec(s1,s1_rev,i,j-1), lps_rec(s1,s1_rev,i-1,j) );
		}
	}
	
	return memo[i][j];
}
	


int main(){
	for (int p=0; p<200; ++p){
		for(int l=0; l<200; ++l){
			memo[p][l] = -1;
		}
	}
	
	
	char s1[] = "abc";
	char s1_rev[] = "cba";
	int s_len = strlen(s1);
	
	int res = lps_rec(s1, s1_rev, s_len, s_len);
	printf("res: %d", res);
	

	return 0;
}
