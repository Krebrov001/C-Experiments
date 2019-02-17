/**
 * CS:APP Web Aside DATA:TMIN
 * Practice Problem 4
 *
 */
#include <stdio.h>   /* C standard input/output - for printf()     */
#include <stdlib.h>  /* C standard library      - for EXIT_SUCCESS */

/**
 * Returns the name of the variable or expression passed in as a string.
 */
#define NAME(x) #x

/**
 * Returns 1 if the passed in expression is a signed type.
 * -1 is cast to the type of the expression.
 * If it is signed, -1 < 0 == 1 (TRUE)
 * If it is unsigned, UMax < 0 == 0 (FALSE)
 */
#define IS_SIGNED_TYPE(x) ((typeof(x))-1 < 0)

int main(void)
{

    /* What data type is the literal -9223372036854775808? */

    printf("The literal is %s\n", NAME(-9223372036854775808));
    printf("The literal takes up %u bytes\n", sizeof(-9223372036854775808));
    if (IS_SIGNED_TYPE(-9223372036854775808))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");


    /* What data type is the literal 0x8000000000000000? */

    printf("The literal is %s\n", NAME(0x8000000000000000));
    printf("The literal takes up %u bytes\n", sizeof(0x8000000000000000));
    if (IS_SIGNED_TYPE(0x8000000000000000))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");


    return EXIT_SUCCESS;
}
