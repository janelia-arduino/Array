#include <Arduino.h>
#include <Array.h>

const long BAUD = 115200;

const size_t ELEMENT_COUNT_MAX = 5;
typedef Array<size_t, ELEMENT_COUNT_MAX> Elements;

const size_t INDEX = 2;
const size_t DELAY = 500;

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
  const size_t c_style_array[ELEMENT_COUNT_MAX] = {15, 14, 13, 12, 11};

  Elements array(c_style_array);
  array[2] = 28;
  Serial.print("array:");
  printArray(array);
  delay(DELAY);
  Serial.print("array[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(array[INDEX]);
  delay(DELAY);
  size_t *array_data_ptr = array.data();
  Serial.print("array_data_ptr[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(array_data_ptr[INDEX]);
  delay(DELAY);
  Serial.println();
  delay(DELAY);

  const Elements const_array(c_style_array);
  Serial.print("const_array:");
  printArray(const_array);
  delay(DELAY);
  Serial.print("const_array[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(const_array[INDEX]);
  delay(DELAY);
  const size_t *const_array_data_ptr = const_array.data();
  Serial.print("const_array_data_ptr[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(const_array_data_ptr[INDEX]);
  delay(DELAY);
  Serial.println();
  delay(DELAY);
  Serial.print("Print const_array elements using iterators: ");
  for (const int element : const_array) {
    Serial.print(element);
    Serial.print(" ");
  }
  Serial.println();
  delay(DELAY);

  const Elements const_array_copy(const_array);
  Serial.print("const_array_copy:");
  printArray(const_array_copy);
  delay(DELAY);
  Serial.print("const_array_copy[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(const_array_copy[INDEX]);
  delay(DELAY);
  const size_t *const_array_copy_data_ptr = const_array_copy.data();
  Serial.print("const_array_copy_data_ptr[");
  Serial.print(INDEX);
  Serial.print("] = ");
  Serial.println(const_array_copy_data_ptr[INDEX]);
  delay(DELAY);
  Serial.println();
  delay(DELAY);
}
