//============================================================================
// Name        : rand_vec.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

// Function to generate a random vector
// Params:-
// size: size of the vector
// minVal = minimum value from which distribution will start
// maxVal = minimum value from which distribution will end
template <typename Data>
std::vector<Data> generateRandomVector(const int size, const Data minVal = 0,
                                       const Data maxVal = 100) {
  std::random_device rndDevice;
  std::mt19937 mersenneEngine{rndDevice()};
  std::uniform_int_distribution<Data> distribution{minVal, maxVal};
  auto generate = [&distribution, &mersenneEngine]() {
    return distribution(mersenneEngine);
  };
  std::vector<Data> randVec(size);
  std::generate(std::begin(randVec), std::end(randVec), generate);
  return randVec;
}