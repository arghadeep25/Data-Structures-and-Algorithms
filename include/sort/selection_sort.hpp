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
  void printVector(const std::vector<DataType> &data) override {
    for (const auto &elem : data)
      std::cout << elem << " ";
    std::cout << std::endl;
  }

public:
  std::vector<DataType> sort(const std::vector<DataType> &data) override {}
};
} // namespace dataStructure::sort
