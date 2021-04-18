#include <stdlib.h>
#include <stdio.h>

MAX_SIZE = 10;

void addFront(int *arr, int *pfront, int *prear, int x){
	if (*pfront < 10 && *pfront <= *prear){
		*(arr + *pfront) = x;
		*pfront = *pfront + 1;
	}else{
		printf("deque is full!\n");
	}

}

void addRear(int *arr, int *pfront, int *prear, int x){
	if (*prear >= 0 && *prear >= *pfront){
		*(arr + *prear) = x;
		*prear = *prear - 1;	
	}else{
		printf("deque is full!\n");
	}
}

void delFrond(){
	
}

void delRear(){
	
}

void printArr(int arr[]){
	for (int i=0; i<=MAX_SIZE-1; ++i){
		printf("%d,", *(arr+i) );
	}
	printf("\n");
}

int main(){
	int arr[10] = {0};
	int front = 0;
	int rear = 9;
	
	printArr(arr);
	addFront(arr, &front, &rear, 24);
	addRear(arr, &front, &rear, 8);
	addFront(arr, &front, &rear, 99);
	addFront(arr, &front, &rear, 2);
	addFront(arr, &front, &rear, 5);
	addFront(arr, &front, &rear, 33);
	addFront(arr, &front, &rear, 65);
	addFront(arr, &front, &rear, 7);
	addFront(arr, &front, &rear, 2);
	addFront(arr, &front, &rear, 11);
	printArr(arr);
	

	return 0;
}
