#include <stdio.h>
#define false 0
#define true 1

int canSum(int targetSum, int numbers[], int n){
	int arr[targetSum+1];
	memset( arr, 0, (targetSum+1)*sizeof(int) ); //sett arr to 0
	arr[0] = 1; //true, because targetSum of 0 can always be obtained
	int tmp;
	

	for (int k=0; k<=targetSum; ++k){ //for i=0 to targetSum
		if (arr[k] == true){
			printf("arr[k]: %d, k: %d \n", arr[k], k);
			for (int j=0; j<n; ++j){
				printf("j: %d\n",j);
				tmp = k + numbers[j];
				arr[tmp] = true;
			}
		} 
	}
	
	printf("The final array ('1' indicates that the value can be attained with the numbers in the array):\n");
	for (int b=0; b<= targetSum; ++b){
		printf("%d ", arr[b]);
	}
	printf("\n");
	return arr[targetSum];
}


int main(){
	
	int target = 7;
	int nr[] = {5,3,4,7};
	int res = canSum(target, nr, 4);
	printf("%d\n", res);
	
	return 0;
}
