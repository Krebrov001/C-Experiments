#include "file3.h"  /* Declaration made availible here */
#include "prog1.h"  /* Function declarations */

/* Variable defined here */
int global_variable = 37;    /* Definition checked against declaration */

int increment() {
  return global_variable++;
}
