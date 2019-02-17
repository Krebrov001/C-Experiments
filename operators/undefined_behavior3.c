/*
 * This program demonstrates undefined behavior in C.
 * The order of evaluation of subexpressions in C is not guaranteed.
 * Try this program with different compilers.
 *
 * Sequence Points in C | Set 1
 * https://www.geeksforgeeks.org/sequence-points-in-c-set-1/
 */
// PROGRAM 3
#include <stdio.h>


int main(void)
{
  int i = 8;
  int p = i++ * i++;  // we are modifying a variable twice in a single expression.
  printf("%d\n", p);  // both clang and gcc generate 72 == 8 * 9 ?
  return 0;
}
