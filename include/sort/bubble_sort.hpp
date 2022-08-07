/************************************
* @file bubble_sort.hpp
* @details Bubble Sort Algorithm
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
 * @brief Bubble Sort
 * @details Bubble Sort Algorithm Class
 * @tparam DataType
 */
template <typename DataType> class BubbleSort : public Sort<DataType> {
public:
  explicit BubbleSort() = default;

private:
  /**
   * @brief Bubble Sort Algorithm
   * @details Recursive implementation of Bubble Sort Algorithm
   * @param data Vector of unsorted data
   * @param size Size of data
   */
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
  /**
   * @details Public function for sorting
   */
  void sort() override {
    if (this->data.size() <= 1)
      return;
    bubblesort(this->data, this->data.size());
  }
};
} // namespace dataStructure::sort