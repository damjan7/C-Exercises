#include <stdio.h>


int sequence(int n){
	if (n == 1){
		printf("a(1) = %d\n", 1);
		return 1;
	}
	if (n == 2){
		printf("a(2) = %d\n", 2);
		return 2;
	}
	if (sequence(n-1)%3 == 0){
		
		return sequence(n-1)/3 + sequence(n-2);
	}
	return sequence(n-1) + sequence(n-2);
}

void main(){
	printf("%d \n", sequence(14));
	
    printf("Hello World!");
    
}
