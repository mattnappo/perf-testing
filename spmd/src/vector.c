#include "vector.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

float *vec_zeros(int len) {
  float *v = calloc(sizeof(float), len);
  return v;
}

float *vec_uninit(int len) {
  float *v = malloc(sizeof(float) * len);
  return v;
}

float *vec_rand(int len) {
  float *v = vec_uninit(len);
  for (int i = 0; i < len; i++) {
    v[i] = (float)rand() / RAND_MAX;
  }
  return v;
}

float *vec_asc(int len) {
  float *v = vec_uninit(len);
  for (int i = 0; i < len; i++)
    v[i] = i;
  return v;
}

float *vec_fill(float val, int len) {
  float *v = vec_uninit(len);
  for (int i = 0; i < len; i++)
    v[i] = val;
  return v;
}

// TODO: can read from $COLUMNS and $LINES, and can add tabs/alignment.
void vec_display(float *v, int len) {
  printf("{ ");
  for (int i = 0; i < len - 1; i++) {
    printf("%0.4f ", v[i]);
  }
  printf("%0.4f }\n", v[len - 1]);
}

void vec_free(float *v, ...) {
  va_list args;
  va_start(args, v);
  float *to_free = v;
  while (to_free) {
    free(to_free);
    to_free = va_arg(args, float *);
  }
  va_end(args);
}
