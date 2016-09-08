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
Array<T, MAX_SIZE>::Array(const T (&values)[MAX_SIZE])
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
void Array<T, MAX_SIZE>::fill(const T &value)
{
  assign(MAX_SIZE,value);
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::fill(const T (&values)[MAX_SIZE])
{
  assign(MAX_SIZE,values);
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::assign(const size_t n, const T &value)
{
  size_t assign_size = n;
  if ((n > size_) && (n <= MAX_SIZE))
  {
    size_ = n;
  }
  else if (n > MAX_SIZE)
  {
    size_ = MAX_SIZE;
    assign_size = MAX_SIZE;
  }
  for (size_t i=0; i<assign_size; i++)
  {
    values_[i] = value;
  }
}

template <typename T, size_t MAX_SIZE>
void Array<T, MAX_SIZE>::assign(const size_t n, const T values[])
{
  size_t assign_size = n;
  if ((n > size_) && (n <= MAX_SIZE))
  {
    size_ = n;
  }
  else if (n > MAX_SIZE)
  {
    size_ = MAX_SIZE;
    assign_size = MAX_SIZE;
  }
  memcpy((void*) values_, (void*) values, assign_size*sizeof(T));
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
