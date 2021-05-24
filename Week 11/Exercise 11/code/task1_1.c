// A recursive solution to LPS Problem

#include <stdio.h>

int strLength(char A[]) {
  int i = 0;
  while (A[i] != '\0') {
    i++;
  }
  return i;
}

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int lps(char A[], int i, int j) {
  // If there is only one character.
  if (i == j) {
    return 1;
  }
  // If there are only two characters
  // and both are the same.
  if (i + 1 == j && A[i] == A[j]) {
    return 2;
  }
  // If the first and the last characters
  // are the same. Then the length of the LPS will be
  // lps(s, i+1, j-1) + 2
  if (A[i]==A[j]) {
      return lps(A, i+1, j-1)+2;
  }
  // Otherwise, the lps is the larger one of 
  // lps(s, i+1) and lps(s, j-1)
  return max(lps(A, i+1, j), lps(A, i, j-1)); 
}

int main() {
    char A[100];
    int length;
    printf("Please enter a string: ");
    scanf("%[^\n]s", A);
    length = strLength(A);
    printf("The length of longest palindromic subsequence is %d\n", lps(A, 0,length-1));
    return 0;
}

// Linux, Mac: gcc task1_1.c -o task1_1; ./task1_1