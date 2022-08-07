/************************************
* @file base.hpp
* @details Base Class for Sorting Algorithms
* @author Arghadeep Mazumder
* @version 1.0.0
* @copyright -
************************************/

#pragma once

#include <iostream>
#include <vector>

namespace dataStructure::sort {
template <typename DataType> class Sort {
public:
  explicit Sort() = default;

public:
  // Function to print the vector
  virtual void printVector() {
    std::cout << "Elements in Vector:: ";
    for (const auto &elem : data)
      std::cout << elem << " ";
    std::cout << std::endl;
  }

public:
  // Function to set the data for sorting
  void setVector(const std::vector<DataType> &vec) { data = vec; }

public:
  // Function to return the original data
  std::vector<DataType> getVector() { return data; }

public:
  // Virtual function for sorting
  virtual void sort() = 0;

protected:
  std::vector<DataType> data;
};
} // namespace dataStructure::sort