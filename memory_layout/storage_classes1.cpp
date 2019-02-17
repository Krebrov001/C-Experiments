#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS

// Function declaration/prototype
void func(void);  // same as void func();

int count = 10; /* Global variable */

int main() {

  while (count--) {
    func();
  }

  cout << func::i << endl;

  return EXIT_SUCCESS;
}

// void inside the function parameter parentheses means that the function
// doesn't have any parameters
void func(void) {
  static int i = 5;  // local static variable
  i++;
  std::cout << "i is " << i << " and count is " << count << std::endl;
}
