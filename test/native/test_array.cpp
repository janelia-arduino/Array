#include <cassert>

#include <Array.h>

namespace {

void test_default_array_state() {
  Array<int, 4> array;
  assert(array.size() == 0);
  assert(array.max_size() == 4);
  assert(array.empty());
  assert(!array.full());
}

void test_push_pop_and_capacity_limits() {
  Array<int, 3> array;
  array.push_back(10);
  array.push_back(20);
  array.push_back(30);
  array.push_back(40);

  assert(array.size() == 3);
  assert(array.full());
  assert(array.front() == 10);
  assert(array.back() == 30);

  array.pop_back();
  assert(array.size() == 2);
  assert(array.back() == 20);
}

void test_fill_assign_and_remove() {
  Array<int, 5> array(7);
  assert(array.size() == 5);
  assert(array[0] == 7);
  assert(array[4] == 7);

  const int values[] = {1, 2, 3};
  array.assign(3, values);
  assert(array.size() == 3);
  assert(array[0] == 1);
  assert(array[2] == 3);

  array.remove(1);
  assert(array.size() == 2);
  assert(array[0] == 1);
  assert(array[1] == 3);

  array.clear();
  assert(array.empty());
}

void test_copy_constructor_and_iteration() {
  const int values[] = {4, 5, 6};
  Array<int, 4> source(values);
  Array<int, 6> copy(source);

  int sum = 0;
  for (auto value : copy) {
    sum += value;
  }

  assert(copy.size() == 3);
  assert(sum == 15);
  assert(copy.data()[2] == 6);
}

void test_const_accessors_and_iterator_identity() {
  const int values_a[] = {1, 2, 3};
  const int values_b[] = {1, 2, 3};
  const Array<int, 4> array(values_a);
  const Array<int, 4> other(values_b);

  assert(array.front() == 1);
  assert(array.back() == 3);
  assert(array.begin() != other.begin());
}

}  // namespace

int main() {
  test_default_array_state();
  test_push_pop_and_capacity_limits();
  test_fill_assign_and_remove();
  test_copy_constructor_and_iteration();
  test_const_accessors_and_iterator_identity();
  return 0;
}
