//============================================================================
// Name        : merge_sort.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Merge Sort Algorithm
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
//============================================================================
#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <algorithm>
#include <iostream>

namespace dataStructure::sort {
template <typename DataType> class MergeSort : public Sort<DataType> {
public:
  explicit MergeSort() = default;

private:
  template <typename Iterator> void mergesort(Iterator first, Iterator last) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type
        difference_type;

    difference_type n = std::distance(first, last) / 2;
    if (n <= 1)
      return;
    mergesort(first, first + n);
    mergesort(first + n, last);
    std::vector<value_type> merged(std::distance(first, last));
    std::merge(first, first + n, first + n, last, merged.begin());
    std::copy(merged.begin(), merged.end(), first);
  }

public:
  void sort() override {
    if (this->data.size() <= 1)
      return;
    typename std::vector<DataType>::iterator first = this->data.begin();
    typename std::vector<DataType>::iterator last = this->data.end();
    mergesort(first, last);
  }
};
} // namespace dataStructure::sort