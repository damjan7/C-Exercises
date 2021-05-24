#include <stdio.h>
#include <string.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))


int cut_rod(int rod_len, int p[], int n){
	int r[n+1];
	memset(r, 0, (n+1)*sizeof(int));
	int max_value;
	
	for (int j=1; j<=n; ++j){
		max_value = 0;
		for(int i=0; i<=j; ++i){
			max_value = new_max( max_value, p[i] + r[j-i-1]  );
		}
		r[j] = max_value;
	}
	
	for (int i=0; i<=n; ++i){
		printf("%d ", r[i]);
	}
	printf("\n");
}

int main(){
	int p1[] = {1,5,8,9,10,17,18,20}; //for length i = 1,2,..8
	int rod_len1 = 8;
	cut_rod(rod_len1, p1, 8);
	
	
	int prices[] = {0,1,5,8,9,10,17,17,20,24,30};
	cut_rod(8, prices, 10);
	return 0;
}
