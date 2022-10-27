/************************************
 * @file linear_search.hpp
 * @details Linear Search
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once
#include <iostream>
#include <search/base.hpp>

namespace dataStructure::search {
/**
 * @details Linear Search Class
 * @tparam DataType
 */
template <typename DataType> class LinearSearch : public Search<DataType> {
public:
  /**
   * @details Default constructor
   */
  explicit LinearSearch() = default;

public:
  /**
   * @details Default destructor
   */
  ~LinearSearch() = default;

public:
  /**
   * @details Search function
   * @param key Value which to be searched in the vector
   * @return position
   */
  int search(typename DataType::value_type key) override {
    this->checkEmpty();
    for (int idx = 0; idx < this->data.size(); idx++) {
      if (this->data.at(idx) == key) {
        MESSAGE("Element found at position: ", idx);
        return idx;
      } else {
        return -1;
      }
    }
  }
};
} // namespace dataStructure::search