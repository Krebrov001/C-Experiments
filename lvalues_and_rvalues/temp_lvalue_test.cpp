#include <iostream>
using std::endl;
using std::cout;

int main() {
  // Creating a temp lvalue out of an rvalue
  // and assigning it to an lvalue reference variable.
  // For more information about how this code works, see:
  //    lvalue_rvalue.cpp
  const int& r = 5;

  // Should output 5.
  cout << "r = " << r << endl;

  //                               address of r
  cout << "this lvalue resides at: " << &r << endl;

  int* p = (int*) &r;
  cout << p << " : " << *p << endl;

  int i = 2;
  int& ref = i;
  cout << endl;

  cout << "i: " << i << " address of i: " << &i << endl;

  // Case 1: int& lvalue = int lvalue;
  // attempting to relabel the r
  //r = i;  // error: assignment of read-only reference ‘r’

  // Case 2: int& lvalue = int& lvalue;
  // attempting to relabel the r
  //r = ref;  // error: assignment of read-only reference ‘r’

  // Case 3: int& lvalue = int rvalue;
  // attempting to change the data at the memory location referenced by r
  //r = 4;  // error: assignment of read-only reference ‘r’

  return 0;
}
