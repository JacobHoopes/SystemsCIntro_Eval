#include "update_locations.h"

TYPE * generate_random_array(int size, float bound) {
    TYPE * RA = malloc(size * sizeof(float)); //Array initialization
    for (int i = 0; i < size; i++) {
        RA[i] = ((float) rand() / ((float) RAND_MAX / ((2 * bound) + 1))) - bound;
    }
    return RA;
 }

void update_coords(int size, TYPE * xs, TYPE * ys, TYPE * zs, TYPE * vx, TYPE * vy, TYPE * vz) {
        for (int i = 0; i < size; i++) {
            xs[i] = xs[i] + vx[i];
            ys[i] = ys[i] + vy[i];
            zs[i] = zs[i] + vz[i];
        }
    }

TYPE summ (int size, TYPE * s) {
    TYPE sum = 0.;
    for (int i = 0; i < size; i++) {
        sum += s[i];
    }
    return sum;
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Required arguments: vector_length(N) and iterations_num(M)\n");
        return 1;
    }

    int size = atoi(argv[1]);
    int iters = atoi(argv[2]);

    srand(size); // Initial call to srand before generate_random_array call

    TYPE * xs = generate_random_array(size, 1000.); 
    TYPE * ys = generate_random_array(size, 1000.);
    TYPE * zs = generate_random_array(size, 1000.);
    TYPE * vx = generate_random_array(size, 1.);
    TYPE * vy = generate_random_array(size, 1.);
    TYPE * vz = generate_random_array(size, 1.);

    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < iters; i++) {
        update_coords(size, xs, ys, zs, vx, vy, vz);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);

    TYPE chksum = summ(size, xs) + summ(size, ys) + summ(size, zs);
    double start_time = (double) start.tv_sec * 1e6 + (double) start.tv_nsec * 1e-3;
    double stop_time = (double) stop.tv_sec * 1e6 + (double) stop.tv_nsec * 1e-3;

    double total_time = stop_time - start_time;

    printf("Mean time per coordinate: %f us\n", total_time / (size * iters));
    printf("Final checksum is: %f\n", chksum); // This is the only line that needs to change for float/double and various int conversions.
}
