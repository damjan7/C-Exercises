#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num){
	int i = 1;
	while (i < num){
		if (num / i == i){
			return 1;
		}
		++i;
	}
	return 0;
}



bool main(){
	printf("Please enter an integer to check if it's a perfect square: ");
	int num;
	scanf("%d" , &num);
	bool a;
	a = isPerfectSquare(num);
	return a;
}
