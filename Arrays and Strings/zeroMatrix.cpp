#include <iostream>
#include "createSqrMatrix.h"
#include "printMatrix.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int **mat = createSqrMatrix(3);
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[0][2] = 3;
  mat[1][0] = 4;
  mat[1][1] = 5;
  mat[1][2] = 6;
  mat[2][0] = 7;
  mat[2][1] = 8;
  mat[2][2] = 9;
  printMatrix(mat,3,3);
  return 0;
}
