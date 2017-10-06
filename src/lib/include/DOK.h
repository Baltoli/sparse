#ifndef DOK_H
#define DOK_H

#include <index.h>

#include <map>

class DOKMatrix {
  using map_t = std::map<Index, double>;

public:
  using iterator = map_t::iterator;

  DOKMatrix(std::initializer_list<map_t::value_type> l) :
    entries_(l) {}

  DOKMatrix(std::map<Index, double> e) :
    entries_(e) {}

  size_t rows() const;
  size_t columns() const;
  size_t count() const;
  size_t non_zero_in_row(size_t row) const;

  double operator[](Index i) const;

  std::string repr() const;

  iterator begin() { return std::begin(entries_); }
  iterator end() { return std::end(entries_); }

protected:
  map_t entries_;
};

#endif
