/* Mathematical Properties of floating-point operations
   Floating point operations are not always associative or
   distributive, due to rounding.
   doubles give you a more accurate result
   When you're not sure, prepare for trouble, just use double!
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  float pi = 3.14;
  float bignum = 1e10;

  printf("3.14: %f\n", pi);
  printf("1e10: %f\n", bignum);
  printf("\n");

  printf("calculations with floats:\n");
  printf("(3.14 + 1e10) is %f\n", (float) (3.14 + 1e10));
  printf("(3.14 + 1e10) - 1e10 is %f\n", (float) (3.14 + 1e10) - 1e10);
  printf("(1e10 - 1e10) is %f\n", (float) (1e10 - 1e10));
  printf("3.14 + (1e10 - 1e10) is %f\n", (float) 3.14 + (1e10 - 1e10));
  printf("\n");

  printf("calculations with doubles:\n");
  printf("(3.14 + 1e10) is %f\n", (double) (3.14 + 1e10));
  printf("(3.14 + 1e10) - 1e10 is %f\n", (double) (3.14 + 1e10) - 1e10);
  printf("(1e10 - 1e10) is %f\n", (double) (1e10 - 1e10));
  printf("3.14 + (1e10 - 1e10) is %f\n", (double) 3.14 + (1e10 - 1e10));
  printf("\n");

  float reallyBigNum = 1e20;

  printf("1e20: %f\n", reallyBigNum);
  printf("\n");

  printf("calculations with floats:\n");
  printf("(1e20 - 1e20) is %f\n", (float) (1e20 - 1e20));
  printf("1e20 * (1e20 - 1e20) is %f\n", (float) 1e20 * (1e20 - 1e20));
  printf("(1e20 * 1e20) is %f\n", (float) (1e20 * 1e20));
  printf("(1e20 * 1e20) - (1e20 * 1e20) is %f\n", (float) (1e20 * 1e20) - (1e20 * 1e20));
  printf("\n");

  printf("calculations with doubles:\n");
  printf("(1e20 - 1e20) is %f\n", (double) (1e20 - 1e20));
  printf("1e20 * (1e20 - 1e20) is %f\n", (double) 1e20 * (1e20 - 1e20));
  printf("(1e20 * 1e20) is %f\n", (double) (1e20 * 1e20));
  printf("(1e20 * 1e20) - (1e20 * 1e20) is %f\n", (double) (1e20 * 1e20) - (1e20 * 1e20));
  printf("\n");

  return EXIT_SUCCESS;
}
