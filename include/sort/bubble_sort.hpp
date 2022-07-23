//============================================================================
// Name        : bubble_sort.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Bubble Sort Algorithm
// Time Complexity: O(N^2)
// Space Complexity: O(1)
//============================================================================
#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <iostream>

namespace dataStructure::sort {
template <typename DataType> class BubbleSort : public Sort<DataType> {
public:
  explicit BubbleSort() = default;

private:
  void bubblesort(std::vector<DataType> &data, int size) {
    if (size <= 1)
      return;
    for (int idx = 0; idx < size - 1; idx++) {
      if (data[idx] > data[idx + 1])
        std::swap(data[idx], data[idx + 1]);
    }
    bubblesort(data, size - 1);
  }

public:
  void sort() override {
    if (this->data.size() <= 1)
      return;
    bubblesort(this->data, this->data.size());
  }
};
} // namespace dataStructure::sort