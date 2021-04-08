#include <stdio.h>
int get_length(char *str[]){
	int cnt = 0;
	char *p = str; //arrays are actually pointers to the first element of the array!
	while (*p != '\0'){
		++cnt;
		p = (p+1);
	}
	return cnt;
}

void print_rev(char *str[]){
	int l = get_length(str);
	char *p_start = str;
	char *p_end = p_start + l-1;
	char *p_iter = p_end;
	while (p_iter != p_start){
		printf("%c", *p_iter);
		--p_iter;
	}
	printf("%c", *p_iter);
}

void print_rev_arr(int arr[], int n){
	int *p_start = arr;
	int *p_end = arr + n-1;
	int *p_iter = p_end;
	while (p_iter != p_start){
		printf("%d", *p_iter);
		--p_iter;
	}
	printf("%d", *p_iter);	
}

void mat_mul(int arr[])


int main(){
	char s[] = "Hello, Damjan!";
	print_rev(s);
	int arr[] = {1,2,3,4,5};
	printf("\n \n");
	print_rev_arr(arr, 5);
	printf("\n \n");
	int len = get_length(s); 
	printf("%d", len);
	return 0;
}
