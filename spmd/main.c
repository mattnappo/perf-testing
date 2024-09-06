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

int main(int argc, char **argv)
{
    // test_1();
    // test_2();
    test_3();

    return 0;
}
