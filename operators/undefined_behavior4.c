/**
 * This program demonstrates yet another example of undefined behaviors.
 *
 * The first example comes from javaTpoint C Operators and Exp. Quiz - 3
 * I found an error in the official answer, that did not take undefined
 * behavior into account.
 *
 * The second example I made up by myself to demonstrate that the order
 * of evaluation of the function arguments is undefined.
 * clang appears to evaluate the function arguments left to right
 * gcc appears to evaluate the function arguments right to left
 *
 * The third example is taken from:
 * Evaluation of Expressions inside printf in C [duplicate]
 * https://stackoverflow.com/questions/39161508/evaluation-of-expressions-inside-printf-in-c
 */
#include <stdio.h>


int one()
{
  printf("one");
  return 1;
}


int two()
{
  printf("two");
  return 2;
}


int three()
{
  printf("three");
  return 3;
}


int main()
{
  int x = 5;
  printf("%d %d %d\n", x <= 55, x = 5, x >= 10);

  x = 5;
  printf("%d %d %d\n", x <= 55, x = 90, x >= 10);

  int i = 0;
  printf("%d %d %d\n", i, i++, i++);
  printf("%d\n", i);

  printf("%d %d %d\n", one(), two(), three());

  return 0;
}
