#ifndef __VEC_H
#define __VEC_H

#include <time.h>

#define DEFAULT_BENCHMARK {2, 4, 6, 0}
// #define DEFAULT_BENCHMARK {16, 32, 64, 128, 256, 512, 0}

/*** Vector auxiliaries ***/

float *vec_zeros(int len);
float *vec_uninit(int len);
float *vec_rand(int len);
float *vec_asc(int len);
float *vec_fill(float val, int len);
void vec_display(float *v, int len);
void vec_free(float *v, ...);

/*** Timing and benchmarking ***/

typedef struct bench_config {
  int iters;
  int *sizes;
} bench_config_t;

typedef void (*vec_kernel_t)(float *, float *, float *, int);

#define bench_kernel(_kern, _check, _conf)                                     \
  _bench_kernel(_kern, _check, #_kern, _conf)

struct timespec time_kernel(vec_kernel_t kern, char *label, float *a, float *b,
                            float *c, int len);
void _bench_kernel(vec_kernel_t kern, vec_kernel_t check, char *label,
                   bench_config_t conf);
bench_config_t default_bench_config();
void bench_config_free(bench_config_t conf);

/*** Vector math ***/

void vec_add_naive(float *a, float *b, float *c, int len);
void vec_mul_naive(float *a, float *b, float *c, int len);
void vec_add_avx(float *a, float *b, float *c, int len);
void vec_mul_avx(float *a, float *b, float *c, int len);

/*** Verification ***/

void vec_check_add(float *a, float *b, float *c, int len);
void vec_check_mul(float *a, float *b, float *c, int len);

#endif
