#ifndef RANDOM_X_Y_H
#define RANDOM_X_Y_H
/**
 * @brief generates a pseudo random interger based on rand() function from cstdlib
 * 
 * @param lower the lower bound, inclusive
 * @param upper the upper bound, exclusive 
 * @return int the random number between lower and upper bounds
 */
int random_x_y(int lower=0, int upper=10);
#endif