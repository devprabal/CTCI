#include"random_x_y.h"
#include <cstdlib>
int random_x_y(int lower, int upper){
  return lower+rand()%(upper - lower);
}