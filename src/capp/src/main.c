#include <csparse/csparse.h>

int main(void)
{
  dense_mat *m = new_dense_mat(4, 4);

  *dense_at(m, 1, 0) = 5;
  *dense_at(m, 1, 1) = 8;
  *dense_at(m, 2, 2) = 3;
  *dense_at(m, 3, 1) = 6;
  
  print_dense_mat(m);

  sparse_mat *c = new_sparse_mat(m);
  print_sparse_mat(c);
  return 0;
}
