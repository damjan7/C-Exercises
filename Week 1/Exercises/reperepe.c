#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int n){
	int i;
	for (i=0; i*i<n+1; ++i){
		printf("%d ", i);
		if (i*i == n){
			printf("True! %d is a perfect square!", n);
			i = n+1;
			return true;
		}
	}
	printf("False! %d is NOT a perfect square!", n);
	return false;
	}

int main(){
	int nr;
	printf("Please enter a number to see if it is a perfect integer: ");
	scanf("%d", &nr);
	return isPerfectSquare(nr);

}
