/*
 * Size of Data Types
 *
 * written by:          Konstantin Rebrov
 * created on:          17 December 2017
 * last modified on:    18 December 2017
 *
 * This program prints out the sizes of various data types,
 * first using the name of the variable as the argument to the sizeof() operator,
 * and then using the data type itself as the argument to the sizeof() operator.
 * It is important to note that sizeof() returns the number of bytes something takes up as a long int.
 * Therefore, in the C programming language, we have to use %ld as the format specifier/ conversion character.
 * This program is intended to be compiled by multiple compilers on multiple operating systems and/or architectures
 * to determine the sizes of the data types on that particular implementation so that the programmer can confidently
 * use the standard C data types, knowing their size and also their range.
 *
 */
#include <stdio.h>  // includes printf() and scanf()
// Unlike in C++, there is no specific bool data type in the C programming language.
// stdbool.h defines bool, true, and false to be used in C programs.
#include <stdbool.h>
#include <wchar.h>  // includes the wchar_t type
#include <stdint.h>  // includes [u]intX_t types

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

  printf("The C programming language.\n");
  // sizeof() returns long int
  printf("signed char is:             %2ld bytes\n", sizeof(signed_char));
  printf("unsigned char is:           %2ld bytes\n", sizeof(unsigned_char));
  printf("signed short int is:        %2ld bytes\n", sizeof(signed_short_int));
  printf("unsigned short int is:      %2ld bytes\n", sizeof(unsigned_short_int));
  printf("signed int is:              %2ld bytes\n", sizeof(signed_int));
  printf("unsigned int is:            %2ld bytes\n", sizeof(unsigned_int));
  printf("signed long int is:         %2ld bytes\n", sizeof(signed_long_int));
  printf("unsigned long int is:       %2ld bytes\n", sizeof(unsigned_long_int));
  printf("signed long long int is:    %2ld bytes\n", sizeof(singed_long_long_int));
  printf("unsigned long long int is:  %2ld bytes\n", sizeof(unsigned_long_long_int));
  
  printf("----------------------------------------\n");

  printf("signed char is:             %2ld bytes\n", sizeof(signed char));
  printf("unsigned char is:           %2ld bytes\n", sizeof(unsigned char));
  printf("signed short int is:        %2ld bytes\n", sizeof(signed short int));
  printf("unsigned short int is:      %2ld bytes\n", sizeof(unsigned short int));
  printf("signed int is:              %2ld bytes\n", sizeof(signed int));
  printf("unsigned int is:            %2ld bytes\n", sizeof(unsigned int));
  printf("signed long int is:         %2ld bytes\n", sizeof(signed long int));
  printf("unsigned long int is:       %2ld bytes\n", sizeof(unsigned long int));
  printf("signed long long int is:    %2ld bytes\n", sizeof(signed long long int));
  printf("unsigned long long int is:  %2ld bytes\n", sizeof(unsigned long long int));
  
  printf("----------------------------------------\n");

  printf("bool is:         %2ld bytes\n", sizeof(condition));
  printf("wchar_t is:      %2ld bytes\n", sizeof(letter));
  printf("float is:        %2ld bytes\n", sizeof(pi1));
  printf("double is:       %2ld bytes\n", sizeof(pi2));
  printf("long double is:  %2ld bytes\n", sizeof(pi3));

  printf("----------------------------------------\n");

  printf("bool is:         %2ld bytes\n", sizeof(bool));
  printf("wchar_t is:      %2ld bytes\n", sizeof(wchar_t));
  printf("float is:        %2ld bytes\n", sizeof(float));
  printf("double is:       %2ld bytes\n", sizeof(double));
  printf("long double is:  %2ld bytes\n", sizeof(long double));

  printf("----------------------------------------\n");

  printf("char pointer is:          %2ld bytes\n", sizeof(ptr1));
  printf("short pointer is:         %2ld bytes\n", sizeof(ptr2));
  printf("int pointer is:           %2ld bytes\n", sizeof(ptr3));
  printf("unsigned int pointer is:  %2ld bytes\n", sizeof(ptr4));
  printf("float pointer is:         %2ld bytes\n", sizeof(ptr5));
  printf("double pointer is:        %2ld bytes\n", sizeof(ptr6));
  printf("void pointer is:          %2ld bytes\n", sizeof(ptr7));

  printf("----------------------------------------\n");

  printf("char pointer is:          %2ld bytes\n", sizeof(char*));
  printf("short pointer is:         %2ld bytes\n", sizeof(short*));
  printf("int pointer is:           %2ld bytes\n", sizeof(int*));
  printf("unsigned int pointer is:  %2ld bytes\n", sizeof(unsigned int*));
  printf("float pointer is:         %2ld bytes\n", sizeof(float*));
  printf("double pointer is:        %2ld bytes\n", sizeof(double*));
  printf("void pointer is:          %2ld bytes\n", sizeof(void*));

  printf("----------------------------------------\n");

  printf("int8_t is:    %2ld bytes\n", sizeof(num1));
  printf("uint8_t is:   %2ld bytes\n", sizeof(num2));
  printf("int16_t is:   %2ld bytes\n", sizeof(num3));
  printf("uint16_t is:  %2ld bytes\n", sizeof(num4));
  printf("int32_t is:   %2ld bytes\n", sizeof(num5));
  printf("uint32_t is:  %2ld bytes\n", sizeof(num6));
  printf("int64_t is:   %2ld bytes\n", sizeof(num7));
  printf("uint64_t is:  %2ld bytes\n", sizeof(num8));

  printf("----------------------------------------\n");

  printf("int8_t is:    %2ld bytes\n", sizeof(int8_t));
  printf("uint8_t is:   %2ld bytes\n", sizeof(uint8_t));
  printf("int16_t is:   %2ld bytes\n", sizeof(int16_t));
  printf("uint16_t is:  %2ld bytes\n", sizeof(uint16_t));
  printf("int32_t is:   %2ld bytes\n", sizeof(int32_t));
  printf("uint32_t is:  %2ld bytes\n", sizeof(uint32_t));
  printf("int64_t is:   %2ld bytes\n", sizeof(int64_t));
  printf("uint64_t is:  %2ld bytes\n", sizeof(uint64_t));

  return 0;
}

