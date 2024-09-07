#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __AVX__
#include <immintrin.h>
#endif

#include "vector.h"

void vec_add_naive(float *a, float *b, float *c, int len) {
  for (int i = 0; i < len; i++) {
    c[i] = a[i] + b[i];
  }
}

void vec_mul_naive(float *a, float *b, float *c, int len) {
  for (int i = 0; i < len; i++) {
    c[i] = a[i] * b[i];
  }
}

// Precondition: (len % 8) == 0
#ifdef __AVX__
void vec_add_avx(float *a, float *b, float *c, int len) {
  // fits 8 SP floats
  __m256 av, bv, cv;

  for (int s = 0; s < len; s += 8) {
    av = _mm256_set_ps(a[s + 7], a[s + 6], a[s + 5], a[s + 4], a[s + 3],
                       a[s + 2], a[s + 1], a[s]);
    bv = _mm256_set_ps(b[s + 7], b[s + 6], b[s + 5], b[s + 4], b[s + 3],
                       b[s + 2], b[s + 1], b[s]);
    cv = _mm256_add_ps(av, bv);
    _mm256_storeu_ps(c + s, cv);
  }
}
#endif

// Precondition: (len % 8) == 0
#ifdef __AVX__
void vec_mul_avx(float *a, float *b, float *c, int len) {
  __m256 av, bv, cv;
  for (int s = 0; s < len; s += 8) {
    av = _mm256_set_ps(a[s + 7], a[s + 6], a[s + 5], a[s + 4], a[s + 3],
                       a[s + 2], a[s + 1], a[s]);
    bv = _mm256_set_ps(b[s + 7], b[s + 6], b[s + 5], b[s + 4], b[s + 3],
                       b[s + 2], b[s + 1], b[s]);
    cv = _mm256_mul_ps(av, bv);
    _mm256_storeu_ps(c + s, cv);
  }
}
#endif

// Precondition: (len % 8) == 0
#ifdef __AVX__
void vec_mul_avx_omp(float *a, float *b, float *c, int len) {
  __m256 av, bv, cv;
  // #pragma omp parallel_for
  for (int s = 0; s < len; s += 8) {
    av = _mm256_set_ps(a[s + 7], a[s + 6], a[s + 5], a[s + 4], a[s + 3],
                       a[s + 2], a[s + 1], a[s]);
    bv = _mm256_set_ps(b[s + 7], b[s + 6], b[s + 5], b[s + 4], b[s + 3],
                       b[s + 2], b[s + 1], b[s]);
    cv = _mm256_mul_ps(av, bv);
    _mm256_storeu_ps(c + s, cv);
  }
}
#endif

void vec_check_add(float *a, float *b, float *c, int len) {
  for (int i = 0; i < len; i++) {
    assert(c[i] == a[i] + b[i]);
  }
}

void vec_check_mul(float *a, float *b, float *c, int len) {
  for (int i = 0; i < len; i++) {
    assert(c[i] == a[i] * b[i]);
  }
}
