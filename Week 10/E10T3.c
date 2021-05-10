#include <stdio.h>
#include <math.h>

#define m 7

void init(int A[], int n){//func should fill all slots of the HT with value 0
	for (int i=0; i<=n; ++i){
		A[i] = 0;
	}
}

int h(int k, int i){ //hashing fct, returns hashed key h(k)
	int h,h1,h2;
	int m2 = 6;
	h1 = (k % m) + 1;
	h2 = m2 - (k % m2);
	h = (h1 + i*h2)%m;
	return h;
} 

void insert(int A[], int key){ //inserts key into the HT A
	int probe = 0;
	int hash_value;
	while(1==1){
		hash_value = h(key, probe);
		if (A[hash_value] == 0){
			A[hash_value] = key;
			break;
		}else{
			probe += 1;
			if (probe >= m){
				printf("Hash Table is full!\n");
				return;
			}
		}
	}
	
}

int search(int A[], int key){
	int probe = 0;
	int hash_value;
	while(1){
		hash_value = h(key, probe);
		if (A[hash_value] == key){
			printf("Found key: %d at index: %d\n", key, hash_value);
			return hash_value;
		}else if(A[hash_value] == 0){
			printf("Key not found in hash table!\n");
			return -1;
		}
		++probe;
	}
}


void printHash(int A[]){
	printf("Table size: %d\n", m);
	int size = 0;
	int idx_arr[m] = {0};
	for (int i=0; i<m; ++i){
		if (A[i] != 0){
			idx_arr[size] = i;
			++size;
			printf("i: %d   key: %d\n", i, A[i]);
		}
	}
	
	//printf("Table size: %d\n", size);
	//for (int k=0; k<size; ++k){
	//	printf("i: %d   key: %d\n", idx_arr[k], A[idx_arr[k]]);
	//}
}

void printArr(int A[], int n){
	for (int i=0; i<n; ++i){
		printf("i: %d   key: %d\n", i, A[i]);
	}
}

int main(){
	int HT[7];
	init(HT, 7);
	insert(HT, 1313);
	insert(HT, 1314);
	insert(HT, 1315);
	insert(HT, 2000);
	insert(HT, 2001);
	insert(HT, 2002);
	printHash(HT);

	search(HT,2000);
	search(HT,10);
	search(HT,1314);
	search(HT,1313);
	search(HT,337);
	printHash(HT);

	return 0;
}
