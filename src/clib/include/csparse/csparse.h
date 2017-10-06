#ifndef CSPARSE_H
#define CSPARSE_H

#include <stddef.h>

typedef struct dense_mat_st {
  double *data;
  size_t rows;
  size_t cols;
} dense_mat;

dense_mat *new_dense_mat(size_t r, size_t c);
void free_dense_mat(dense_mat *m);

void print_dense_mat(dense_mat *m);

double *dense_at(dense_mat *m, size_t r, size_t c);
size_t non_zero_count(dense_mat *m);
size_t row_non_zero_count(dense_mat *m, size_t r);

typedef struct sparse_mat_st {
  size_t rows;
  double *A;
  size_t *IA;
  size_t *JA;
} sparse_mat;

sparse_mat *new_sparse_mat(dense_mat *m);
void free_sparse_mat(sparse_mat *m);

void print_sparse_mat(sparse_mat *m);

void sparse_mul(sparse_mat *m, double *v, double *o);

#endif
