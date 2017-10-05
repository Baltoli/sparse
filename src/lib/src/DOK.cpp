#include <DOK.h>

#include <algorithm>
#include <iomanip>
#include <sstream>

size_t DOKMatrix::rows() const
{
  return std::max_element(std::begin(entries_), std::end(entries_),
    [](auto a, auto b) {
      return a.first.row < b.first.row;
    }
  )->first.row + 1;
}

size_t DOKMatrix::columns() const
{
  return std::max_element(std::begin(entries_), std::end(entries_),
    [](auto a, auto b) {
      return a.first.col < b.first.col;
    }
  )->first.col + 1;
}

double DOKMatrix::operator[](Index i) const
{
  auto v = entries_.find(i);
  if(v != std::end(entries_)) {
    return v->second;
  } else {
    return 0.0;
  }
}

std::string DOKMatrix::repr() const
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2);

  for(size_t r = 0; r < rows(); ++r) {
    for(size_t c = 0; c < columns(); ++c) {
      ss << (*this)[{r, c}] << '\t';
    }
    ss << '\n';
  }

  return ss.str();
}
