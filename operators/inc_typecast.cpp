/*
 * Name: inc_typecast.cpp
 * Author: Konstantin Rebrov
 * Description : Using Luke Sathrum's lecture slides to make my own examples
 *               of Increment/Decrement Operators and Type Casting.
 */

#include <iostream> // C++ input/output stream
                    // for cout, cin, endl, and overloaded bitshift operators.
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  int a = 5;
  int b = ++a + a++;  // NOTE: undefined behavior, a is modified twice in a sequence point!
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << "10 / 3 = " << (10 / 3) << endl;
  cout << "10 % 3 = " << (10 % 3) << endl;
  // static_cast<output data type>(argument)
  cout << "10 / 3.0 = " << (10 / static_cast<float>(3)) << endl;
  cout << "10.0 / 3 = " << (static_cast<double>(10) / 3) << endl;

  double c = 1.99999999;
  a = static_cast<int>(c);
  if (a == 1) {
    cout << "example of a bug" << endl;
  }

  return 0;
}
