#include <sparse/sparse.h>

#include <iostream>

int main()
{
  DOKMatrix d{
    {{0, 0}, 0.2},
    {{1, 0}, 1.0},
    {{1, 5}, 3.11},
    {{3, 2}, 54.2}
  };

  std::cout << d.rows() << " rows\n";
  std::cout << d.columns() << " columns" << std::endl;

  std::cout << d.repr();
  return 0;
}
