//============================================================================
// Name        : sorting_algorithms.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#include "sort/sort_factory.hpp"
#include "utils/rand_vec.hpp"

int main(int argc, char **argv) {
  std::vector<int> data =
      dataStructure::Utils::generateRandomVector(15, 0, 100);
  const char *sort_type = "Selection_Sort";
  MESSAGE("Selected Sort Type: ", sort_type);
  auto sort_method = dataStructure::sort::sortMethod<int>(sort_type);
  sort_method->setVector(data);
  MESSAGE("------- BEFORE SORTING -------");
  sort_method->printVector();
  sort_method->sort();
  MESSAGE("------- AFTER SORTING -------");
  sort_method->printVector();
}