#include <stdlib.h>


int main(void) {
  int i = 100, j = 200;
  const int* const p = &i;  // point p to i
  *p = j;       // assign the rvalue of j (200) to i,
                // change the data stored in i.
  p = &j;       // reassign p to point to j.

  return EXIT_SUCCESS;
}
