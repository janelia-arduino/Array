#include <cassert>

struct ArrayAccessFailure {};

#define ARRAY_ACCESS_CHECK(condition)                                         \
  do {                                                                        \
    if (!(condition)) {                                                       \
      throw ArrayAccessFailure{};                                             \
    }                                                                         \
  } while (0)

#include <Array.h>

namespace {

void test_array_invalid_access_throws_when_hook_enabled() {
  Array<int, 2> array;

  bool threw = false;
  try {
    static_cast<void>(array.back());
  } catch (const ArrayAccessFailure &) {
    threw = true;
  }
  assert(threw);

  array.push_back(11);

  threw = false;
  try {
    static_cast<void>(array.at(1));
  } catch (const ArrayAccessFailure &) {
    threw = true;
  }
  assert(threw);
}

void test_array_valid_access_still_works_with_hook_enabled() {
  Array<int, 3> array;
  array.push_back(10);
  array.push_back(20);
  array.push_back(30);

  assert(array.front() == 10);
  assert(array.back() == 30);
  assert(array.at(1) == 20);
  assert(array[2] == 30);
}

} // namespace

int main() {
  test_array_invalid_access_throws_when_hook_enabled();
  test_array_valid_access_still_works_with_hook_enabled();
  return 0;
}
