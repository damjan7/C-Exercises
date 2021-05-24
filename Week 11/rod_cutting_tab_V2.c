#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y) (((x) >= (y)) ? (x) : (y))

int cut_rod(int i, int p[]){
	int tab[100];
	for (int b=0; b<100; ++b){
		tab[b] = 0;
	}
	int cur_max = -1;

	for(int j=1; j<=i; ++j){
		for (int k=1; k<=j; ++k){
			cur_max = MAX(cur_max, p[k] + tab[j-k] );
		}
		tab[j] = cur_max;
		cur_max = 0;
	}
	
	return tab[i];
}


int main(){
	int prices[] = {0,1,5,8,9,10,17,17,20,24,30};
	int res = cut_rod(10, prices);
	printf("res: %d\n", res);
	
	int p1[] = {0,3,5,8,9,10,17,17,20};
	res = cut_rod(8, p1);
	printf("res: %d\n", res);
	
	
	return 0;
}
