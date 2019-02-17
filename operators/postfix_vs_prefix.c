/**
 * This program demonstrates the difference between prefix and postfix
 * increment and decrement, short-circuiting of logical operators,
 * and what true and false values evaluate to in the C programming language.
 *
 * Operators in C (Solved Problem 2)
 * https://www.youtube.com/watch?v=-QXh0y__tYY&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=36
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a = 1;
  int b = 1;

  int c = ++a || b++;
  // 2 || b++
  // T || b++  short-circuits!
  //   T
  //   1

  int d = b-- && --a;
  // 1 && --a
  // T && --a  does not short-circuit
  // T && 1
  // T && T
  //   T
  //   1

  // prints 1 1 0 1
  printf("%d %d %d %d\n", d, c, b, a);

  return EXIT_SUCCESS;
}
