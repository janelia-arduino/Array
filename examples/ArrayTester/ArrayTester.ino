#include <Arduino.h>
#include <Array.h>

const long BAUD = 115200;

const int ELEMENT_COUNT_MAX = 5;
typedef Array<int, ELEMENT_COUNT_MAX> Elements;
const size_t DELAY = 500;

void stuffFullArray(Elements &array) {
  array.clear();
  for (int i = 0; i < ELEMENT_COUNT_MAX; i++) {
    array.push_back((i + 1) * 3);
  }
}

void stuffPartialArray(Elements &array) {
  array.clear();
  for (int i = 0; i < ELEMENT_COUNT_MAX - 2; i++) {
    array.push_back((i + 1) * 8);
  }
}

void doubleElements(Elements &array) {
  for (int i = 0; i < ELEMENT_COUNT_MAX; i++) {
    array[i] = array[i] * 2;
  }
}

void setup() {
  Serial.begin(BAUD);
  while (!Serial) {
    // wait for serial port to connect.
  }
}

template <typename T, size_t MAX_SIZE>
void printArray(const Array<T, MAX_SIZE> &array) {
  Serial.print("[");
  for (size_t i = 0; i < array.size(); ++i) {
    if (i != 0) {
      Serial.print(",");
    }
    Serial.print(array[i]);
  }
  Serial.println("]");
}

void loop() {
  Elements array;
  array.push_back(5);
  array.push_back(4);
  array.push_back(3);
  array.push_back(2);
  array.push_back(1);
  array.push_back(0);
  array.pop_back();
  Serial.println("array:");
  printArray(array);
  delay(DELAY);

  const int array_simple[ELEMENT_COUNT_MAX] = {15, 14, 13, 12, 11};
  Serial.println("array_simple:");
  Serial.print("[");
  for (int i = 0; i < ELEMENT_COUNT_MAX; ++i) {
    if (i != 0) {
      Serial.print(",");
    }
    Serial.print(array_simple[i]);
  }
  Serial.println("]");
  delay(DELAY);

  Elements array_copy(array_simple);
  Serial.println("array_copy:");
  printArray(array_copy);
  delay(DELAY);

  Elements array_initialized(ELEMENT_COUNT_MAX);
  Serial.println("array_initialized:");
  printArray(array_initialized);
  delay(DELAY);

  array_initialized.fill(37);
  Serial.println("array_initialized.fill(37):");
  printArray(array_initialized);
  delay(DELAY);

  array_initialized.fill(array_simple);
  Serial.println("array_initialized.fill(array_simple):");
  printArray(array_initialized);
  delay(DELAY);

  array_initialized[3] = 666;
  Serial.println("array_initialized[3] = 666:");
  printArray(array_initialized);
  delay(DELAY);

  Elements array_full_stuffed;
  stuffFullArray(array_full_stuffed);
  Serial.println("array_full_stuffed:");
  printArray(array_full_stuffed);
  delay(DELAY);

  Serial.print("Print array_full_stuffed elements using iterators: ");
  for (int element : array_full_stuffed) {
    Serial.print(element);
    Serial.print(" ");
  }
  Serial.println();

  Elements array_partial_stuffed;
  stuffPartialArray(array_partial_stuffed);
  Serial.println("array_partial_stuffed:");
  printArray(array_partial_stuffed);
  delay(DELAY);

  Serial.print("Print array_partial_stuffed elements using iterators: ");
  for (size_t element : array_partial_stuffed) {
    Serial.print(element);
    Serial.print(" ");
  }
  Serial.println();

  Elements array_doubled(array_full_stuffed);
  doubleElements(array_doubled);
  Serial.println("array_doubled:");
  printArray(array_doubled);
  delay(DELAY);

  // fill with value of a different type
  Elements array_filled;
  long fill_value = 123;
  array_filled.fill(fill_value);
  Serial.println("array_filled:");
  printArray(array_filled);
  delay(DELAY);

  // initialize with array of different size and type
  Array<long, ELEMENT_COUNT_MAX * 2> array_copy_2(array_simple);
  Serial.println("array_copy_2:");
  printArray(array_copy_2);
  Serial.println("array_copy_2.max_size():");
  Serial.println(array_copy_2.max_size());
  delay(DELAY);

  // initialize with another array instance
  Array<size_t, ELEMENT_COUNT_MAX * 3> array_copy_3(array_copy_2);
  Serial.println("array_copy_3:");
  printArray(array_copy_3);
  Serial.println("array_copy_3.max_size():");
  Serial.println(array_copy_3.max_size());
  delay(DELAY);

  // get pointer to raw data
  size_t *array_copy_3_ptr = array_copy_3.data();
  size_t index = 2;
  if (index < array_copy_3.size()) {
    Serial.println("array_copy_3_ptr[index]:");
    Serial.println(array_copy_3_ptr[index]);
  }
  delay(DELAY);

  Elements array_copy_4(array_simple);
  Serial.println("array_copy_4:");
  printArray(array_copy_4);
  Serial.println("array_copy_4.size():");
  Serial.println(array_copy_4.size());
  array_copy_4.remove(2);
  Serial.println("array_copy_4.remove(2):");
  printArray(array_copy_4);
  Serial.println("array_copy_4.size():");
  Serial.println(array_copy_4.size());
  delay(DELAY);
}
