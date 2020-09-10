// ----------------------------------------------------------------------------
// ArrayIterator.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

template<typename T>
class ArrayIterator
{
public:
  ArrayIterator(T * values_ptr) : values_ptr_{values_ptr}, position_{0} {}

  ArrayIterator(T * values_ptr, size_t size) : values_ptr_{values_ptr}, position_{size} {}

  bool operator!=(const ArrayIterator<T> & other) const
  {
    return !(*this == other);
  }

  bool operator==(const ArrayIterator<T> & other) const
  {
    return position_ == other.position_;
  }

  ArrayIterator & operator++()
  {
    ++position_;
    return *this;
  }

  T & operator*() const
  {
    return *(values_ptr_ + position_);
  }

private:
  T * values_ptr_;
  size_t position_;
};

#endif
