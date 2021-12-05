//***********************************************************************
// CS2720A - Fall 2020 - Text Based Adventure Game
// Instructor: Dr. John Anvik
// Escape The Hotel - Team Infinity
//
// Exeptions for test files
// Authours: Jackson Druhan, Jacob Lachowski, Muhammad Saleh, James Smith
// Date: Nov 1, 2020
//***********************************************************************

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>
/**
* Exception for class with invalid parameter
*/
class invalid_parameter: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_parameter(const char* errMessage) :
  std::runtime_error(errMessage) {}
};

#endif
