#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "log.h"
#include "vector.h"

#define LOG_LEVEL LOG_LEVEL_DEBUG

void bench_add()
{
    int sizes[] = {8, 16, 32, 64, 1024, 4096, 16384, 0};
    bench_config_t conf = {
        .iters = 10000,
        .sizes = sizes
    };
#ifdef __AVX__
    bench_kernel(vec_add_avx, vec_check_add, conf);
#else
    bench_kernel(vec_add_naive, vec_check_add, conf);
#endif
}

void bench_mul()
{
    int sizes[] = {8, 16, 32, 64, 1024, 4096, 16384, 0};
    bench_config_t conf = {
        .iters = 10000,
        .sizes = sizes
    };
#ifdef __AVX__
    bench_kernel(vec_mul_avx, vec_check_mul, conf);
#else
    bench_kernel(vec_mul_naive, vec_check_mul, conf);
#endif
}

int main(int argc, char **argv)
{
    bench_add();
    bench_mul();

    return 0;
}
