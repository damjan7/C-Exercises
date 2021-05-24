#include <stdio.h>
#include <string.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))


int knapsack(int W, int n, int w[], int v[]){
	int K[n+1][W+1];
	memset( K, 0, (n+1)*(W+1)*sizeof(int) );
	int tmp1,tmp2;
	
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=W; ++j){
			
		tmp1 = K[i-1][j];
		printf("j-w[i-1]: %d,  j: %d \n", j-w[i-1], j);
		if(j-w[i-1] <= j && j-w[i-1] >= 0){ // > 0 condition wichtig!!!!!
			tmp2 = K[i-1][j-w[i-1]] + v[i-1];
		}else{
			tmp2 = 0;
		}
		//printf("tmp1: %d, tmp2: %d\n", tmp1, tmp2);
		K[i][j] = new_max(tmp1, tmp2);
		
		}
	}
	
	for (int i=0; i<=n; ++i){
		printf("row %d:  ", i);
		for(int j=0; j<=W; ++j){
			printf("%d	", K[i][j]);
		}
		printf("\n");
	}
	
	//now we must extract which elements are in the knapsack
	int max_val = K[n][W];
	int item_list[n-1];
	int cur_W = W;
	memset(item_list, 0, (n-1)*sizeof(int) );
	
	for (int i=n; i>=1; --i){
		if(max_val == K[i-1][cur_W]){
			item_list[i-1] = 0;
		}else{
			item_list[i-1] = 1;
			max_val = max_val - v[i-1];	
			cur_W = cur_W - w[i-1];
		}
	}
	
	printf("Included items are: ");
	for(int i=0; i<n; ++i){
		printf("%d ", item_list[i]);
	}
	printf("\n");
	return 0;
}


int main(){
	int W = 5;
	int n = 3;
	int v[] = {10,20,30};
	int w[] = {1,2,3};
	knapsack(W,n,w,v);
	
	int v2[]={1,2,5,6};
	int w2[] = {2,3,4,5};
	W=8;
	n=4;
	knapsack(W,n,w2,v2);
	
	
	return 0;
}
