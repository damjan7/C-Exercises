#include <stdio.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))

void foo(int *arr_ptr, int n){
	for (int i=0; i<n; ++i){
		printf("%d ", *(arr_ptr) );
		arr_ptr = arr_ptr+1;
	}
}


int main(){
	int arr[6] = {1,2,3,4,5,6};
	foo(arr+1, 5);
	//printf("\n %p \n", &(arr) );
	
	
	return 0;
}
