int Partition(int A[], int l, int r){
	int tmp;
	int x = A[l];
	int i = l;
	for (int j=l+1; j<=r; ++j){
		if (A[j] <= x){
			++i;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i];
	A[i] = A[l];
	A[l] = tmp;
	return i; 
}


int main(){
	int arr[] = {3,2,3,1,2,4,5,5,6};
	for (int k=0; k<=8; ++k){
		printf("%d ", arr[k]);
	}
	
	printf("\n");
	int c = Partition(arr, 0, 8);
		for (int k=0; k<=8; ++k){
		printf("%d ", arr[k]);
	}
	printf("\n");	
	int b = Partition(arr, 6, 8);
			for (int k=0; k<=8; ++k){
		printf("%d ", arr[k]);
	}
	printf("\n");
	printf("c: %d", c);
	printf("\n");
	printf("b: %d", b);
	return 0;
}
