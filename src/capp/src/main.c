#include <csparse/csparse.h>

#include <stdio.h>

int main(void)
{
  dense_mat *m = new_dense_mat(4, 4);

  *dense_at(m, 0, 0) = 1;
  *dense_at(m, 1, 1) = 1;
  *dense_at(m, 2, 2) = 1;
  *dense_at(m, 3, 3) = 1;
  
  print_dense_mat(m);

  sparse_mat *c = new_sparse_mat(m);
  print_sparse_mat(c);

  double v[4] = {1, 2, 3, 4};
  double o[4];

  sparse_mul(c, v, o);
  
  printf("v: [");
  for(size_t i = 0; i < m->rows; ++i) {
    printf("%.2f ", v[i]);
  }
  printf("]\n");

  printf("o: [");
  for(size_t i = 0; i < m->rows; ++i) {
    printf("%.2f ", o[i]);
  }
  printf("]\n");

  return 0;
}
