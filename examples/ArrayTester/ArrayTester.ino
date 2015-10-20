#include "Arduino.h"
#include "Streaming.h"
#include "Array.h"


const int BAUDRATE = 9600;

const int ELEMENT_COUNT = 5;

void printArray(Array<int,ELEMENT_COUNT> array)
{
  Serial << "[";
  for (int i=0; i<ELEMENT_COUNT; i++)
  {
    if (i != 0)
    {
      Serial << ",";
    }
    Serial << array[i];
  }
  Serial << "]" << endl;
}

void printArray(const int (&array)[ELEMENT_COUNT])
{
  Array<int,ELEMENT_COUNT> array_copy(array);
  printArray(array_copy);
}

Array<int,ELEMENT_COUNT> generateArray()
{
  Array<int,ELEMENT_COUNT> array;
  for (int i=0; i<ELEMENT_COUNT; i++)
  {
    array[i] = (i+1)*3;
  }
  return array;
}

Array<int,ELEMENT_COUNT> doubleElements(Array<int,ELEMENT_COUNT> &array)
{
  Array<int,ELEMENT_COUNT> array_doubled;
  for (int i=0; i<ELEMENT_COUNT; i++)
  {
    array_doubled[i] = array[i]*2;
  }
  return array_doubled;
}

void setup()
{
  Serial.begin(BAUDRATE);
  delay(1000);

  const int array_simple[ELEMENT_COUNT] = {15,14,13,12,11};
  Serial << "array_simple:" << endl;
  printArray(array_simple);

  Array<int,ELEMENT_COUNT> array_copy(array_simple);
  Serial << "array_copy:" << endl;
  printArray(array_copy);

  Array<int,ELEMENT_COUNT> array_initialized(ELEMENT_COUNT);
  Serial << "array_initialized:" << endl;
  printArray(array_initialized);

  array_initialized.fill(37);
  Serial << "array_initialized.fill(37):" << endl;
  printArray(array_initialized);

  array_initialized.fill(array_simple);
  Serial << "array_initialized.fill(array_simple):" << endl;
  printArray(array_initialized);

  array_initialized[3] = 666;
  Serial << "array_initialized[3] = 666:" << endl;
  printArray(array_initialized);

  Array<int,ELEMENT_COUNT> array_generated = generateArray();
  Serial << "array_generated:" << endl;
  printArray(array_generated);

  Array<int,ELEMENT_COUNT> array_doubled = doubleElements(array_generated);
  Serial << "array_doubled:" << endl;
  printArray(array_doubled);

  int out_of_bounds = array_doubled[ELEMENT_COUNT+1];
  Serial << "out_of_bounds: " << out_of_bounds << endl;

  out_of_bounds = array_doubled.at(ELEMENT_COUNT+1);
  Serial << "out_of_bounds:" << out_of_bounds << endl;
}


void loop()
{
}
