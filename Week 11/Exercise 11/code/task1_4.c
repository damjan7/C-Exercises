// A dynamic programming solution to LPS Problem

#include <stdio.h>

int strLength(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
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

int lps(char s[], int n) {
  int i, j;
  // n is the length of substring
  int k;
  int L[n][n];
  // The diagonal of L denotes the string of length 1
  // They are of course palindrome of length 1
  for (i = 0; i < n; i++) {
    L[i][i] = 1;
  }
  for (k = 2; k <= n; k++) {
    for (i = 0; i < n - k + 1; i++) {
      j = i + k - 1;
      if (s[i]==s[j] && k == 2) {
          L[i][j] = 2;
      } else if (s[i]==s[j]) {
          L[i][j] = L[i+1][j-1]+2;
      } else {
          L[i][j] = max(L[i][j-1], L[i+1][j]);
      }
    }
  }
  return L[0][n-1];
}

int main() {
    char s[100];
    int length;
    printf("Please enter a string: ");
    scanf("%[^\n]s", s);
    length = strLength(s);
    printf("The length of longest palindromic subsequence is %d\n", lps(s, length-1));
    return 0;
}

// Linux, Mac: gcc task1_1.c -o task1_1; ./task1_1