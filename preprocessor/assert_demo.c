#include <stdio.h>   // C standard input/output - for printf()
#include <assert.h>  // C assert macro

int main() {
  // assert(boolean expression); evaluates to:
  //
  // ((boolean expression) ? (void) 0 : _assert("boolean expression", __FILE__, __LINE__));
  // If the boolean expression evaluates to true,
  //    (void) 0 is placed on that line,
  // If the boolean expression evaluates to false,
  //    _assert() is called with the boolean expression convered into a string (#token),
  //                        the filename in macro __FILE__,
  //                        and the line number in macro __LINE__
  //    This is necessary for assert to print the diagnostic message, indicating
  //    which condition failed, on what line, in which file was it in.
  //
  // NDEBUG (No DEBUG) can be defined
  // This macro turns off the assert macro.
  // Specifically, NDEBUG causes all calls to assert(boolean expression);
  // to be replaced with:
  // ((void) 0);
  // It replaces all calls to assert() with the "true" condition.
  // This is done because we want to deactivate assert(), and we assume
  // that the boolean expression returns true every single time.
  // Therefore, there is no need to check it,
  // because we assume that our source code has no potential problems.
  // We're done debugging already in this case.
  #line 90 "source_code.c"  // change the line number and the file name
  assert(4 > 5);

  // assert() macro should be used for internal checks only.
  // This is something that developers, not users should see.
  //
  // Use assert to test your assumptions about the state of the code (its variables)
  // at any point during the program execution.
  // Use assert:
  //   - Inside functions to test if the parameters are in a given set of values.
  //   - Before and after function calls for pre-conditions and post-conditions,
  //     to check for side effects.
  //   - When saving the return value of a function into a variable,
  //     and you want to check the return value.
  //   - Anytime you assume some variable has a certain value.
  //
  // Since the boolean expression passed to assert() should be true on normal
  // execution of the program, such using of assert() provides documentation
  // in the code for the reader, describing conditions which should be true on
  // running the code.


  #define PRINT_TOKEN(token) printf(#token ": %d\n", token);

  // expressions which have side effects should not be passed to assert()
  // defining NDEBUG will remove those expressions, changing the behavior of the code.

  int x = 5;
  PRINT_TOKEN(x)
  // assert() has a side effect here
  assert (x++ == 5);  // x++ returns the former value of x, which is 5
  PRINT_TOKEN(x)  // now x == 6

  // This is an example of bad using assert()
  // although it looks like the return value of do_something is checked,
  // defining NDEBUG will optimise away the assert() statement,
  // so the function will never get called, changing the behavior of the code.
  for (i = 0; i < 100; i++)
    assert(do_something() == 0);

  // This is the correct way to check the return value of a function.
  // First, save the return value into a temporary variable.
  // Then, pass the temporary variable into assert().
  // defining NDEBUG will remove the assert(), but it will leave the function all alone.
  for (i = 0; i < 100; i++) {
    int status = do_something();
    assert(status == 0);
  }


  // assert() is helpful for checking of NULL pointers before dereferencing them
  int* pointer = NULL;
  assert(pointer != NULL);


  // Suppose we have the following function declaration/prototype:
  // void ComputeCoin(int coin_value, int& number, int& amount_left);

  // Precondition: 0 < coinValue < 100.
  //               0 <= amountLeft < 100.

  // The assertion
  assert( (0 < coinValue) && (coinValue < 100) &&
          (0 <= amountLeft) && (amountLeft < 100) );

  // The call if the assertion holds.
  ComputeCoin(coinValue, number, amountLeft);

  // Postcondition: 0 < number < 100.
  //                0 <= amountLeft < 100.

  // The assertion
  assert( (0 < number) && (number < 100) &&
          (0 <= amountLeft) && (amountLeft < 100) );


  return 0;
}
