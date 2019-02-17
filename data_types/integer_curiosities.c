/**
 * @file      integer_curiosities.c
 * @author    Konstantin Rebrov
 * @language  C/C++
 * @version   07/08/2018
 * This program demonstrates various "integer curiosities".
 * https://stackoverflow.com/a/14695400/5500589
 *
 * Here we are comparing the resulting integer literals to 0.
 * In some cases, they are converted to unsigned int or
 * signed long long int.
 *
 * This code demonstrates different behavior when being compiled
 * as a 32-bit program under the ISO C90 standard vs. under any
 * other settings in C and C++.
 * To compile this code use:
 * gcc -m32 -std=c90 integer_curiosities.c
 * gcc -m64 -std=c90 integer_curiosities.c
 * gcc -m32 -std=c99 integer_curiosities.c
 * gcc -m64 -std=c99 integer_curiosities.c
 * g++ -std=c++98 integer_curiosities.c
 * g++ -std=c++11 integer_curiosities.c
 * g++ -std=c++14 integer_curiosities.c
 */

#ifdef __cplusplus     /* Compiling C++ */
  #include <cstdlib>
  #include <climits>
  #include <iostream>
  using std::cout;
  using std::endl;
  using std::boolalpha;
#else                  /* Compiling C */
  #include <stdlib.h>
  #include <limits.h>
  #include <stdio.h>
  #include <stdbool.h>
#endif

/**
 * This function prints a bool variable in a manner dependent on the
 * programming language, either C or C++.
 * The output is identical: it prints either true or false.
 * The end result is that the function works being independent of the
 * programming language.
 */
void printBool(bool true_or_false);


int main() {
    bool b = (-2147483647        > 0);  /* false */
    bool i = (-2147483648        > 0);  /* true : result still unsigned */
    bool c = ( INT_MIN - 1       > 0);  /* true : '-' int constant overflow */
    bool f = ( 2147483647        > 0);  /* true */
    bool g = ( 2147483648        > 0);  /* true */
    bool d = ( INT_MAX + 1       > 0);  /* false : '+' int constant overflow */
    bool j = ( (int) -2147483648 > 0);  /* false */
    bool h = ( (int) 2147483648  > 0);  /* false */
    bool m = (-2147483648L       > 0);  /* true */
    bool o = (-2147483648LL      > 0);  /* false */

    printBool(b);
    printBool(i);
    printBool(c);
    printBool(f);
    printBool(g);
    printBool(d);
    printBool(j);
    printBool(h);
    printBool(m);
    printBool(o);

    return EXIT_SUCCESS;
}


/* C++ version of the function */
#ifdef __cplusplus
  void printBool(bool true_or_false) {
      cout << boolalpha << true_or_false << endl;
  }

/* C version of the function */
#else
  void printBool(bool true_or_false) {
      if (true_or_false)
          printf("true\n");
      else
          printf("false\n");
  }
#endif

