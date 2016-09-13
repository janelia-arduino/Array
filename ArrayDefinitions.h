// ----------------------------------------------------------------------------
// ArrayDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ARRAY_DEFINITIONS_H
#define ARRAY_DEFINITIONS_H

#ifndef ARDUINO
#include <cstring>
#endif

template <typename T, size_t MAX_SIZE>
Array<T, MAX_SIZE>::Array()
{
  size_ = 0;
}

template <typename T, size_t MAX_SIZE>
Array<T, MAX_SIZE>::Array(const T &value)
{
  size_ = 0;
  fill(value);
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
Array<T, MAX_SIZE>::Array(const U (&values)[N])
{
  size_ = 0;
  fill(values);
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
Array<T, MAX_SIZE>::Array(const Array<U,N> &values)
{
  size_ = 0;
  fill(values);
}

template <typename T, size_t MAX_SIZE>
T& Array<T, MAX_SIZE>::operator[](const size_t i)
{
  return values_[i];
}

template <typename T, size_t MAX_SIZE>
T& Array<T, MAX_SIZE>::at(const size_t i)
{
  return values_[i];
}

template <typename T, size_t MAX_SIZE>
T& Array<T, MAX_SIZE>::front()
{
  return values_[0];
}

template <typename T, size_t MAX_SIZE>
T& Array<T, MAX_SIZE>::back()
{
  return values_[size_-1];
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::clear()
{
  size_ = 0;
}

template <typename T, size_t MAX_SIZE>
template <typename U>
void Array<T, MAX_SIZE>::fill(const U &value)
{
  assign(MAX_SIZE,value);
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
void Array<T, MAX_SIZE>::fill(const U (&values)[N])
{
  assign(N,values);
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
void Array<T, MAX_SIZE>::fill(const Array<U,N> &values)
{
  assign(N,values);
}

template <typename T, size_t MAX_SIZE>
template <typename U>
void Array<T, MAX_SIZE>::assign(const size_t n, const U &value)
{
  size_t assign_size = ((n < MAX_SIZE) ? n : MAX_SIZE);
  size_ = assign_size;
  for (size_t i=0; i<assign_size; i++)
  {
    values_[i] = value;
  }
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
void Array<T, MAX_SIZE>::assign(const size_t n, const U (&values)[N])
{
  size_t n_smallest = ((n < N) ? n : N);
  size_t assign_size = ((n_smallest < MAX_SIZE) ? n_smallest : MAX_SIZE);
  size_ = assign_size;
  for (size_t i=0; i<assign_size; i++)
  {
    values_[i] = values[i];
  }
}

template <typename T, size_t MAX_SIZE>
template <typename U, size_t N>
void Array<T, MAX_SIZE>::assign(const size_t n, const Array<U,N> &values)
{
  size_t n_smallest = ((n < values.size()) ? n : values.size());
  size_t assign_size = ((n_smallest < MAX_SIZE) ? n_smallest : MAX_SIZE);
  size_ = assign_size;
  for (size_t i=0; i<assign_size; i++)
  {
    values_[i] = values[i];
  }
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::push_back(const T &value)
{
  if (size_ < MAX_SIZE)
  {
    values_[size_++] = value;
  }
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::pop_back()
{
  if (size_ > 0)
  {
    --size_;
  }
}

template <typename T, size_t MAX_SIZE>
size_t Array<T, MAX_SIZE>::size()
{
  return size_;
}

template <typename T, size_t MAX_SIZE>
size_t Array<T, MAX_SIZE>::max_size()
{
  return MAX_SIZE;
}

template <typename T, size_t MAX_SIZE>
bool Array<T, MAX_SIZE>::empty()
{
  return size_ == 0;
}

template <typename T, size_t MAX_SIZE>
bool Array<T, MAX_SIZE>::full()
{
  return size_ == MAX_SIZE;
}

#endif
