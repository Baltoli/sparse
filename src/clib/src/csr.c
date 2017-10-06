#include "csparse/csparse.h"

#include <stdio.h>
#include <stdlib.h>

dense_mat *new_dense_mat(size_t r, size_t c)
{
  dense_mat *ret = malloc(sizeof(*ret));
  ret->rows = r;
  ret->cols = c;
  ret->data = calloc(r * c, sizeof(*(ret->data)));

  return ret;
}

void free_dense_mat(dense_mat *m)
{
  if(m && m->data) {
    free(m->data);
  }

  if(m) {
    free(m);
  }
}

void print_dense_mat(dense_mat *m)
{
  for(size_t i = 0; i < m->rows; ++i) {
    for(size_t j = 0; j < m->cols; ++j) {
      printf("%.2f\t", *dense_at(m, i, j));
    }
    printf("\n");
  }
}

double *dense_at(dense_mat *m, size_t r, size_t c)
{
  return &(m->data[r*m->cols + c]);
}

size_t non_zero_count(dense_mat *m)
{
  size_t count = 0;
  for(size_t i = 0; i < (m->cols * m->rows); ++i) {
    count += (m->data[i] != 0 ? 1 : 0);
  }
  return count;
}

size_t row_non_zero_count(dense_mat *m, size_t r)
{
  size_t count = 0;
  for(size_t c = 0; c < m->cols; ++c) {
    count += (m->data[r*m->cols + c] != 0 ? 1 : 0);
  }
  return count;
}

sparse_mat *new_sparse_mat(dense_mat *m)
{
  size_t nnz = non_zero_count(m);

  sparse_mat *ret = malloc(sizeof(*ret));
  ret->rows = m->rows;
  ret->A = calloc(nnz, sizeof(*(ret->A)));
  ret->IA = calloc(m->rows + 1, sizeof(*(ret->IA)));
  ret->JA = calloc(nnz, sizeof(*(ret->JA)));

  size_t j = 0;
  for(size_t i = 0; i < (m->rows * m->cols); ++i) {
    if(m->data[i] != 0) {
      ret->A[j] = m->data[i];
      ret->JA[j] = i % m->cols;
      j++;
    }
  }

  for(size_t i = 1; i < m->rows + 1; ++i) {
    ret->IA[i] = ret->IA[i - 1] + row_non_zero_count(m, i - 1);
  }

  return ret;
}

void free_sparse_mat(sparse_mat *m)
{
  if(!m) {
    return;
  }

  if(m->A) {
    free(m->A);
  }

  if(m->IA) {
    free(m->IA);
  }

  if(m->JA) {
    free(m->JA);
  }
}

void sparse_mul(sparse_mat *m, double *v, double *o)
{
  for(size_t i = 0; i < m->rows; ++i) {
    size_t lower = m->IA[i];
    size_t upper = m->IA[i+1];

    double sum = 0;
    for(size_t j = lower; j < upper; ++j) {
      sum += m->A[j] * v[m->JA[j]];
    }
    o[i] = sum;
  }
}

void print_sparse_mat(sparse_mat *m)
{
  size_t nnz = m->IA[m->rows];

  printf("A:  [ ");
  for(size_t i = 0; i < nnz; ++i) {
    printf("%.2f ", m->A[i]);
  }
  printf("]\n");

  printf("IA: [ ");
  for(size_t i = 0; i < m->rows + 1; ++i) {
    printf("%zu ", m->IA[i]);
  }
  printf("]\n");

  printf("JA: [ ");
  for(size_t i = 0; i < nnz; ++i) {
    printf("%zu ", m->JA[i]);
  }
  printf("]\n");
}
