#include <stdio.h>
#include <math.h>

#define m 7

void init(int A[]){
	for (int i=0; i<m; ++i){
		A[i] = 0;
	}
}

int h1(int key){
	return key%m + 1;
}

int h2(int key){
	return (m-1) - (key%(m-1));
}

int h(int key, int i){
	return (h1(key) + i*h2(key)) % m;
}

void insert(int A[], int key){
	int i=0;
	int hash_value;
	while(i<m){
		hash_value = h(key, i);
		if (A[hash_value] != 0){
			++i;
		}else{
			A[hash_value] = key;
			return;
		}
	}
	printf("Hash Table is full!!\n");
}

int search(int A[], int key){
	int i=0;
	int hash_value;
	while(i<m){
		hash_value = h(key, i);
		if(A[hash_value] == key){
			printf("%d was found at index %d!\n", key, hash_value);
			return hash_value;
		}else if(A[hash_value] == 0){
			printf("%d is not in the hash table!\n", key);
			return -1;
		}
		++i;
	}
	printf("%d is not in the hash table!\n", key);
	return -1;
}

void printHash(int A[]){
	printf("Table size: %d\n", m);
	for (int i=0; i<m; ++i){
		if(A[i] != 0){
			printf("i: %d	key: %d\n", i, A[i]);
		}
	}
}



int main(){
	int HT[m];
	init(HT);
	insert(HT, 1313);
	insert(HT, 1314);
	insert(HT, 1315);
	insert(HT, 2000);
	insert(HT, 2001);
	insert(HT, 2002);
	
	printHash(HT);

	search(HT, 2000);
	search(HT, 10);
	search(HT, 1314);
	search(HT, 1313);
	search(HT, 337);
	
	return 0;
}
