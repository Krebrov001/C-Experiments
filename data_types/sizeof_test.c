/*
 * Name        : sizeof_test.c
 * Author      : Konstantin Rebrov
 * Date        : 05/02/2017
 * Language    : C
 * Description : This program demonstrates using the sizeof function/operator in C/C++.
 * Sources     : https://www.youtube.com/watch?v=zxb8DvLUqcM&index=9&
 */

#include <stdlib.h>   // includes EXIT_SUCCESS
#include <stdio.h>    // includes printf()
#include <stdbool.h>  // includes bool (only for C not for C++)

int main() {
  int a = sizeof(int);
  printf("int has %d bytes\n", a);

  a = sizeof(unsigned int);
  printf("unsigned int has %d bytes\n", a);

  a = sizeof(char);
  printf("char has %d bytes\n", a);

  a = sizeof(float);
  printf("float has %d bytes\n", a);

  a = sizeof(double);
  printf("double has %d bytes\n", a);

  // a = sizeof(unsigned double);  // error: ‘signed’ or ‘unsigned’ invalid for ‘type name’
  // printf("unsigned double has %d bytes\n", a);

  a = sizeof(long long);
  printf("long long has %d bytes\n", a);

  a = sizeof(long long int);
  printf("long long int has %d bytes\n", a);

  a = sizeof(bool);
  printf("bool has %d bytes\n", a);

  int b = 5;
  char c = 'a';

  a = sizeof(b);
  printf("sizeof int b is %d\n", a);

  a = sizeof(c);
  printf("sizeof char c is %d\n", a);

  return EXIT_SUCCESS;
}
