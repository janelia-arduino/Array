// ----------------------------------------------------------------------------
// Array.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ARRAY_H
#define ARRAY_H

#ifdef ARDUINO
    #if ARDUINO >= 100
        #include <Arduino.h>
    #else
        #include <WProgram.h>
    #endif
#else
    #include <cstddef>
#endif

template <typename T, size_t MAX_SIZE>
class Array
{
public:
  Array();
  Array(const T &value);
  Array(const T (&values)[MAX_SIZE]);
  T& operator[](const size_t i);
  T& at(const size_t i);
  T& front();
  T& back();
  void clear();
  void fill(const T &value);
  void fill(const T (&values)[MAX_SIZE]);
  void assign(const size_t n, const T &value);
  void assign(const size_t n, const T values[]);
  void push_back(const T &value);
  void pop_back();
  size_t size();
  size_t max_size();
  bool empty();
  bool full();

private:
  T values_[MAX_SIZE];
  size_t size_;
};

template <typename T, size_t MAX_SIZE>
inline Print &operator <<(Print &stream, const Array<T,MAX_SIZE> &array)
{
  stream.print("[");
  for (int i=0; i<array.size(); i++)
  {
    if (i != 0)
    {
      stream.print(",");
    }
    stream.print(array[i]);
  }
  stream.print("]");
  return stream;
}

#include "ArrayDefinitions.h"

#endif
