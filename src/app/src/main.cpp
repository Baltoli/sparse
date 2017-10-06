#include <sparse/sparse.h>

#include <iostream>

int main()
{
  DOKMatrix d{
    {{1, 1}, 1},
    {{2, 0}, 1},
    {{2, 1}, 2},
    {{2, 2}, 1},
  };

  CSRMatrix c(d);
  std::cout << c.repr() << '\n';
  std::cout << d.repr();

  std::vector<double> v{3, 2.2, 0.1};
  auto p = c.mul(v);
  for(auto pe : p) {
    std::cout << pe << " ";
  }
  std::cout << '\n';

  return 0;
}
