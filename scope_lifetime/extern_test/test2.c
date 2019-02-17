#include <stdio.h>
#include "global_includefile.h"

// In C, all variables must be declared before they are used.
// You can only use a variable inside the scope of its declaration.
// This statement is an explicit declaration, allowing us to use
// the variable int test1_var, which is defined in test1.c,
// in this file test2.c
extern int test1_var;

int main() {
  printf("test1_var = %d\n", test1_var);

  printf("other_variable = %d\n", other_variable);

  say_hello();

  printf("other_variable = %d\n", other_variable);

  return 0;
}
