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
  for(auto i = 0; i < 4; ++i) {
    std::cout << c.extent(i).first << ", " << c.extent(i).second << '\n';
  }
  std::cout << d.repr();

  for(auto e : c.row(3)) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  return 0;
}
