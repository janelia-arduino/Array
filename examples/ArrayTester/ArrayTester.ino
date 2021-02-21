#include <Arduino.h>
#include <Streaming.h>
#include <Array.h>


const long BAUD = 115200;

const int ELEMENT_COUNT_MAX = 5;
typedef Array<int,ELEMENT_COUNT_MAX> Elements;
const size_t DELAY = 500;

void stuffFullArray(Elements & array)
{
  array.clear();
  for (int i=0; i<ELEMENT_COUNT_MAX; i++)
    {
      array.push_back((i+1)*3);
    }
}

void stuffPartialArray(Elements & array)
{
  array.clear();
  for (int i=0; i<ELEMENT_COUNT_MAX-2; i++)
    {
      array.push_back((i+1)*8);
    }
}

void doubleElements(Elements & array)
{
  for (int i=0; i<ELEMENT_COUNT_MAX; i++)
    {
      array[i] = array[i]*2;
    }
}

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
  Elements array;
  array.push_back(5);
  array.push_back(4);
  array.push_back(3);
  array.push_back(2);
  array.push_back(1);
  array.push_back(0);
  array.pop_back();
  Serial << "array:" << endl;
  Serial << array << endl;
  delay(DELAY);

  const int array_simple[ELEMENT_COUNT_MAX] = {15,14,13,12,11};
  Serial << "array_simple:" << endl;
  Serial << "[";
  for (int i=0; i<ELEMENT_COUNT_MAX; ++i)
    {
      if (i != 0)
        {
          Serial << ",";
        }
      Serial << array_simple[i];
    }
  Serial << "]" << endl;
  delay(DELAY);

  Elements array_copy(array_simple);
  Serial << "array_copy:" << endl;
  Serial << array_copy << endl;
  delay(DELAY);

  Elements array_initialized(ELEMENT_COUNT_MAX);
  Serial << "array_initialized:" << endl;
  Serial << array_initialized << endl;
  delay(DELAY);

  array_initialized.fill(37);
  Serial << "array_initialized.fill(37):" << endl;
  Serial << array_initialized << endl;
  delay(DELAY);

  array_initialized.fill(array_simple);
  Serial << "array_initialized.fill(array_simple):" << endl;
  Serial << array_initialized << endl;
  delay(DELAY);

  array_initialized[3] = 666;
  Serial << "array_initialized[3] = 666:" << endl;
  Serial << array_initialized << endl;
  delay(DELAY);

  Elements array_full_stuffed;
  stuffFullArray(array_full_stuffed);
  Serial << "array_full_stuffed:" << endl;
  Serial << array_full_stuffed << endl;
  delay(DELAY);

  Serial << "Print array_full_stuffed elements using iterators: ";
  for (int element : array_full_stuffed)
    {
      Serial << element << " ";
    }
  Serial << endl;

  Elements array_partial_stuffed;
  stuffPartialArray(array_partial_stuffed);
  Serial << "array_partial_stuffed:" << endl;
  Serial << array_partial_stuffed << endl;
  delay(DELAY);

  Serial << "Print array_partial_stuffed elements using iterators: ";
  for (size_t element : array_partial_stuffed)
    {
      Serial << element << " ";
    }
  Serial << endl;

  Elements array_doubled(array_full_stuffed);
  doubleElements(array_doubled);
  Serial << "array_doubled:" << endl;
  Serial << array_doubled << endl;
  delay(DELAY);

  // fill with value of a different type
  Elements array_filled;
  long fill_value = 123;
  array_filled.fill(fill_value);
  Serial << "array_filled:" << endl;
  Serial << array_filled << endl;
  delay(DELAY);

  // initialize with array of different size and type
  Array<long,ELEMENT_COUNT_MAX*2> array_copy_2(array_simple);
  Serial << "array_copy_2:" << endl;
  Serial << array_copy_2 << endl;
  Serial << "array_copy_2.max_size():" << endl;
  Serial << array_copy_2.max_size() << endl;
  delay(DELAY);

  // initialize with another array instance
  Array<size_t,ELEMENT_COUNT_MAX*3> array_copy_3(array_copy_2);
  Serial << "array_copy_3:" << endl;
  Serial << array_copy_3 << endl;
  Serial << "array_copy_3.max_size():" << endl;
  Serial << array_copy_3.max_size() << endl;
  delay(DELAY);

  // get pointer to raw data
  size_t * array_copy_3_ptr = array_copy_3.data();
  size_t index = 2;
  if (index < array_copy_3.size())
    {
      Serial << "array_copy_3_ptr[index]:" << endl;
      Serial << array_copy_3_ptr[index] << endl;
    }
  delay(DELAY);

  Elements array_copy_4(array_simple);
  Serial << "array_copy_4:" << endl;
  Serial << array_copy_4 << endl;
  Serial << "array_copy_4.size():" << endl;
  Serial << array_copy_4.size() << endl;
  array_copy_4.remove(2);
  Serial << "array_copy_4.remove(2):" << endl;
  Serial << array_copy_4 << endl;
  Serial << "array_copy_4.size():" << endl;
  Serial << array_copy_4.size() << endl;
  delay(DELAY);

}
