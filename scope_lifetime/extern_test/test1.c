#include <stdio.h>

// The definition of the variable.
// The declaration is in the file test2.c,
// which allows this variable to be used in that file
int test1_var = 5;

void say_hello() {
  printf("\n");
  printf("\tHello, World!\n");

  printf("\ttest1_var = %d\n", test1_var);

  // The extern statement is simply a declaration.
  // It says that the variable "lives" inside another translation unit.
  //     int other_variable = 10; is a definition,
  // it defines the variable, allocating space for it in that translation unit,
  // and initializes that variable to an initial value.
  //
  // The following statement will not work since we are combining
  // extern (a declaration) with an initializer (a definition).
  // This statement gives us a compiler warining.
  //extern int other_variable = 10;
  extern int other_variable;

  other_variable = 10;
  // Oops, other_variable is not in scope here.
  // identifier other_variable undeclared
  printf("\tother_variable = %d\n", other_variable);
  printf("\n");
}
