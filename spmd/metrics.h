#ifndef __METRICS_H
#define __METRICS_H

typedef void (*vec_kernel_t)(float*, float*, float*, int);

struct timespec timeit3(vec_kernel_t kern,
                        char *label, float *a, float *b, float *c, int len);

#endif
