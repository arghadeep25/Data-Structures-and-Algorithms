//============================================================================
// Name        : sort_factory.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Sort Algorithm Factory
//============================================================================
#pragma once

#include "sort/selection_sort.hpp"
#include <cstring>
#include <iostream>
#include <memory>

namespace dataStructure::sort {
template <typename DataType>
std::unique_ptr<Sort<DataType>> sortMethod(const char *sortType) {
  if (!std::strcmp(sortType, "Selection_Sort"))
    return std::make_unique<SelectionSort<DataType>>();
  else
    return nullptr;
}
} // namespace dataStructure::sort
