#include <iostream>
#include "createSqrMatrix.h"
int **createSqrMatrix(int n) {
  int **mat = new int *[n];
  for (int i = 0; i < n; i++) {
    mat[i] = new int[n];
  }
  return mat;
}