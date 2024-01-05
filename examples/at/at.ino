/**
 * @file at.ino
 * @author Alexander Tonn (https://github.com/AlexanderTonn)
 * @brief This example shows the usage of ::at Operator
 * ! If the inserted index is out of range, the program will return the value of the last index
 * ! Code tested with Arduino MEGA2560
 * @date 2024-01-05
 */

#include "Array.h"

Array<uint32_t,12> test1 = {{34,32,66,34,35,23,44,78,56,240,2323,234}};
const Array<uint32_t,10> test2 = {{1,7,3,7,35,23,44,78,56,240}};
Array<float,5> test3 = {{1.45,425.0,234.9,234.4,567.4}};
Array<float,8> test4 = {{false,false,true,true,false,true,true,true}};
void setup()
{
  Serial.begin(9600);

  // Try to Access an out of range index
  Serial.println(test1.at(16));
  Serial.println(test2.at(14));
  Serial.println(test3.at(10));
  Serial.println(test4.at(20));

  Serial.println("########");

  //Try to Access an in range index
  Serial.println(test1.at(5));
  Serial.println(test2.at(3));
  Serial.println(test3.at(2));
  Serial.println(test4.at(6));

}

void loop()
{

}