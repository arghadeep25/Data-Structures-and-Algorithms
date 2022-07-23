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
  // Generating a random vector
  std::vector<int> data =
      dataStructure::Utils::generateRandomVector(15, 0, 100);
  // Name of the sorting algorithm
//  const char *sort_type = "Selection_Sort";
  const char *sort_type = "Bubble_Sort";
  MESSAGE("Selected Sort Type: ", sort_type);
  // Passing the sorting method to the sorting algorithms factory
  auto sort_method = dataStructure::sort::sortMethod<int>(sort_type);
  // Passing the vector
  sort_method->setVector(data);
  MESSAGE("------- BEFORE SORTING -------");
  // Printing the vector before sorting
  sort_method->printVector();
  // Sort the vector
  sort_method->sort();
  MESSAGE("------- AFTER SORTING -------");
  // Printing the vector after sorting
  sort_method->printVector();
}