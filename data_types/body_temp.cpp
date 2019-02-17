/*
 * Name             : body_temp.cpp
 * Title            : Comparing floating-point numbers for equality - Body Temperature
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 10 January 2017
 * Last modified on : 10 January 2017
 * Description      : This program demonstrates how to compare floating-point
 *                    values in C/C++.
 * Sources          : Zybooks C++ Figure 11.3.1
 */

#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
#include <cmath>     // C math library     - for fabs()
using std::cout;
using std::cin;
using std::endl;

#define EPSILON 0.0001

int main() {
  float bodyTemp = 0.0;

  cout << "Enter body temperature in Fahrenheit: ";
  cin  >> bodyTemp;

  // if (bodyTemp == 98.6)
  if (fabs(bodyTemp - 98.6) < EPSILON) {
    cout << "Temperature is exactly normal." << endl;
  } else if (bodyTemp > 98.6) {
    cout << "Temperature is above normal." << endl;
  } else {  // bodyTemp < 98.6
    cout << "Temperature is below normal." << endl;
  }

  return EXIT_SUCCESS;
}
