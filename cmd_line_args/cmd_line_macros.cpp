/*
 * Name       : cmd_line_macros.cpp
 * Date       : 03/16/2017
 * Author     : Konstantin Rebrov
 * Description: This program tests defining command-line macros when
 *              compiling the program
 *              g++ -D OPEN -D MONTH=month1 cmd_line_macros.cpp
 * Sources    : Advanced Linux Programming
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main() {
  // OPEN is optional
  #ifdef OPEN
  cout << "You defined the \"OPEN\" command-line macro" << endl;
  #endif
  cout << "Hello World\n";
  
  // MONTH is mandatory and must be the name of one of the 3 string variables
  // To set MONTH to a string:
  // g++ -D MONTH='"April"' cmd_line_macros.cpp
  // g++ -D MONTH=\"April\" cmd_line_macros.cpp
  string month1 = "January";
  string month2 = "February";
  string month3 = "March";
  cout << "The month is " << MONTH << endl;
  
  // NUM1 and NUM2 are mandatory and must be int or double values
  cout << NUM1 << '+' << NUM2 << '=' << (NUM1 + NUM2) << endl;

  #ifdef LETTER
  cout << static_cast<char>(NUM1 + NUM2) << endl;
  #endif
  
  return 0;
}
