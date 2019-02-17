#include <iostream>  // C++ input/output stream
#include <climits>   // C limits of integral data types - for INT_MIN, INT_MAX, UINT_MAX
#include <cstdlib>   // C standard library - for EXIT_SUCCESS

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
 * This is a templated function.
 * It accepts a value "object" of any data type, which is labeled as "T".
 *
 * The __PRETTY_FUNCTION__ is a GNU compiler extension which is actually
 * a C-string that evaluates to the "pretty" name of a function,
 * means including the function's return type and the types of its
 * formal parameters.
 *
 * I'm using __PRETTY_FUNCTION__ to determine the data type of the passed
 * in expression to the function, during the runtime!
 */
template<typename T>
void foo(T value)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //std::cout << value << std::endl;
}

// The C++ way to write main() !
int main() {
    // Real professional programmers indent by 4 spaces!

    foo(-2147483648);   // long int      -2147483648
    foo(0x80000000);    // unsigned int   2147483648
    foo(INT_MIN);       // int           -2147483648
    foo(-INT_MAX - 1);  // int           -2147483648

    std::cout << std::endl;

    /* This code demonstrates that signed int is the same as int. */
    signed int a = 5;
    foo(a);            /* int */
    foo(7);            /* int */

    /* This code demonstrates that unsigned is the same as unsigned int. */
    unsigned b = 8;
    unsigned int c = 9;
    foo(b);             /* unsigned int */
    foo(c);             /* unsigned int */
    foo(10u);           /* unsigned int */

    std::cout << std::endl;

    //                            32-bit             64-bit
    foo(32767);               // signed int       signed int
    foo(50L);                 // long int         long int
    foo(9223372036854775806L); // long long int   long int
    foo(55UL);             // long unsigned int  long unsigned int
    foo(18446744073709551614lu); // long long unsigned int  long unsigned int
    foo(0x8000000000000000l); // long long unsigned int  long unsigned int
    foo(030uLL);              // long long unsigned int  long long unsigned int
    foo(0x7fffffffffffffffl); // long long int      long int
    foo(3.14);                //   double           double
    foo(3.14f);               //   float            float

    short int number = 3;
    foo(number);
    foo(number + 5);
    foo('a');
    foo('a' + 0);
    foo(5 + 2llu);
    foo(number + 'a');
    foo(-2 + 0u);
    foo(-number);
    foo(+number);
    foo(+'b');
    foo(4.0 + 5);
    foo(+3.14f);
    foo(4.0f + 5);
    char one = 120, two = 50;
    foo(one + two);
    foo(true + true);

    foo(-9223372036854775808);

    return EXIT_SUCCESS;
}
