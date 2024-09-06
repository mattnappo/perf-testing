#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifdef __AVX__
    #include <immintrin.h>
#endif

#include "vector.h"

void vec_add_naive(float *a, float *b, float *c, int len)
{
    for (int i = 0; i < len; i++) {
        c[i] = a[i] + b[i];
    }
}

void vec_add_avx(float *a, float *b, float *c, int len)
{
#ifndef __AVX__
    fprintf(stderr, "AVX not supported.\n");
    exit(1);
#endif

    assert(len == 8); // TODO: for now

    // can fit 8 floats
    __m256 av = _mm256_set_ps(a[7], a[6], a[5], a[4],
                              a[3], a[2], a[1], a[0]);
    __m256 bv = _mm256_set_ps(b[7], b[6], b[5], b[4],
                              b[3], b[2], b[1], b[0]);
    // __m256 cv = _mm256_set1_ps(0.0);
    __m256 cv = _mm256_add_ps(av, bv);
    _mm256_storeu_ps(c, cv);
}

void vec_check_add(float *a, float *b, float *c, int len)
{
    for (int i = 0; i < len; i++) {
        assert(c[i] == a[i] + b[i]);
    }
}
