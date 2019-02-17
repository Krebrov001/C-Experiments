/**
 * The ! Logical NOT operator returns an int rvalue in C,
 * and a bool rvalue in C++.
 * The C programming language has not bool data type by default.
 */
#include <stdio.h>

int main()
{
  /*
   * sizeof(0) is 4 int both C and C++ since 0 is an int rvalue
   * sizeof(!0) and sizeof(!!0) both return 4 in C

   * because they are int rvalues in C (either 1 or 0).
   * However, they return 1 in C++, because they are rvalue of type
   * bool in C++ (true or false)!
   */

  printf("0   : %d\tsizeof(0)   : %zu\n", 0,   sizeof(0));
  printf("!0  : %d\tsizeof(!0)  : %zu\n", !0,  sizeof(!0));
  printf("!!0 : %d\tsizeof(!!0) : %zu\n", !!0, sizeof(!!0));

  return 0;
}
