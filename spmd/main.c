#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "log.h"
#include "vector.h"

#define LOG_LEVEL LOG_LEVEL_DEBUG

int get_num_procs()
{
    char *num_procs_str = getenv("SPMD_NUM_PROCS");
    if (!num_procs_str) {
        fprintf(stderr, "please specify SPMD_NUM_PROCS\n");
        exit(EXIT_FAILURE);
    }
    errno = 0;
    int num_procs = (int) strtol(num_procs_str, NULL, 10);
    if (errno) {
        fprintf(stderr, "error converting\n");
        perror("strtol");
        exit(EXIT_FAILURE);
    }
    if (num_procs <= 0) {
        fprintf(stderr, "must have SPMD_NUM_PROCS > 0\n");
        exit(EXIT_FAILURE);
    }
    return num_procs;
}

void test_1()
{
    int num_procs = get_num_procs();
    LOG_DEBUG("running with num_procs=%d\n", num_procs);

    int n = 32;

    float *a = vec_rand(n);
    float *b = vec_rand(n);
    float *c = vec_zeros(n);
    vec_display(a, n);
    vec_display(b, n);
    vec_display(c, n);

    vec_free(a, b, c, NULL);
}

void test_2()
{
    int n = 16;
    float *a = vec_fill(2, n);
    float *b = vec_fill(3, n);
    float *c = vec_zeros(n);
    vec_display(a, n);
    vec_display(b, n);
    vec_display(c, n);

    time_kernel(vec_add_naive, "vec_add_naive", a, b, c, n);
    vec_display(c, n);

    vec_free(a, b, c, NULL);
}

void test_3()
{
    bench_config_t conf = default_bench_config();
    bench_kernel(vec_add_naive, "vec_add_naive", conf);
    bench_config_free(conf);
}

void test_4()
{
    int len = 16;
    float *a = vec_rand(len);
    float *b = vec_rand(len);
    float *c = vec_zeros(len);
    vec_add_avx(a, b, c, len);
    vec_check_add(a, b, c, len);
    vec_free(a, b, c, NULL);
}

void test_5()
{
    int sizes[] = {8, 16, 32, 64, 1024, 4096, 16384, 0};
    bench_config_t conf = {
        .iters = 10000,
        .sizes = sizes
    };
    bench_kernel(vec_add_naive, "naive", conf);
    bench_kernel(vec_add_avx,   "avx", conf);
}

int main(int argc, char **argv)
{
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    test_5();

    return 0;
}
