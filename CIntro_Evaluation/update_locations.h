#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef float TYPE;

TYPE * generate_random_array (int size, float bound);
void update_coords (int size, TYPE * xs, TYPE * ys, TYPE * zs, TYPE * vx, TYPE * vy, TYPE * vz);
TYPE summ (int size, TYPE * s);
int main(int argc, char * argv[]);
int atoi(const char * str);
