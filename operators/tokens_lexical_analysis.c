/**
 * Increment & Decrement Operators in C (Part 2)
 * https://www.youtube.com/watch?v=3uRoSITqXRI&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM&index=24
 *
 * This program demonstrates lexical analysis of tokens in C/C++.
 */
#include <stdio.h>

// A handy way to include C++ specific header files!
#ifdef __cplusplus
  #include <iostream>
#endif

int main() {
  int a = 4, b = 3;
  // This statement is rejected by the lexical tokens analyzer.
  //printf("%d\n", a+++++b);
  printf("%d\n", a++ + ++b);

  /* In C, both post-increment and pre-increment return rvalues, therefore
     they cannot be used on the left side of the = assignment operator.
     In C++ however, the post-increment operator returns an rvalue,
     but the pre-increment operator returns an lvalue.
     This means that the pre-increment operator can go on the left side
     of the = assignment operator.
   */
  /* The post-increment operator increments the variable and returns that
     variable's former value BEFORE the increment happenned.
     Since that is the former value, it does not represent the current
     data inside the variable. It is an rvalue.
   */
  /* The pre-increment operator increments the variable and then it returns
     the new value of the variable after it has been incremented.
     It returns the value of the increment. In other words, it returns the
     updated variable itself. The new value returned accurately describes
     the data stored inside the variable at its current state. Therefore,
     we can say that the pre-increment returns the variable a, an lvalue.
   */
  /* Both statements will not compile in C.
     The first statement, which attempts to assign an rvalue 2 into the
     rvalue a++, will not compile in C++.
     The second statement, which attempts to assign an rvalue 2 into the
     lvalue, ++a, will compile and run successfully in C++!
     It first increments a, then it returns the lvalue a,
     then the lvalue a is overwritten with 2.
     In terms of function of the program, this is equivalent to:
     ++a;
     a = 2;  // a is assigned 2
   */

  //a++ = 2;  // error: lvalue required as left operand of assignment
  ++a = 2;    // a is incremented, the it is assigned 2.

  #ifdef __cplusplus
    std::cout << a << std::endl;
  #endif
  return 0;
}
