#include <stdio.h>
#include <stdbool.h>

//works perfectly now, but just as printf, i dont know how to return whole arrays :-)
int mat_mul(int A[3][3], int B[3][3]){
	int res[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int row;
	int col;
	int k;
	for(row = 0; row < 3; ++row){
		for(col = 0; col < 3; ++col){
			for (k = 0; k < 3; ++k){
				res[row][col] = res[row][col] + A[row][k]*B[k][col];
			}
		}
	}
	
	for (row=0; row<3; ++row){
		for (col = 0; col<3; ++col){
			printf("%d ", res[row][col]);
		}
		printf("\n");	
	}
	return 0;
}

// should determine all prime nr's btw 0 and n [FAIL]
/* 
void prime_nrs(int n){
	int arr[n+1];
	arr[0] = false;
	arr[1] = false;
	int i;
	int j;
	
	for (i=2; i<n+2; ++i){
		arr[i] = true;
	}
	for (i=2; i<int((n+1)/2); ++i ){
		for (j=2; j<int(n/i); ++j){
			
		}
	}
}
*/


//Reverse String func

int sLength(char s[]){
	int i;
	while(s[i] != '\0'){
		++i;
	}
	return i;
}

void reverse(char s[]){
	int length = sLength(s);
	int i;
	char new_str[length];
	for (i=0; i<length; ++i){
		new_str[i] = s[length-i-1];
	}
	printf("%s", new_str);
}

int main(){
	/*int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int B[3][3] = {{5,5,5}, {6,6,6}, {4,3,2}};
	mat_mul(A,B); 
	int i;
	int arr[10] = {  };
	for (i = 0; i < 10; ++i){
	printf("%d", arr[i]);		
	}
	*/
	
	//for revString
	int MAX_SIZE = 1000;
	char str[MAX_SIZE];
  	printf("Please enter a string: ");
	scanf("%[^\n]s", str);
	reverse(str);
	

	
	
	return 0;
}
