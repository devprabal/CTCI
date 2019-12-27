#include <iostream>
#include "printMatrix.h"
#include "createSqrMatrix.h"
using namespace std;

void rotateMatrix(int **mat, int n) {
  for (int layer = 0; layer < n / 2; layer++) {
    for (int row = layer; row < n - layer - 1; row++) {
      // save top
      int temp = mat[layer][row];
      // top -> left
      mat[layer][row] = mat[n - layer - 1 - row][layer];
      // left -> bottom
      mat[n - layer - 1 - row][layer] = mat[n - layer - 1][n - layer - 1 - row];
      // bottom -> right
      mat[n - layer - 1][n - layer - 1 - row] = mat[layer + row][n - 1 - layer];
      // right -> top
      mat[layer + row][n - 1 - layer] = temp;
    }
  }
}
int main(int argc, char const *argv[]) {
  int **mat = nullptr;
  int rows = 3, cols = 3;
  // cin >> rows >> cols;
  int n;
  if (rows != cols)
    // to know the exit status returned by the previous program in the terminal
    // type: echo $?
    exit(EXIT_FAILURE);
  else
    n = rows;
  
  mat = createSqrMatrix(3);
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[0][2] = 3;
  mat[1][0] = 4;
  mat[1][1] = 5;
  mat[1][2] = 6;
  mat[2][0] = 7;
  mat[2][1] = 8;
  mat[2][2] = 9;

  // int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  // no. of rows = sizeof mat / sizeof mat[0];
  // no. of cols = sizeof mat[0] / sizeof int
  printMatrix(mat, rows, cols);
  rotateMatrix(mat, n);
  printMatrix(mat, rows, cols);
  return 0;
}
