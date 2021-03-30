#include <stdio.h>

/**
 * Draws a square cross pattern on the screen using the characters
 * 'X' and '.' with spaces inbetween
 *
 * @param  size  The size of the cross which shall be drawn
 * @pre    size > 0 (size has to be strictly positive as a precondition)
 */
void drawCrossNestedLoop(int size) {
  char myFigure[size][size];
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row == col || row == size - col - 1) {
        myFigure[row][col] = 'X';
      }
      else {
        myFigure[row][col] = '.';
      }
      printf("%c ", myFigure[row][col]);
    }
    printf("\n");
  }
}

void drawCrossSingleLoop(int size) {
  /* We change indexing from (row, col) to continous indexes i from
     i = 1 to i = size^2. The row number then is given as i / size
     and column number is given as i % size and these formulas can
     be substituted for row and col in the nested loop version */
  for (int i = 0; i < size * size; i++) {
    if (i > 0 && i % size == 0) {
      printf("\n");
    }
    if ((i / size == i % size) || (i % size == size - i / size - 1)) {
      printf("X ");
    }
    else {
      printf(". ");
    }
  }
}

int main() {
  drawCrossNestedLoop(7);
  printf("\n");
  drawCrossSingleLoop(7);
  return 0;
}
