#pragma once
#include <iostream>
#include <string>
// #include <utility> // for std::move

template<class T>
void copySwap(T& a, T& b)
{
  T tmp { a }; // invokes copy constructor
  a = b; // invokes copy assignment
  b = tmp; // invokes copy assignment
}
