/*
 * This program demonstrates undefined behavior in C.
 * The order of evaluation of subexpressions in C is not guaranteed.
 * Try this program with different compilers.
 *
 * Sequence Points in C | Set 1
 * https://www.geeksforgeeks.org/sequence-points-in-c-set-1/
 */
// PROGRAM 1
#include <stdio.h>

/* global variable */
int x = 20;

/* The called functions have side effects which change the value of the
   global variable. Depending on the order in which the functions will
   get called, the resulting value assigned to p will be different.
   both gcc and clang give a result of 55. */

int f1()
{
  x = x + 10;
  return x;
}


int f2()
{
  x = x - 5;
  return x;
}


int main(void)
{
  int p = f1() + f2();
  printf("p = %d\n", p);
  return 0;
}
