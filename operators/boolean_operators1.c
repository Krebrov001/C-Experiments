/**
 * Neso Academy Bitwise Operators in C (Part 1)
 * https://www.youtube.com/watch?v=jlQmeyce65Q&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=27
 *
 * This program demonstrates the difference between bitwise and logical
 * boolean operators.
 */
#include <stdio.h>

int main(void)
{
  char x = 1, y = 2;  // x = 1(0000_0001), y = 2(0000_0010)

  if (x & y)                           // 1 & 2 = 0(0000_0000) == FALSE
    printf("Result of x & y is 1\n");

  if (x && y)                          // 1 && 2 = TRUE && TRUE = TRUE = 1
    printf("Result of x && y is 1\n");

  return 0;
}
