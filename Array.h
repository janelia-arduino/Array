// ----------------------------------------------------------------------------
// Array.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ARRAY_H
#define ARRAY_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

template <typename T, size_t max_size_>
class Array
{
public:
  Array();
  Array(const T &value);
  Array(const T (&values)[max_size_]);
  T& operator[](const size_t i);
  T& at(const size_t i);
  T& front();
  T& back();
  void clear();
  void fill(const T &value);
  void fill(const T (&values)[max_size_]);
  void assign(const size_t n, const T &value);
  void assign(const size_t n, const T values[]);
  void push_back(const T &value);
  void pop_back();
  size_t size();
  size_t max_size();
  bool empty();
  bool full();

private:
  T values_[max_size_];
  size_t size_;
};
#include "ArrayDefinitions.h"

#endif
