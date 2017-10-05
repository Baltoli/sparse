#ifndef DOK_H
#define DOK_H

#include <index.h>

#include <map>

class DOKMatrix {
  using map_t = std::map<Index, double>;

public:
  DOKMatrix(std::initializer_list<map_t::value_type> l) :
    entries_(l) {}

  DOKMatrix(std::map<Index, double> e) :
    entries_(e) {}

  size_t rows() const;
  size_t columns() const;

  double operator[](Index i) const;

  std::string repr() const;
private:
  map_t entries_;
};

#endif
