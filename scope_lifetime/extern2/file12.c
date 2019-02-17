#include <stdio.h>
#include "prog2.h"

int i = 9;  /* Do not do this in portable code */
// Each of a number of files provides a tentative definition of the variable.
// As long as no more than one file provides an initialized definition,
// the various files end up sharing a common single definition of the variable.

void put() {
  printf("i = %d\n", i);
}
