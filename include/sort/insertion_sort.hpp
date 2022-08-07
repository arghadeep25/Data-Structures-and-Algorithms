/************************************
 * @file insertion.hpp
 * @details Insertion Sort Algorithm
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
/**
 * @brief Insertion Sort
 * @details Insertion Sort Class
 * @tparam DataType int or float or double
 */
template <typename DataType> class InsertionSort : public Sort<DataType> {
public:
  /**
   * @brief Constructor
   */
  explicit InsertionSort() = default;

private:
  DataType key;

public:
  /**
   * @brief Insertion Sort
   * @details Implementaiton of Insertion sort algorithm
   */
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