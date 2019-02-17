/**
 * CS:APP Web Aside DATA:TMIN
 * Practice Problem 3
 *
 * This code demonstrates how to programatically find TMin for the
 * signed long int data types.
 */
#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <limits.h>  // C limits of integral data types - for LONG_MIN
#include <stdint.h>  // C standard integer data types   - for uint8_t

int main(void)
{
    signed long int TMin_long1 = 1L << (sizeof(long) << 3) - 1;
    signed long int TMin_long2 = 1L << 8 * sizeof(long) - 1;
    uint8_t tests_passed = 0;

    if (TMin_long1 == LONG_MIN) {
        printf("%ld\n", TMin_long1);
	tests_passed++;
    }

    if (TMin_long2 == LONG_MIN) {
        printf("%ld\n", TMin_long2);
	tests_passed++;
    }

    printf("Your code passed %hhu tests\n", tests_passed);

    return EXIT_SUCCESS;
}
