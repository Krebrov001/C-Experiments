#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <limits.h>  // C variable limits       - for USHRT_MAX

int main(void) {
  signed short int   var1 = 0;
  unsigned short int var2 = 0;

  // This is how a professional programmer does it:
  // clean, simple, easy to read, and effective!
  while (var2 != USHRT_MAX) {
    printf("%6d %6u\n", var1, var2);
    var1++;
    var2++;
  }
  printf("%6d %6u\n", var1, var2);

  return EXIT_SUCCESS;
}
