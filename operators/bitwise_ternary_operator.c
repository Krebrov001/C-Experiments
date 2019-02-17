/*
 * Implementing Conditional Ternary Operator using bitwise operators
 *
 * Numbers, Video 4: Bit shifting and sign extension
 * https://www.youtube.com/watch?v=ns01z-02ofY&list=PL0oekSefhQVJdk0hSRu6sZ2teWM740NtL&index=13
 */
#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS, rand()
#include <time.h>    // C time library          - for time()

#define PRINT_INT(x) printf("%s : %d\n", #x, x)

int main(void)
{
  int x = 0;  /* our "boolean" value */

  /* seed the random number generator */
  srand(time(NULL));

  /* every number is either even or odd.
     % 2 is either 1 or 0. */
  x = rand() % 2;

  /* our two values */
  int y = 5, z = 8;

  /* The regular ternary conditional operator. */
  int result1 = x ? y : z;

  /* My version of the ternary operator. */
  int result2 = ((x<<31)>>31) & y  |  ((!x<<31)>>31) & z;

  /* << 31 shifts the least-significant bit into the most-significant
     bit position. >> 31 then shifts that bit into the least-significant
     bit position, this time extending the most-significant sign bit.
     if x is 1, the result is all 1's
     if x is 0, the result is all 0's
     One of the variables is ANDed with all 1's, letting the value go
     through.
     The other variable is ANDed with all 0's zeroing out that value.
     One of the values is necessarily unchanged, the other one is
     necessarily zeroed out.
     The | combines these two values into one,
     it selects the value which was unchanged.
   */

  PRINT_INT(result1);
  PRINT_INT(result2);

  return EXIT_SUCCESS;
}
