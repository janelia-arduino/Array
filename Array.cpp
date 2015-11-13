// ----------------------------------------------------------------------------
// Array.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Array.h"


// handle diagnostic informations given by assertion and abort program execution:
// void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp)
// {
//   // transmit diagnostic informations through serial link.
//   // Serial.println(__func);
//   // Serial.println(__file);
//   // Serial.println(__lineno, DEC);
//   // Serial.println(__sexp);
//   Serial.println("Attempted to access out of bounds Array element!");
//   Serial.println("Check indicies or increase Array size.");
//   Serial.flush();
//   // abort program execution.
//   abort();
// }
