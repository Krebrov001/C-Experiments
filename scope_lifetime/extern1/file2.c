#include <stdio.h>
#include "file3.h"  /* Declaration of global_variable */
#include "prog1.h"  /* Function declarations */

void use_it() {
  printf("Global variable: %d\n", global_variable++);
}
