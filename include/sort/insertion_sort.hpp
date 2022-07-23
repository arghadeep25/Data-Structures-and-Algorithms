//============================================================================
// Name        : insertion_sort.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Insertion Sort Algorithm
// Time Complexity: O(N^2)
// Space Complexity: O(1)
//============================================================================
#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <iostream>

namespace dataStructure::sort {
template <typename DataType> class InsertionSort : public Sort<DataType> {
public:
  explicit InsertionSort() = default;

private:
  DataType key;

public:
  void sort() override {
    if (this->data.size() <= 1)
      return;
    for (int idx = 1; idx < this->data.size(); idx++) {
      key = this->data.at(idx);
      while (idx - 1 >= 0 && this->data.at(idx - 1) > key) {
        std::swap(this->data.at(idx), this->data.at(idx - 1));
        idx--;
      }
      this->data.at(idx) = key;
    }
  }
};
} // namespace dataStructure::sort