//============================================================================
// Name        : base.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Base Class for Sorting Algorithms
//============================================================================
#pragma once

#include <iostream>
#include <vector>

namespace dataStructure::sort {
template <typename DataType> class Sort {
public:
  virtual void printVector(const std::vector<DataType> &) = 0;

public:
  virtual std::vector<DataType> sort(const std::vector<DataType> &) = 0;
};
} // namespace dataStructure::sort