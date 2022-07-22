//============================================================================
// Name        : selection_sort.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#pragma once

#include "base.hpp"
#include "utils/message.hpp"
#include <iostream>

namespace dataStructure::sort {
template <typename DataType> class SelectionSort : public Sort<DataType> {
public:
  explicit SelectionSort() = default;

public:
  std::vector<DataType> sort() override {}
};
} // namespace dataStructure::sort
