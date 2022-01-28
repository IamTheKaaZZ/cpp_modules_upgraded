#pragma once
#include <iostream>
#include <string>
#include <utility> // for std::move

// In C++11, std::move is a standard library function that casts (using static_cast) its argument into an r-value reference,
// so that move semantics can be invoked.
// Thus, we can use std::move to cast an l-value into a type that will prefer being moved over being copied.
// std::move is defined in the utility header.

template<class T>
void moveSwap(T& a, T& b)
{
  T tmp { std::move(a) }; // invokes move constructor
  a = std::move(b); // invokes move assignment
  b = std::move(tmp); // invokes move assignment
}
