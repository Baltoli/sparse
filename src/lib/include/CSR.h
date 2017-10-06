#ifndef CSR_H
#define CSR_H

#include <DOK.h>

#include <vector>

class CSRMatrix {
public:
  CSRMatrix(DOKMatrix d);

  std::pair<size_t, size_t> extent(size_t i) const;
  std::vector<double> row(size_t i) const;

  std::vector<double> mul(std::vector<double> v) const;

  std::string repr() const;
private:
  std::vector<double> A;
  std::vector<size_t> IA;
  std::vector<size_t> JA;
};

#endif
