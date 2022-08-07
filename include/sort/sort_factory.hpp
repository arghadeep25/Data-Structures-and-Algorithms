/************************************
 * @file sort_factory.hpp
 * @details Sort Factory
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include "sort/bubble_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/selection_sort.hpp"
#include <cstring>
#include <iostream>
#include <memory>

namespace dataStructure::sort {
template <typename DataType>
std::unique_ptr<Sort<DataType>> sortMethod(const char *sortType) {
  if (!std::strcmp(sortType, "Selection_Sort"))
    return std::make_unique<SelectionSort<DataType>>();
  else if (!std::strcmp(sortType, "Bubble_Sort"))
    return std::make_unique<BubbleSort<DataType>>();
  else if (!std::strcmp(sortType, "Insertion_Sort"))
    return std::make_unique<InsertionSort<DataType>>();
  else if (!std::strcmp(sortType, "Merge_Sort"))
    return std::make_unique<MergeSort<DataType>>();
  else
    return nullptr;
}
} // namespace dataStructure::sort
