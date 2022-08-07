/************************************
 * @file selection_sort.hpp
 * @details Selection Sort Algorithm
 *         Time Complexity: O(N^2)
 *         Space Complexity: O(1)
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <iostream>

namespace dataStructure::sort {
template <typename DataType> class SelectionSort : public Sort<DataType> {
public:
  explicit SelectionSort() = default;

public:
  // Function to sort the vector
  void sort() override {
    if (this->data.size() <= 1)
      return;
    for (int i = 0; i < this->data.size() - 1; i++) {
      DataType min = i;
      for (int j = i + 1; j < this->data.size(); j++)
        if (this->data.at(min) > this->data.at(j))
          min = j;
      DataType key = this->data.at(min);
      while (min > i) {
        this->data.at(min) = this->data.at(min - 1);
        min--;
      }
      this->data.at(i) = key;
    }
  }
};
} // namespace dataStructure::sort
