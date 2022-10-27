/************************************
* @file search.cpp
* @details Search Algorithm Examples
* @author Arghadeep Mazumder
* @version 1.0.0
* @copyright -
************************************/

#include <iostream>
#include <vector>
#include <search/search_factory.hpp>

int main(int argc, char **argv) {
  // Declare Data
  std::vector<int> data{5, 3, 1, 7, 6, 11, 9};
  // Search Method
  const char *sort_type = "Linear_Search";
  auto search_method =
      dataStructure::search::searchMethod<std::vector<int>>(sort_type);
  // Operations
  search_method->setData(data);
  search_method->print();
  search_method->search(5);
}