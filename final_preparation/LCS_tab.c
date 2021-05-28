#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int LCS(char s1[], char s2[]){
	int tab[100][100];
	for (int i=0; i<100; ++i){
		for (int j=0; j<100; ++j){
			tab[i][j] = 0;
		}
	}
	
	for(int i=1; i<=strlen(s1); ++i){
		for (int j=1; j<=strlen(s2); ++j){
			if(s1[i] == s2[j]){
				tab[i][j] = 1 + tab[i-1][j-1];
			}else{
				tab[i][j] = MAX(tab[i-1][j], tab[i][j-1]);
			}
		}
	}
	
	return tab[strlen(s1)][strlen(s2)];
}


int main(){
	char s1[] = "hellopartypeples";
	char s2[] = "ellpartypple";
		
	int res = LCS(s1, s2);
	printf("The LCS is: %d\n", res);
	
	return 0;
}
