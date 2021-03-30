#include <stdio.h>

int exponent(int x, int pow){
	if (pow == 1){
		return x;
	}
	return x*exponent(x, pow-1);
}


void main(){
	int base;
	int pow;
	printf("Please enter the base: ");
	int x = scanf("%d", &base);
	printf("Please enter the power: ");
	int p = scanf("%d", &pow);
	
	printf("The result is %d", exponent(base,pow));
}

