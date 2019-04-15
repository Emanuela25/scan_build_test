#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
//ARR30-1

static int matrix[ROWS][COLS];

void init_matrix(int x) {
  for (size_t i = 0; i < COLS; i++) {
    for (size_t j = 0; j < ROWS; j++) {
      matrix[i][j] = x;
    }
  }
} 

//ARR30-2
enum { TABLESIZE = 100 };

static int table[TABLESIZE];
 
int *f_arr(int index) {
  if (index < TABLESIZE) {
    return table + index;
  }
  return NULL;
}

void arr_main() {
    init_matrix(0);
    int* n = f_arr(-1);
    printf("%d\n", *n);
    return;
}

