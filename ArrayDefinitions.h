// ----------------------------------------------------------------------------
// ArrayDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ARRAY_DEFINITIONS_H
#define ARRAY_DEFINITIONS_H


template <typename T, size_t max_size_>
Array<T,max_size_>::Array()
{
  clear();
}

template <typename T, size_t max_size_>
Array<T,max_size_>::Array(const T &value)
{
  fill(value);
}

template <typename T, size_t max_size_>
Array<T, max_size_>::Array(const T (&values)[max_size_])
{
  fill(values);
}

template <typename T, size_t max_size_>
T& Array<T, max_size_>::operator[](const size_t i)
{
  return values_[i];
}

template <typename T, size_t max_size_>
T& Array<T, max_size_>::at(const size_t i)
{
  return values_[i];
}

template <typename T, size_t max_size_>
T& Array<T, max_size_>::front()
{
  return values_[0];
}

template <typename T, size_t max_size_>
T& Array<T, max_size_>::back()
{
  return values_[size_-1];
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::clear()
{
  size_ = 0;
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::fill(const T &value)
{
  assign(max_size_,value);
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::fill(const T (&values)[max_size_])
{
  assign(max_size_,values);
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::assign(const size_t n, const T &value)
{
  size_t assign_size = n;
  if ((n > size_) && (n <= max_size_))
  {
    size_ = n;
  }
  else if (n > max_size_)
  {
    size_ = max_size_;
    assign_size = max_size_;
  }
  for (size_t i=0; i<assign_size; i++)
  {
    values_[i] = value;
  }
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::assign(const size_t n, const T values[])
{
  size_t assign_size = n;
  if ((n > size_) && (n <= max_size_))
  {
    size_ = n;
  }
  else if (n > max_size_)
  {
    size_ = max_size_;
    assign_size = max_size_;
  }
  memcpy((void*) values_, (void*) values, assign_size*sizeof(T));
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::push_back(const T &value)
{
  if (size_ < max_size_)
  {
    values_[size_++] = value;
  }
}

template <typename T, size_t max_size_>
void Array<T, max_size_>::pop_back()
{
  if (size_ > 0)
  {
    --size_;
  }
}

template <typename T, size_t max_size_>
size_t Array<T, max_size_>::size()
{
  return size_;
}

template <typename T, size_t max_size_>
size_t Array<T, max_size_>::max_size()
{
  return max_size_;
}

template <typename T, size_t max_size_>
bool Array<T, max_size_>::empty()
{
  return size_ == 0;
}

template <typename T, size_t max_size_>
bool Array<T, max_size_>::full()
{
  return size_ == max_size_;
}

#endif
