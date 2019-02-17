/*
 * Name        : bad_pointer.cpp
 * Author      : Konstantin Rebrov
 * Date        : 03/24/2017
 * Description : This program demonstrates a pointer that goes out of bounds.
 *               To use this program the LOOP command line macro must be
 *               defined to an int at compilation,
 *               and one of the following command line macros must be defined
 *                 INT_PTR  CHAR_PTR  STRING_PTR  (INT_PTR is reccommended)
 *               Sample compilation:
 *                 g++ -D INT_PTR -D LOOP=500 bad_pointer.cpp
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main() {
  #ifdef INT_PTR
  int num1 = 5;
  int* bad_ptr = &num1;
  cout << "Address of num1: " << &num1 << endl;
  cout << "Dereference bad pointer: " << *bad_ptr << endl;
  
  // The bad pointer acesses LOOP memory addresses
  // LOOP is a command-line macro
  for (int i = 0; i < LOOP; i++) {
    bad_ptr++;
    cout << "Dereference bad pointer: " << *bad_ptr << endl;
  }
  #endif

  #ifdef CHAR_PTR
  char char1 = 'A';
  char* bad_ptr = &char1;
  cout << "Address of char1: " << &char1 << endl;
  cout << "Dereference bad pointer: " << *bad_ptr << endl;
  
  // The bad pointer acesses LOOP memory addresses
  // LOOP is a command-line macro
  for (int i = 0; i < LOOP; i++) {
    bad_ptr++;
    cout << "Dereference bad pointer: " << *bad_ptr << endl;
  }
  #endif

  #ifdef STRING_PTR
  string string1 = "Hello";
  string* bad_ptr = &string1;
  cout << "Address of string1: " << &string1 << endl;
  cout << "Dereference bad pointer: " << *bad_ptr << endl;
  
  // The bad pointer acesses LOOP memory addresses
  // LOOP is a command-line macro
  for (int i = 0; i < LOOP; i++) {
    bad_ptr++;
    cout << "Dereference bad pointer: " << *bad_ptr << endl;
  }
  #endif

  return 0;
}
