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


int f1()
{
  printf("Geeks");
  return 1;
}


int f2()
{
  printf("forGeeks");
  return 1;
}


int main(void)
{
  int p = f1() + f2();
  printf("%d\n", p);
  return 0;
}
