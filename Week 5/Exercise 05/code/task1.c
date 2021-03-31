#include <stdio.h>
  
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(int A[], int i, int n) {
  int m = i;
  int l = 2 * i;
  int r = 2 * i + 1;

  if (l < n && A[l] > A[m])
    m = l;

  if (r < n && A[r] > A[m])
    m = r;

  if (m != i) {
    swap(&A[i], &A[m]); // exchange A[i] and A[m];
    heapify(A, m, n);
  }
}

void buildHeap(int A[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(A, i, n);
}

void heapSort(int A[], int n) {
  buildHeap(A, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(&A[0], &A[i]);
    heapify(A, i, 0);
  }
}

void display(int A[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
  int A[] =  {4,3,5,7,2,1,9,23,53,16,4,3,6,76,2,8,43,9};

  int n = sizeof(A) / sizeof(A[0]);
  printf("%d", n);

  printf("Original Array:\n");
  display(A, n);
  
  buildHeap(A, n);
  printf("After buildHeap:\n");
  display(A, n);

  //optional, heap sort.
  heapSort(A, n);
  printf("[optional]Sorted array:\n");
  display(A, n);
}
