#include <stdio.h>
#include "file3.h"  /* Declaration of global_variable */
#include "prog1.h"  /* Function declarations */

int main() {
  use_it();
  global_variable += 19;
  use_it();
  printf("Increment: %d\n", increment());

  return 0;
}
