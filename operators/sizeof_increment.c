/**
 * Operators in C (Solved Problem 1)
 * https://www.youtube.com/watch?v=HAKAhma7MQg&index=35&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM
 */
#include <stdio.h>

int main() {
  int i = 5;

  /* sizeof(a) will evaluate its operand only if the operand is of a
     variable length array type. */

  // sizeof(a) operator does not evaluate its operand
  // i++ will not execute, i does not get incremented!
  int var = sizeof(i++);

  // prints 5 4
  printf("%d %d\n", i, var);

  return 0;
}
