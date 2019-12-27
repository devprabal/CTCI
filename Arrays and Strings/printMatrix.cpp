#include<iostream>
#include "printMatrix.h"
// TODO: is this correct method for nxn matrix to be passed or not?
void printMatrix(int **mat, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      std::cout << mat[i][j] << " ";
    std::cout << '\n';
  }
  std::cout << '\n';
}