#include <CSR.h>

#include <cassert>
#include <sstream>

CSRMatrix::CSRMatrix(DOKMatrix d)
{
  size_t nnz = d.count();
  A.reserve(nnz);
  IA.reserve(d.rows() + 1);
  JA.reserve(nnz);

  for(auto i : d) {
    A.push_back(i.second);
    JA.push_back(i.first.col);
  }

  IA.push_back(0);
  for(size_t i = 0; i < d.rows(); ++i) {
    IA.push_back(IA[i] + d.non_zero_in_row(i));
  }
}

std::pair<size_t, size_t> CSRMatrix::extent(size_t i) const
{
  return { IA[i], IA[i+1] };
}

std::vector<double> CSRMatrix::row(size_t i) const
{
  std::vector<double> r(IA.size() - 1, 0);
  auto ex = extent(i);
  for(auto i = ex.first; i < ex.second; ++i) {
    r[JA[i]] = A[i];
  }

  return r;
}

std::vector<double> CSRMatrix::mul(std::vector<double> v) const
{
  assert(v.size() == IA.size() - 1 && "Incorrect vector size");
  std::vector<double> o(v.size(), 0);  

  // loop bounds are fixed; exactly one iteration through the entire input
  // vector, element by element. Upper and lower bounds are independent of the
  // iteration variable
  for(auto i = 0; i < o.size(); ++i) {
    // Two memory accesses to adjacent items in the same array determine the
    // row extent
    auto lower = IA[i];
    auto upper = IA[i+1];

    // Variable tracks the running sum for this output element
    double sum = 0.0;

    // fixed loop bounds from the accesses earlier
    for(auto j = lower; j < upper; ++j) {
      // Addition to running total, access pattern
      sum += A[j] * v[JA[j]];
    }

    // Store to the ith element of the output
    o[i] = sum;
  }

  return o;
}

std::string CSRMatrix::repr() const
{
  std::stringstream ss;

  ss << "A:  [";
  for(auto a : A) {
    ss << a << " ";
  }
  ss << "]\n";

  ss << "IA: [";
  for(auto ia : IA) {
    ss << ia << " ";
  }
  ss << "]\n";

  ss << "JA: [";
  for(auto ja : JA) {
    ss << ja << " ";
  }
  ss << "]";

  return ss.str();
}
