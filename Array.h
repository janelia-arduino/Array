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
// #define __ASSERT_USE_STDERR
// #include <assert.h>


// // handle diagnostic informations given by assertion and abort program execution:
// void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp);

template <typename T, unsigned int max_size_>
class Array
{
public:
  Array();
  Array(const T &value);
  Array(const T (&values)[max_size_]);
  virtual T& operator[](const unsigned int i);
  virtual T& at(const unsigned int i);
  virtual T& front();
  virtual T& back();
  virtual void clear();
  virtual void fill(const T &value);
  virtual void fill(const T (&values)[max_size_]);
  virtual void assign(const unsigned int n, const T &value);
  virtual void assign(const unsigned int n, const T values[]);
  virtual void push_back(const T &value);
  virtual void pop_back();
  virtual unsigned int size();
  virtual unsigned int max_size();
  virtual bool empty();
  virtual bool full();

private:
  T values_[max_size_];
  unsigned int size_;
};
#include "ArrayDefinitions.h"

#endif
