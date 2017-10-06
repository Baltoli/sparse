#include <sparse/sparse.h>

#include <iostream>

int main()
{
  DOKMatrix d{
    {{1, 0}, 5},
    {{1, 1}, 8},
    {{2, 2}, 3},
    {{3, 1}, 6},
    {{3, 3}, 0}
  };

  CSRMatrix c(d);
  std::cout << c.repr() << '\n';
  std::cout << d.repr();
  return 0;
}
