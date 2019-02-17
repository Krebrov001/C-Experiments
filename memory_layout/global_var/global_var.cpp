#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS

// includes the global variable
#include "include_global.cpp"

int main() {
  // prints out the global variable
  std::cout << my_number << std::endl;

  return EXIT_SUCCESS;
}
