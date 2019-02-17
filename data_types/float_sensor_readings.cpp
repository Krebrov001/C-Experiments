/*
 * Name             : float_sensor_readings.cpp
 * Title            : Floating Point Comparison - Sensor Readings
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 11 January 2017
 * Last modified on : 11 January 2017
 * Description      : This program demonstrates floating point comparison.
 * Sources          : Zybooks C++ Challenge Activity 11.3.1
 */

#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
#include <cmath>     // C math library     - for fabs()
//#include <ios>
#include <iomanip>   // C++ input/output manipulators - for std::setprecision
                     //                                 and std::fixed
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

#define EPSILON 0.0001

int main() {
  double targetValue = 0.3333;
  double sensorReading = 0.0;

  sensorReading = 1.0/3.0;

  if (fabs(sensorReading - targetValue) < EPSILON) {
    cout << "Equal" << endl;
  } else {
    cout << "Not equal" << endl;
  }

  cout << endl;

  // setprecision can be used to see what the actual floating-point value is
  // represented as
  cout << setprecision(25) << fixed;
  cout << "targetValue:         " << targetValue << endl;
  cout << "sensorReading:       " << sensorReading << endl;
  cout << "epsilon:             " << EPSILON << endl;
  cout << "absolute difference: " << fabs(sensorReading - targetValue) << endl;

  return EXIT_SUCCESS;
}
