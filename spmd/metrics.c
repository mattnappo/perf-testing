#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "vector.h"

struct timespec time_kernel(vec_kernel_t kern,
                            char *label, float *a, float *b, float *c, int len)
{
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    kern(a, b, c, len);
    clock_gettime(CLOCK_MONOTONIC, &t1);

    time_t secs = t1.tv_sec - t0.tv_sec;
    long nanos = t1.tv_nsec - t0.tv_nsec;
    if (label) {
        printf("ran '%s' in %lds %ld ns\n", label, secs, nanos);
    } else {
        printf("%lds %ld ns\n", secs, nanos);
    }
    return (struct timespec) {
        .tv_sec = secs,
        .tv_nsec = nanos,
    };
}

// Benchmark a kernel on random vectors.
void bench_kernel(vec_kernel_t kern, char *label, bench_config_t conf)
{
    float *a, *b, *c;
    int *len = conf.sizes;

    printf("benchmarking '%s'\n", label);
    while (*len) {
        printf("running on len = %d\n", *len);
        // TODO: should use diff vectors each iteration? probably...
        a = vec_rand(*len);
        b = vec_rand(*len);
        c = vec_rand(*len);

        for (int i = 0; i < conf.iters; i++) {
            // TODO: pick up average
            printf("[%d] ", i);
            time_kernel(kern, NULL, a, b, c, *len);
            vec_check_add(a, b, c, *len);
        }
        vec_free(a, b, c, NULL);
        ++len;
    }
}

bench_config_t default_bench_config()
{
    int sizes[] = DEFAULT_BENCHMARK;
    int n = sizeof(sizes)/sizeof(*sizes);
    int *sizes_heap = calloc(sizeof(int), n);
    memcpy(sizes_heap, sizes, n*sizeof(int));
    return (bench_config_t) {
        .iters = 5,
        .sizes = sizes_heap
    };
}

void bench_config_free(bench_config_t conf)
{
    free(conf.sizes);
}
