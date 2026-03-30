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

void test_cross_type_assignment_and_truncation() {
  Array<int, 3> array;

  const long source_values[] = {10L, 20L, 30L, 40L};
  array.assign(4, source_values);
  assert(array.size() == 3);
  assert(array[0] == 10);
  assert(array[1] == 20);
  assert(array[2] == 30);

  Array<long, 5> source(source_values);
  array.assign(5, source);
  assert(array.size() == 3);
  assert(array[0] == 10);
  assert(array[1] == 20);
  assert(array[2] == 30);
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

void test_cross_type_copy_constructor_and_fill_truncate() {
  const long values[] = {1L, 2L, 3L, 4L};
  Array<long, 4> source(values);
  Array<int, 2> copy(source);

  assert(copy.size() == 2);
  assert(copy[0] == 1);
  assert(copy[1] == 2);

  Array<int, 3> filled;
  filled.fill(source);
  assert(filled.size() == 3);
  assert(filled[0] == 1);
  assert(filled[1] == 2);
  assert(filled[2] == 3);
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

} // namespace

int main() {
  test_default_array_state();
  test_push_pop_and_capacity_limits();
  test_fill_assign_and_remove();
  test_cross_type_assignment_and_truncation();
  test_copy_constructor_and_iteration();
  test_cross_type_copy_constructor_and_fill_truncate();
  test_const_accessors_and_iterator_identity();
  return 0;
}
