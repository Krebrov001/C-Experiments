/**
 * Precedence and Associativity of Operators
 * https://www.youtube.com/watch?v=8H9G621pQq0&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=34
 */
#include <stdio.h>

int main() {
  int a = 10, b = 20, c = 30, d = 40;

  /* TRUE will be printed.
     Relational operators  <  >  <=  >= have a higher precedence
     than equality operators  ==  !=
     This code will execute as:
     (a <= b) == (d > c)
     (10 <= 20) == (40 > 30)
     1 == 1
     1
   */

  if (a <= b == d > c) {
    printf("TRUE");
  } else {
    printf("FALSE");
  }

  return 0;
}
