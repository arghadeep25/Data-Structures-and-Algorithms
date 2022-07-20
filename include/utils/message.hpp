//============================================================================
// Name        : message.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Different message formats created using variadic template
//============================================================================
#pragma once

#include "colors.hpp"
#include <iostream>

// -------- WARNING --------
template <typename T> void WARNING(T t) {
  std::cout << BOLD << RED << t << std::endl;
}

template <typename T, typename... Args> void WARNING(T t, Args... args) {
  std::cout << BOLD << RED << t << std::endl;
  WARNING(args...);
}

// -------- STATUS --------
template <typename T, typename C> void STATUS(T t, C c) {
  std::cout << c << t << std::endl;
}

template <typename T, typename C, typename... Args>
void STATUS(T t, C c, Args... args) {
  std::cout << c << t << std::endl;
  STATUS(c, args...);
}

// -------- MESSAGE --------
template <typename T> void MESSAGE(T t) { std::cout << CYAN << t << std::endl; }

template <typename T, typename... Args> void MESSAGE(T t, Args... args) {
  std::cout << CYAN << t << std::endl;
  MESSAGE(args...);
}

// -------- PRINT --------
template <typename T> void PRINT(T t) {
  std::cout << MAGENTA << t << " ";
}

template <typename T, typename... Args> void PRINT(T t, Args... args) {
  std::cout << MAGENTA << t << " ";
  PRINT(args...);
  std::cout << std::endl;
}