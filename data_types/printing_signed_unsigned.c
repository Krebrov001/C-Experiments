#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
  #include <iostream>
#endif

int main(void)
{
    signed short int v = -12345;
    unsigned short int uv = (unsigned short int) v;
    printf("v = %hd\tuv = %hu\n", v, uv);
    printf("v = %hx\tuv = %hx\n", v, uv);

    /// In C, we can print a signed number as unsigned and
    /// an unsigned number as signed!
    /// The bit pattern is the same, it doesn't care in what
    /// format to print them.
    /// Information is bits + context!
    printf("v = %hu\tuv = %hi\n", v, uv);

    /// C++ overloaded output operators automatically recognize
    /// the data type of the variable to be printed, and print it
    /// accordingly, sometimes useful, other times not.
    /// Prints v as a signed short int,
    /// and uv as an unsigned short int.
    #ifdef __cplusplus
      std::cout << "v = " << v << "\tuv = " << uv << std::endl;
    #endif

    printf("UINT_MAX: %d, %x, %u\n", UINT_MAX, UINT_MAX, UINT_MAX);

    return EXIT_SUCCESS;
}
