#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vector.h"

struct timespec time_kernel(vec_kernel_t kern, char *label, float *a, float *b,
                            float *c, int len) {
  struct timespec t0, t1;
  clock_gettime(CLOCK_MONOTONIC, &t0);
  kern(a, b, c, len);
  clock_gettime(CLOCK_MONOTONIC, &t1);

  time_t secs = t1.tv_sec - t0.tv_sec;
  long nanos = t1.tv_nsec - t0.tv_nsec;
  if (label) {
    printf("ran '%s' in %lds %ld ns\n", label, secs, nanos);
  }
  return (struct timespec){
      .tv_sec = secs,
      .tv_nsec = nanos,
  };
}

// Benchmark a kernel on random vectors.
void _bench_kernel(vec_kernel_t kern, vec_kernel_t check, char *label,
                   bench_config_t conf) {
  float *a, *b, *c;
  int *len = conf.sizes;

  printf("benchmarking '%s'\n", label);
  while (*len) {
    printf("running on len = %d\n", *len);
    // TODO: should use diff vectors each iteration? probably...
    a = vec_rand(*len);
    b = vec_rand(*len);
    c = vec_rand(*len);

    float avg = 0.0;
    for (int i = 0; i < conf.iters; i++) {
      struct timespec t = time_kernel(kern, NULL, a, b, c, *len);
      if (t.tv_sec > 0) {
        fprintf(stderr, "add was too slow (> 1s)");
        exit(1);
      }
      avg += (float)t.tv_nsec;

      check(a, b, c, *len);
    }
    avg /= (float)conf.iters;
    printf("avg: %f ns\n", avg);
    vec_free(a, b, c, NULL);
    ++len;
  }
}

bench_config_t default_bench_config() {
  int sizes[] = DEFAULT_BENCHMARK;
  int n = sizeof(sizes) / sizeof(*sizes);
  int *sizes_heap = calloc(sizeof(int), n);
  memcpy(sizes_heap, sizes, n * sizeof(int));
  return (bench_config_t){.iters = 5, .sizes = sizes_heap};
}

void bench_config_free(bench_config_t conf) { free(conf.sizes); }
