#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "vector.h"

void vec_add_naive(float *a, float *b, float *c, int len)
{
    for (int i = 0; i < len; i++) {
        c[i] = a[i] + b[i];
    }
}

void vec_check_add(float *a, float *b, float *c, int len)
{
    for (int i = 0; i < len; i++) {
        assert(c[i] == a[i] + b[i]);
    }
}
