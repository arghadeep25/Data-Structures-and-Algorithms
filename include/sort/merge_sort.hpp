/************************************
 * @file merge_sort.hpp
 * @details Merge Sort Algorithm
 *         Time Complexity: O(NlogN)
 *         Space Complexity: O(1)
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <algorithm>
#include <iostream>

namespace dataStructure::sort {
/**
 * @brief Merge Sort Algorithm
 * @details Class for Merge Sort Algorithm
 * @tparam DataType
 */
template <typename DataType> class MergeSort : public Sort<DataType> {
public:
  explicit MergeSort() = default;

private:
  /**
   * @brief Merge Sort Implementation
   * @details Function to perform merge sort
   * @tparam Iterator Iterator
   * @param first begin iterator of a vector
   * @param last end iterator of a vector
   */
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
  /**
   * @brief Sort function
   * @details Public function inherited from Sort base class
   */
  void sort() override {
    if (this->data.size() <= 1)
      return;
    typename std::vector<DataType>::iterator first = this->data.begin();
    typename std::vector<DataType>::iterator last = this->data.end();
    mergesort(first, last);
  }
};
} // namespace dataStructure::sort