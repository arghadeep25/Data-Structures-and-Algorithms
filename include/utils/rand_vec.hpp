/************************************
 * @file rand_vec.hpp
 * @details Random Vector Generator
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

namespace dataStructure::utils {
// Function to generate a random vector
// Params:-
// size: size of the vector
// minVal = minimum value from which distribution will start
// maxVal = minimum value from which distribution will end
template <typename DataType>
std::vector<DataType> generateRandomVector(const int size,
                                           const DataType minVal = 0,
                                           const DataType maxVal = 100) {
  std::random_device rndDevice;
  std::mt19937 mersenneEngine{rndDevice()};
  std::uniform_int_distribution<DataType> distribution{minVal, maxVal};
  auto generate = [&distribution, &mersenneEngine]() {
    return distribution(mersenneEngine);
  };
  std::vector<DataType> randVec(size);
  std::generate(std::begin(randVec), std::end(randVec), generate);
  return randVec;
}
} // namespace dataStructure::utils