#ifndef __VEC_H
#define __VEC_H

// Vector helpers
float *vec_zeros(int len);
float *vec_uninit(int len);
float *vec_rand(int len);
float *vec_asc(int len);
float *vec_fill(float val, int len);
void   vec_display(float *v, int len);
void   vec_free(float *v, ...);

// Vector math
void vec_add_naive(float *a, float *b, float *c, int len);

#endif
