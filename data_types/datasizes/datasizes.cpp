/*
 * Size of Data Types
 *
 * written by:          Konstantin Rebrov
 * created on:          17 December 2017
 * last modified on:    18 December 2017
 *
 * This program prints out the sizes of various C++ data types,
 * first using the name of the variable as the argument to the sizeof() operator,
 * and then using the data type itself as the argument to the sizeof() operator.
 * This program is intended to be compiled by multiple compilers on multiple operating systems and/or architectures
 * to determine the sizes of the data types on that particular implementation so that the programmer can confidently
 * use the standard C++ data types, knowing their size and also their range.
 *
 */
#include <iostream>
using std::cout;
using std::endl;
using std::string;
// There is a bool data type in C++.
#include <cwchar>  // includes the wchar_t type
#include <cstdint>  // includes the C standard int types, [u]intX_t types

int main() {
  bool condition;

  signed char            signed_char;
  unsigned char          unsigned_char;
  signed short int       signed_short_int;
  unsigned short int     unsigned_short_int;
  signed int             signed_int;
  unsigned int           unsigned_int;
  signed long int        signed_long_int;
  unsigned long int      unsigned_long_int;
  signed long long int   singed_long_long_int;
  unsigned long long int unsigned_long_long_int;

  wchar_t letter;

  float         pi1;
  double        pi2;
  long double   pi3;

  char*         ptr1;
  short*        ptr2;
  int*          ptr3;
  unsigned int* ptr4;
  float*        ptr5;
  double*       ptr6;
  void*         ptr7;

  int8_t    num1;
  uint8_t   num2;
  int16_t   num3;
  uint16_t  num4;
  int32_t   num5;
  uint32_t  num6;
  int64_t   num7;
  uint64_t  num8;

  cout << "The C++ programming language." << endl;
  cout << "signed char is:             " << sizeof(signed_char) << " bytes" << endl;
  cout << "unsigned char is:           " << sizeof(unsigned_char) << " bytes" << endl;
  cout << "signed short int is:        " << sizeof(signed_short_int) << " bytes" << endl;
  cout << "unsigned short int is:      " << sizeof(unsigned_short_int) << " bytes" << endl;;
  cout << "signed int is:              " << sizeof(signed_int) << " bytes" << endl;
  cout << "unsigned int is:            " << sizeof(unsigned_int) << " bytes" << endl;
  cout << "signed long int is:         " << sizeof(signed_long_int) << " bytes" << endl;
  cout << "unsigned long int is:       " << sizeof(unsigned_long_int) << " bytes" << endl;
  cout << "signed long long int is:    " << sizeof(singed_long_long_int) << " bytes" << endl;
  cout << "unsigned long long int is:  " << sizeof(unsigned_long_long_int) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "signed char is:             " << sizeof(signed char) << " bytes" << endl;
  cout << "unsigned char is:           " << sizeof(unsigned char) << " bytes" << endl;
  cout << "signed short int is:        " << sizeof(signed short int) << " bytes" << endl;
  cout << "unsigned short int is:      " << sizeof(unsigned short int) << " bytes" << endl;
  cout << "signed int is:              " << sizeof(signed int) << " bytes" << endl;
  cout << "unsigned int is:            " << sizeof(unsigned int) << " bytes" << endl;
  cout << "signed long int is:         " << sizeof(signed long int) << " bytes" << endl;
  cout << "unsigned long int is:       " << sizeof(unsigned long int) << " bytes" << endl;
  cout << "signed long long int is:    " << sizeof(signed long long int) << " bytes" << endl;
  cout << "unsigned long long int is:  " << sizeof(unsigned long long int) << " bytes" << endl;
  
  cout << string(40, '-') << endl;

  cout << "bool is:         " << sizeof(condition) << " bytes" << endl;
  cout << "wchar_t is:      " << sizeof(letter) << " bytes" << endl;
  cout << "float is:        " << sizeof(pi1) << " bytes" << endl;
  cout << "double is:       " << sizeof(pi2) << " bytes" << endl;
  cout << "long double is:  " << sizeof(pi3) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "bool is:         " << sizeof(bool) << " bytes" << endl;
  cout << "wchar_t is:      " << sizeof(wchar_t) << " bytes" << endl;
  cout << "float is:        " << sizeof(float) << " bytes" << endl;
  cout << "double is:       " << sizeof(double) << " bytes" << endl;
  cout << "long double is:  " << sizeof(long double) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "char pointer is:          " << sizeof(ptr1) << " bytes" << endl;
  cout << "short pointer is:         " << sizeof(ptr2) << " bytes" << endl;
  cout << "int pointer is:           " << sizeof(ptr3) << " bytes" << endl;
  cout << "unsigned int pointer is:  " << sizeof(ptr4) << " bytes" << endl;
  cout << "float pointer is:         " << sizeof(ptr5) << " bytes" << endl;
  cout << "double pointer is:        " << sizeof(ptr6) << " bytes" << endl;
  cout << "void pointer is:          " << sizeof(ptr7) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "char pointer is:          " << sizeof(char*) << " bytes" << endl;
  cout << "short pointer is:         " << sizeof(short*) << " bytes" << endl;
  cout << "int pointer is:           " << sizeof(int*) << " bytes" << endl;
  cout << "unsigned int pointer is:  " << sizeof(unsigned int*) << " bytes" << endl;
  cout << "float pointer is:         " << sizeof(float*) << " bytes" << endl;
  cout << "double pointer is:        " << sizeof(double*) << " bytes" << endl;
  cout << "void pointer is:          " << sizeof(void*) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "int8_t is:    " << sizeof(num1) << " bytes" << endl;
  cout << "uint8_t is:   " << sizeof(num2) << " bytes" << endl;
  cout << "int16_t is:   " << sizeof(num3) << " bytes" << endl;
  cout << "uint16_t is:  " << sizeof(num4) << " bytes" << endl;
  cout << "int32_t is:   " << sizeof(num5) << " bytes" << endl;
  cout << "uint32_t is:  " << sizeof(num6) << " bytes" << endl;
  cout << "int64_t is:   " << sizeof(num7) << " bytes" << endl;
  cout << "uint64_t is:  " << sizeof(num8) << " bytes" << endl;

  cout << string(40, '-') << endl;

  cout << "int8_t is:    " << sizeof(int8_t) << " bytes" << endl;
  cout << "uint8_t is:   " << sizeof(uint8_t) << " bytes" << endl;
  cout << "int16_t is:   " << sizeof(int16_t) << " bytes" << endl;
  cout << "uint16_t is:  " << sizeof(uint16_t) << " bytes" << endl;
  cout << "int32_t is:   " << sizeof(int32_t) << " bytes" << endl;
  cout << "uint32_t is:  " << sizeof(uint32_t) << " bytes" << endl;
  cout << "int64_t is:   " << sizeof(int64_t) << " bytes" << endl;
  cout << "uint64_t is:  " << sizeof(uint64_t) << " bytes" << endl;

  return 0;
}

