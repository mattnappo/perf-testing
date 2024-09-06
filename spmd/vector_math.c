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

// TODO: alignment
// Precondition: (len % 8) == 0
void vec_add_avx(float *a, float *b, float *c, int len)
{
#ifndef __AVX__
    fprintf(stderr, "AVX not supported.\n");
    exit(1);
#endif

    // fits 8 SP floats
    __m256 av, bv, cv;

    for (int s = 0; s < len; s += 8) {
        av = _mm256_set_ps(a[s+7], a[s+6], a[s+5], a[s+4],
                                  a[s+3], a[s+2], a[s+1], a[s]);
        bv = _mm256_set_ps(b[s+7], b[s+6], b[s+5], b[s+4],
                                  b[s+3], b[s+2], b[s+1], b[s]);
        cv = _mm256_add_ps(av, bv);
        _mm256_storeu_ps(c+s, cv);
    }
}

void vec_check_add(float *a, float *b, float *c, int len)
{
    for (int i = 0; i < len; i++) {
        assert(c[i] == a[i] + b[i]);
    }
}
