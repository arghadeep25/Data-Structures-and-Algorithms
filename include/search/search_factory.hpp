/************************************
 * @file search_factory.hpp
 * @details Search Factory
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once
#include <cstring>
#include <memory>
#include <search/linear_search.hpp>

namespace dataStructure::search {
/**
 * @details Search factory to select a search method
 * @tparam DataType vector of int, float, double, and char
 * @param searchType Search Method
 * @return
 */
template <typename DataType>
std::unique_ptr<Search<DataType>> searchMethod(const char *searchType) {
  if (!std::strcmp(searchType, "Linear_Search"))
    return std::make_unique<LinearSearch<DataType>>();
  else
    return nullptr;
}
} // namespace dataStructure::search