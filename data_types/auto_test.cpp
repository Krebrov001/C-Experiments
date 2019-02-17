/**
 * @file     auto_test.cpp
 * @author   Konstantin Rebrov
 * @version  07/18/2018
 * @sources  C++ Primer 2.5.2 p. 69
 *
 * @section DESCRIPTION
 *
 * This program tests out the auto keyword/type specifier.
 *
 * auto was firt introduced in C++11, so compile this program with:
 * g++ -std=c++11 auto_test.cpp
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * Generic function accepts an argument of any type.
 * It prints the type of the argument and its value.
 *
 * __PRETTY_FUNCTION__ is a GNU compiler extension which prints the
 * functions's return type and signature, clearly indicating the type of the argument.
 *
 * @param T var - T is a generic typename, a name of any type
 *                var is a local variable of that type which gets assigned
 *                the passed in argument to the function.
 */
template <typename T>
void printType(T var)
{
  cout << __PRETTY_FUNCTION__ << endl
       << var << endl
       << endl;
}

int main()
{
  int val1 = 1;
  int val2 = 2;

  // the type of item is deduced from the type of the result of adding val1 + val2
  auto item = val1 + val2;  // item is initialized to the result of val1 + val2
  printType(item);

  return 0;
}
