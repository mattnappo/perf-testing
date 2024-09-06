#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "log.h"
#include "vector.h"

#define LOG_LEVEL LOG_LEVEL_DEBUG


int main(int argc, char **argv)
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

    LOG_DEBUG("running with num_procs=%d\n", num_procs);

    int n = 32;

    float *a = vec_rand(n);
    float *b = vec_rand(n);
    float *c = vec_init(n);
    run_with_procs(a, b, c);

    return 0;
}
