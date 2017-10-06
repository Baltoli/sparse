#ifndef CSR_H
#define CSR_H

#include <DOK.h>

#include <vector>

class CSRMatrix {
public:
  CSRMatrix(DOKMatrix d);

  std::string repr() const;
private:
  std::vector<double> A;
  std::vector<size_t> IA;
  std::vector<size_t> JA;
};

#endif
