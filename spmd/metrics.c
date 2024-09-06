#include <stdio.h>
#include <time.h>

#include "metrics.h"

struct timespec timeit3(vec_kernel_t kern, char *label, float *a, float *b, float *c, int len)
{
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    kern(a, b, c, len);
    clock_gettime(CLOCK_MONOTONIC, &t1);

    time_t secs = t1.tv_sec - t0.tv_sec;
    long nanos = t1.tv_nsec - t0.tv_nsec;
    printf("ran '%s' in %lds %ld ns\n", label, secs, nanos);
    return (struct timespec) {
        .tv_sec = secs,
        .tv_nsec = nanos,
    };
}
