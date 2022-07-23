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
  bool swapped;

public:
  void sort() override {
    if (this->data.size() <= 1)
      return;
    for (int idx1 = 0; idx1 < this->data.size() - 1; idx1++) {
      swapped = false;
      for (int idx2 = 0; idx2 < this->data.size() - idx1 - 1; idx2++) {
        if (this->data.at(idx2) > this->data.at(idx2 + 1)) {
          std::swap(this->data.at(idx2), this->data.at(idx2 + 1));
          swapped = true;
        }
      }
      if (!swapped)
        break;
    }
  }
};
} // namespace dataStructure::sort