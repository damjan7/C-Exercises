// Knapsack Problem where each item can be used only once.

#include <stdio.h>

const int MAX_LENGTH = 1000;

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

void Knapsack(int n, int capacity, int w[], int v[]) {
  int max_v[n + 1][capacity + 1];
  int i, j;
  // the entries in first column and the first row are always 0
  for (i = 0; i <= n; i++) {
    max_v[i][0] = 0;
  }
  for (j = 0; j <= capacity; j++) {
    max_v[0][j] = 0;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= capacity; j++) {
      if (w[i-1] > j) {
        max_v[i][j] = max_v[i - 1][j];
      } else {
        max_v[i][j] = max(max_v[i - 1][j - w[i-1]] + v[i-1], max_v[i - 1][j]);
      }
    }
  }
  printf("Max value: %d\n", max_v[n][capacity]);
  int max_value = max_v[n][capacity];
  int selected[n];
  j = capacity;

  /*
  print the table
  for (i=0;i<=n;i++) {
    for (j=0;j<=capacity;j++) {
      printf("%d ", max_v[i][j]);
    }
    printf("\n");
  }
  */
  // Now finds the selected items
  for (i = n; i >= 1; i--) {
    if (max_value==max_v[i-1][capacity]) {
      selected[i-1] = 0;
    } else {
      selected[i-1] = 1;
      max_value = max_value - v[i-1];
      capacity = capacity - w[i-1];
    }
  }
  printf("The selected items are (0 for not selected, 1 for selected): ");
  for (i = 0; i < n; i++) {
    printf("%d ", selected[i]);
  }
  printf("\n");
}

int main() {
  // number of items.
  int n;
  // capacity of the Knapsack.
  int capacity;
  // weight of each item.
  int w[MAX_LENGTH];
  // value of each item.
  int v[MAX_LENGTH];
  printf("Number of items: ");
  scanf("%d", &n);
  printf("Capacity of the Knapsack: ");
  scanf("%d", &capacity);
  printf("Weights of each item: ");
  int i = 0;
  while (i < n) {
    scanf("%d", &w[i]);
    i = i + 1;
  }
  printf("Value of each item: ");
  i = 0;
  while (i < n) {
    scanf("%d", &v[i]);
    i = i + 1;
  }
  Knapsack(n, capacity, w, v);
}

// Linux, Mac: gcc task2_1.c -o task2_1; ./task2_1