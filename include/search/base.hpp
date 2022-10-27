/************************************
 * @file base.hpp
 * @details Search Base Class
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once
#include <iostream>
#include <utils/message.hpp>

namespace dataStructure::search {
/**
 * @details Search Base Class
 * @tparam DataType vector of int, float, double, and char
 */
template <typename DataType> class Search {
public:
  /**
   * @details Default constructor
   */
  explicit Search() = default;

public:
  /**
   * @details Default destructor
   */
  ~Search() = default;

public:
  /**
   * @details Pure virtual function of search method
   * @param key Value which to be searched in the vector
   * @return position
   */
  virtual int search(typename DataType::value_type key) = 0;

public:
  /**
   * @details Function to add data
   * @param data_ vector of data
   */
  void setData(const DataType &data_) { data = data_; }

public:
  /**
   * @details Function to print the elements in a vector
   */
  void print() { PRINT_VECTOR(data); }

public:
  /**
   * @details Function to check if the vector is empty or not. If empty then
   *          exit. This is used for pre-check condition
   */
  void checkEmpty() {
    if (this->data.empty()) {
      WARNING("Empty Vector!!");
      exit(1);
    }
  }

public:
  /**
   * @details Function to check if the vector is empty or not.
   * @return true or false
   */
  bool isEmpty() {
    if (data.empty())
      return true;
    else
      return false;
  }

protected:
  /**
   * @details Holds the data in which an element is to be searched
   */
  DataType data;
};
} // namespace dataStructure::search