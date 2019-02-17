/*
 * Name             : double_inexact.cpp
 * Title            : Observing the inexact values stored in floating-point variables.
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 11 January 2017
 * Last modified on : 11 January 2017
 * Description      : This program demonstrates imprecision of double values.
 *                    Using just cout prints the value as the user would expect,
 *                    the assigned double value, or an int constant for whole
 *                    numbers, or rounded to 5 decimal places for M_PI AND M_E,
 *                    or inf and nan for INFINITY and HUGE_VAL, and NAN.
 *                    std::setprecision(25) shows the actual value stored in the
 *                    double variable to 25 decimal places. This is very useful
 *                    for observing floating-point imprecision.
 * Sources          : Zybooks C++ Figure 11.3.2
 */

#include <iostream>  // C++ input/output stream
#include <ios>
#include <iomanip>
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
#include <cmath>     // C math library     - for M_PI, M_E, INFINITY,
                     //                          NAN, HUGE_VAL
using std::cout;
using std::endl;
using std::setprecision;

int main() {
  // define the variables
  double sampleValue1 = 0.2;
  double sampleValue2 = 0.3;
  double sampleValue3 = 0.7;
  double sampleValue4 = 0.0;        // same as 0
  double sampleValue5 = 0.25;
  double sampleValue6 = 0.5;
  double sampleValue7 = 0.125;
  double sampleValue8 = 0.4;
  double sampleValue9 = 5.0;        // same as 5
  double sampleValue10 = 8.129;
  double sampleValue11 = 9.5;
  double sampleValue12 = M_PI;
  double sampleValue13 = M_E;
  double sampleValue14 = INFINITY;
  double sampleValue15 = NAN;
  double sampleValue16 = HUGE_VAL;
  double sampleValue17 = 7.0;       // same as 7

  cout << "sampleValue1 using just cout: " << sampleValue1 << endl;
  cout << "sampleValue2 using just cout: " << sampleValue2 << endl;
  cout << "sampleValue3 using just cout: " << sampleValue3 << endl;
  cout << "sampleValue4 using just cout: " << sampleValue4 << endl;
  cout << "sampleValue5 using just cout: " << sampleValue5 << endl;
  cout << "sampleValue6 using just cout: " << sampleValue6 << endl;
  cout << "sampleValue7 using just cout: " << sampleValue7 << endl;
  cout << "sampleValue8 using just cout: " << sampleValue8 << endl;
  cout << "sampleValue9 using just cout: " << sampleValue9 << endl;
  cout << "sampleValue10 using just cout: " << sampleValue10 << endl;
  cout << "sampleValue11 using just cout: " << sampleValue11 << endl;
  cout << "sampleValue12 using just cout: " << sampleValue12 << endl;
  cout << "sampleValue13 using just cout: " << sampleValue13 << endl;
  cout << "sampleValue14 using just cout: " << sampleValue14 << endl;
  cout << "sampleValue15 using just cout: " << sampleValue15 << endl;
  cout << "sampleValue16 using just cout: " << sampleValue16 << endl;
  cout << "sampleValue17 using just cout: " << sampleValue17 << endl;

  cout << endl;

  cout << setprecision(25);
  cout << "sampleValue1 is: " << sampleValue1 << endl;
  cout << "sampleValue2 is: " << sampleValue2 << endl;
  cout << "sampleValue3 is: " << sampleValue3 << endl;
  cout << "sampleValue4 is: " << sampleValue4 << endl;
  cout << "sampleValue5 is: " << sampleValue5 << endl;
  cout << "sampleValue6 is: " << sampleValue6 << endl;
  cout << "sampleValue7 is: " << sampleValue7 << endl;
  cout << "sampleValue8 is: " << sampleValue8 << endl;
  cout << "sampleValue9 is: " << sampleValue9 << endl;
  cout << "sampleValue10 is: " << sampleValue10 << endl;
  cout << "sampleValue11 is: " << sampleValue11 << endl;
  cout << "sampleValue12 is: " << sampleValue12 << endl;
  cout << "sampleValue13 is: " << sampleValue13 << endl;
  cout << "sampleValue14 is: " << sampleValue14 << endl;
  cout << "sampleValue15 is: " << sampleValue15 << endl;
  cout << "sampleValue16 is: " << sampleValue16 << endl;
  cout << "sampleValue17 is: " << sampleValue17 << endl;

  return EXIT_SUCCESS;
}
