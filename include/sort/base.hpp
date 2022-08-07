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
/**
 * @brief Sort Base Class
 * @details Base class for sorting algorithms
 * @tparam DataType
 */
template <typename DataType> class Sort {
public:
  /**
   * @details Default constructor
   */
  explicit Sort() = default;

public:
  /**
   * @details Default destructor
   */
  ~Sort() = default;

public:
  /**
   * @brief print vector elements
   * @details Function to print the elements in the vector
   */
  virtual void printVector() {
    std::cout << "Elements in Vector:: ";
    for (const auto &elem : data)
      std::cout << elem << " ";
    std::cout << std::endl;
  }

public:
  /**
   * @details Function to set the data for sorting
   * @param vec vector of unsorted data
   */
  void setVector(const std::vector<DataType> &vec) { data = vec; }

public:
  /**
   * @details Function to return the data
   * @return vector of sorted data
   */
  std::vector<DataType> getVector() { return data; }

public:
  /**
   * @details Virtual function for sorting
   */
  virtual void sort() = 0;

protected:
  std::vector<DataType> data;
};
} // namespace dataStructure::sort