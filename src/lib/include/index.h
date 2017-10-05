#ifndef INDEX_H
#define INDEX_H

#include <cstddef>
#include <initializer_list>

struct Index {
  Index(size_t, size_t);

  const size_t row;
  const size_t col;

  bool operator<(const Index other) const {
    return row < other.row || (row == other.row && col < other.col);
  }
};

#endif
