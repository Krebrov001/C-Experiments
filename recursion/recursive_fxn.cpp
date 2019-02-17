/*
 * Name : recursive_fxn.cpp
 * Author : Konstantin Rebrov
 * Date :   03/24/2017
 * Description: This program tests out recursive functions.
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void recursiveFxn(int num = 0);

int main() {
  cout << "Start the program\n" << string(50, '=') << "\n\n";
  recursiveFxn(0);
  cout << endl << string(50, '=') << endl;
  cout << "End the program" << endl;

  return 0;
}

void recursiveFxn(int num) {
  cout << endl;
  cout << "Open function\n";
  cout << "number: " << num << endl;
  cout << endl;

  if (num != 10)
    recursiveFxn(num + 1);

  cout << "\nExit function (" << num << ')' << endl;
}
