#include <Arduino.h>
#include <Streaming.h>
#include <Array.h>


const long BAUD = 115200;

const size_t ELEMENT_COUNT_MAX = 5;
typedef Array<size_t,ELEMENT_COUNT_MAX> Elements;

const size_t INDEX = 2;
const size_t DELAY = 500;

void setup()
{
  Serial.begin(BAUD);
  while (!Serial)
    {
      // wait for serial port to connect.
    }
}


void loop()
{
  const size_t c_style_array[ELEMENT_COUNT_MAX] = {15,14,13,12,11};

  Elements array(c_style_array);
  array[2] = 28;
  Serial << "array:" << array << endl;
  delay(DELAY);
  Serial << "array[" << INDEX << "] = " << array[INDEX] << endl;
  delay(DELAY);
  size_t * array_data_ptr = array.data();
  Serial << "array_data_ptr[" << INDEX << "] = " << array_data_ptr[INDEX] << endl;
  delay(DELAY);
  Serial << endl;
  delay(DELAY);

  const Elements const_array(c_style_array);
  Serial << "const_array:" << const_array << endl;
  delay(DELAY);
  Serial << "const_array[" << INDEX << "] = " << const_array[INDEX] << endl;
  delay(DELAY);
  const size_t * const_array_data_ptr = const_array.data();
  Serial << "const_array_data_ptr[" << INDEX << "] = " << const_array_data_ptr[INDEX] << endl;
  delay(DELAY);
  Serial << endl;
  delay(DELAY);
  Serial << "Print const_array elements using iterators: ";
  for (const int element : const_array)
    {
      Serial << element << " ";
    }
  Serial << endl;
  delay(DELAY);

  const Elements const_array_copy(const_array);
  Serial << "const_array_copy:" << const_array_copy << endl;
  delay(DELAY);
  Serial << "const_array_copy[" << INDEX << "] = " << const_array_copy[INDEX] << endl;
  delay(DELAY);
  const size_t * const_array_copy_data_ptr = const_array_copy.data();
  Serial << "const_array_copy_data_ptr[" << INDEX << "] = " << const_array_copy_data_ptr[INDEX] << endl;
  delay(DELAY);
  Serial << endl;
  delay(DELAY);

}
