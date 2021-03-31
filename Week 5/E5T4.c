#include <stdio.h>

void Arraydisplay(int A[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
  printf("\n");
}

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

int find_kth_nr(int A[], int k, int l, int r){
	int m = Partition(A, l, r); //A[m] is the (r-m+1)'th biggest number
	Arraydisplay(A, r+1);
	int orig_r = r;
	int orig_l = l;
	while (1==1){
	if (k == orig_r-m+1){
		return A[m];
	}
	else if (k < orig_r-m+1){
		l = m+1;
		if (l == r){
			return A[l];
		}
		m = Partition(A, l, r);
		
	}
	else if (k > orig_r-m+1){
		r = m-1;
		if (l == r){
			return A[l];
		}
		
		m = Partition(A, l, r);
	//	printf("%d ", m);
	}		
	}


}

int main(){
	//int arr1[] = {3,2,1,5,6,4};
	//int res1 = find_kth_nr(arr1, 2, 0, 5);
	//printf("%d", res1);
	
	printf("\n");
	int arr2[] = {3,2,3,1,2,4,5,5,6};
	int res2 = find_kth_nr(arr2, 6, 0, 8);
	printf("%d", res2);

}
