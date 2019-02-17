/*
 * C programming test 1
 *
 * written by			Konstantin Rebrov
 * created on			13 November 2017
 * last modified on		13 November 2017
 *
 * This is just a test of various features of the C programming language.
 * It is in fact a demonstration of Derek Banas's Youtube tutorial: "C Video Tutorial"
 *
 */

#include <stdio.h>
#include <string.h>

// #define inserts text anywhere in the program except for inside a string
#define MY_NAME "Konstantin"
#define RASPBERRY pi

int main() {
  char initial = 'K';
  int number = 19;
  long int big_number = 1234567890;
  char name[18] = "Konstantin Rebrov";
//  float pi = 3.141592654;
  float pi = 2.56;
  double big_pi = 3.1415926542343243243242341234;
  double floater = 2.5e5;

  // %d is for digit (int), %f is for float (or double)
  // %ld is for long digit, AKA long int
  printf("\n");
  printf("Your name is %s and you are %d years old.\n", name, number);
  // here, #define inserts a string constant as the second argument of printf()
  printf("My name: %s\n", MY_NAME);
  printf("The big number is: %ld \n", big_number);
  printf("charater: %c, ASCII value: %d\n\n", initial, (int) initial);  // double \n here
  
  number = 1.5e3;
  printf("1 thousand 500: %d\n", number);

  printf("\nfloater:\n");
  printf("%f\n%e\n%g\n", floater, floater, floater);

  printf("\n");
  printf("int: %ld bytes\n", sizeof(int));
  printf("long long: %ld bytes\n", sizeof(long long));
  printf("long int: %ld bytes\n", sizeof(long int));
  printf("unsigned int: %ld bytes\n", sizeof(unsigned int));
  printf("unsigned long long: %ld bytes\n", sizeof(unsigned long long));
  printf("unsigned long int: %ld bytes\n", sizeof(unsigned long int));
  printf("char: %ld bytes\n", sizeof(char));
  printf("float: %ld bytes\n", sizeof(float));
  printf("double: %ld bytes\n", sizeof(double));
  printf("long double: %ld bytes\n", sizeof(long double));
  //printf("bool: %ld bytes\n", sizeof(bool));
  printf("\n");

  /*
  // by default, printf() prints out 6 decimal places for %f without the decimal specifier
  // here, #define inserts the name of a variable
  printf("pi: %f\n", RASPBERRY);
  // here, #define doesn't work because the keyword to replace is inside a string
  printf("pi: RASPBERRY\n");
  // %f works for doubles too (not only floats)
  printf("Very long pi: %f\n", big_pi);

  // decimal specifier prints a float or a double with various precisions
  printf("pi: %.0f\n", RASPBERRY);
  printf("pi: %.1f\n", RASPBERRY);
  printf("pi: %.2f\n", RASPBERRY);
  printf("pi: %.3f\n", RASPBERRY);
  printf("pi: %.4f\n", RASPBERRY);
  printf("pi: %.5f\n", RASPBERRY);
  printf("pi: %.6f\n", RASPBERRY);
  printf("pi: %.7f\n", RASPBERRY);
  printf("pi: %.8f\n", RASPBERRY);
  printf("pi: %.9f\n", RASPBERRY);
  printf("pi: %.10f\n", RASPBERRY);
  printf("pi: %.11f\n", RASPBERRY);
  printf("pi: %.12f\n", RASPBERRY);
  */

  return 0;
}

