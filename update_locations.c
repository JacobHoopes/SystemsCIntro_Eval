 /*   #!/usr/bin/env python3

    import random, sys, timeit, psutil

    ###############
    # Create a list of 'size' floating point numbers in the range [-bound, bound]
    def generate_random_list(size, bound):
        return [random.uniform(-bound, bound) for i in range(size)]

*/

/*

    ###############
    # Update position by velocity, one time-step
    def update_coords(xs, ys, zs, vx, vy, vz):
        for i in range(len(xs)):
            xs[i] = xs[i] + vx[i]
            ys[i] = ys[i] + vy[i]
            zs[i] = zs[i] + vz[i]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    
    printf("The argument supplied is: %s\n", argv[1]);
    printf("The next argument supplied is: %s\n", argv[2]);
    /*printf("The length of the argument is %lu\n", strlen(*argv));
    if (strlen(argv) != 3) {
        printf("Required arguments: vector_length(N) and iterations_num(M)");
    }*/
    int size = (int) argv[1];
    int iters = (int) argv[2];
    srand(time(NULL));
    int16_t generate_random_list(int size, float bound){
        float new = rand() % bound;
    }

    


    void update_coords(xs, ys, zs, vx, vy, vz) {
        for (i = 0; i < xs; i++) {
            xs[i] = xs[i] + vx[i];
            ys[i] = ys[i] + vy[i];
            zs[i] = zs[i] + vz[i];
        }
    }
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    sleep(2);
    update_coords()
    float chksum = sum(xs) + sum(ys) + sum(zs);
    printf("Mean time per coordinate: %f us\n", str(1000000 * t / (size * iters)));
    printf("Final checksum is: %s\n", str(chksum));
    clock_gettime(CLOCK_MONOTONIC, &stop);
    double total_time = (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec)/((double) 1000000000);
    printf("Total time = %f\n", total_time);
}

/*
    ############ Main:
    if (len(sys.argv) != 3):
        print("Required arguments: vector_length(N) and iterations_num(M)")
        sys.exit(-1)
    size = int(sys.argv[1])
    iters = int(sys.argv[2])
    random.seed(size)
    xs = generate_random_list(size, 1000.)
    ys = generate_random_list(size, 1000.)
    zs = generate_random_list(size, 1000.)
    vx = generate_random_list(size, 1.)
    vy = generate_random_list(size, 1.)
    vz = generate_random_list(size, 1.)
    t = timeit.timeit(stmt = "update_coords(xs, ys, zs, vx, vy, vz)",
        setup = "from __main__ import update_coords, xs, ys, zs, vx, vy, vz",
        number = iters)
    chksum = sum(xs) + sum(ys) + sum(zs)
    print("Mean time per coordinate: " + str(1000000 * t / (size * iters)) + "us")
    print("Final checksum is: " + str(chksum))
    print(psutil.virtual_memory())
    exit(0)

*/
