/**
 * @file     c_limits_TMin.c
 * @author   Konstantin Rebrov
 * @version  modified version 2 : 07/08/2018
 *
 * @section DESCRIPTION
 *
 * This program applies the knowledge presented in CS:APP Web Aside DATA:TMIN
 * Writing TMin in C.
 *
 * This program tests the issues associated with range of int,
 * Assuming data types of integer literals and expressions by the C compiler
 * in 32 and 64-bit programs, under the ISO C90 and ISO C99 standards,
 * and determining the data types of such expressions.
 *
 * This program seeks to answer the question, why do we define INT_MIN as
 * #define INT_MIN (-INT_MAX - 1)
 *
 * Because this code uses the GNU C Compiler extension typeof(),
 * it should be compiled as -std=gnu89 for ISO C90 and -std=gnu99 for ISO C99.
 * This code is intender to be compiled as:
 *   gcc -m32 -std=gnu89 c_limits_Tmin.c     As a 32-bit program under the ISO C90 standard
 *   gcc -m64 -std=gnu89 c_limits_Tmin.c     As a 64-bit program under the ISO C90 standard
 *   gcc -m32 -std=gnu99 c_limits_Tmin.c     As a 32-bit program under the ISO C99 standard
 *   gcc -m64 -std=gnu99 c_limits_Tmin.c     As a 64-bit program under the ISO C99 standard
 *
 * A note about this modified version 2:
 * I am using (or shall we say rather exploiting) the feature that this program is to be
 * compiled using multiple settings as 32 and 64-bit program unde multiple standards.
 * Another used feature is that this program gives me the ability to determine the type of
 * an expression.
 * Here I use these features to determine if C90 supports long long literals (with LL suffix)
 * Apparently, long long is supported as a GCC compiler extension.
 */
#include <stdlib.h>  /* C standard library - for EXIT_SUCCESS */
#include <stdio.h>   /* C standard input/output - for printf(), putchar() */
#include <limits.h>  /* C limits of integral data types - for INT_MIN, INT_MAX, UINT_MAX */

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

/**
 * Prints an int variable and the value.
 */
#define PRINT_INT(x) printf("%s : %d\n", #x, x);

int main(void)
{
    /* Prints out the values of INT_MAX, INT_MIN, and UINT_MAX. */

    signed   int a = INT_MAX;
    signed   int b = INT_MIN;
    unsigned int c = UINT_MAX;

    printf("a = %i\n", a);
    printf("b = %i\n", b);
    printf("c = %u\n", c);

    putchar('\n');  /* this is the same as putc('\n', stdout); */

    /*
    This code tests alternative values for INT_MIN.
    The following literals equivalent to INT_MIN actually do not fit into an int
    This code determines the data types of these integer literals.
    -2147483648 is actually the integer literal 2147483648 (which does not not into an int)
    with the unary - operator applied to it.
    0x80000000 likewise won't fit into an int since it is greater than the hexadecimal
    representation for INT_MAX 0x7fffffff.
    */

    /*
    The sizeof() operator returns the size in bytes that the type
    of the expression operand takes up.
    IS_SIGNED_TYPE() macro returns 1 (true) if the expression is of a signed type,
    and 0 if it is of an unsigned type.
    */

    /*
    This code is intended to be compiled both as a 32 and a 64-bit program,
    under the ISO C90 and ISO C99 standards.
    Using this scheme, we can find out what data types the integer literals get by the compiler.
    */

    /* What data type is the literal 2147483648? */

    printf("The literal is %s\n", NAME(-2147483648));
    printf("The literal takes up %zu bytes\n", sizeof(-2147483648));
    if (IS_SIGNED_TYPE(-2147483648))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");

    /* What data type is the literal 0x80000000? */

    printf("The literal is %s\n", NAME(0x80000000));
    printf("The literal takes up %zu bytes\n", sizeof(0x80000000));
    if (IS_SIGNED_TYPE(0x80000000))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");

    /* What data type is the literal -2147483648LL? */

    printf("The literal is %s\n", NAME(-2147483648LL));
    printf("The literal takes up %zu bytes\n", sizeof(-2147483648LL));
    if (IS_SIGNED_TYPE(-2147483648LL))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");

    /*
    The following code tests whether the following expressions equivalent to INT_MIN
    evalutate to being positive of negative.
    */

    int dpos32 = (-2147483648 > 0);
    int hpos32 = (0x80000000  > 0);

    PRINT_INT(dpos32)
    PRINT_INT(hpos32)

    printf("===============================\n\n");

    /*
    In this code, dtmin32 and htmin32 are assigned integer literals which are equivalent
    to INT_MIN. The integer literals are determined by the compiler to be non-signed int
    data types. Then these integer literals of non-signed int data types, whatever
    their data types may be, are assigned to lvalues of type [signed] int.
    The bit patterns are copied into the int variables, resulting in a signed 32-bit int
    representation of the values of INT_MIN.
    We don't care what data types the original integer literals had, the resulting vairables
    are of type signed int always, and we can do arithmetic on them and compare them to other
    ints without any problems.
    Unlike #defining the literals to be INT_MIN, in which case they assume non-signed int
    data types, using int variables avoids the possible issues associated with implementation
    (compiler and the standard of the programming language).
    */

    int dtmin32 = -2147483648;
    int dpos32a = (dtmin32 > 0);
    int htmin32 = 0x80000000;
    int hpos32a = (htmin32 > 0);

    PRINT_INT(dtmin32)
    PRINT_INT(dpos32a)
    PRINT_INT(htmin32)
    PRINT_INT(hpos32a)

    if (dtmin32 == INT_MIN)
        printf("dtmin32 == INT_MIN\n");

    if (htmin32 == INT_MIN)
        printf("htmin32 == INT_MIN\n");

    /* What data type is the variable dtmin32? */

    printf("The literal is %s\n", NAME(dtmin32));
    printf("The literal takes up %zu bytes\n", sizeof(dtmin32));
    if (IS_SIGNED_TYPE(dtmin32))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");

    /* What data type is the variable htmin32? */

    printf("The literal is %s\n", NAME(htmin32));
    printf("The literal takes up %zu bytes\n", sizeof(htmin32));
    if (IS_SIGNED_TYPE(htmin32))
        printf("The literal is of a signed type.\n");
    else
        printf("The literal is of an unsigned type.\n");

    return EXIT_SUCCESS;
}

