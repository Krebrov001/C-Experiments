#include <stdio.h>
#include <stdlib.h>

#define PRINT_SIZEOF(x) printf(#x ": %zu\n", sizeof(x))

int main(void) {
  int C[3][2][2] = {
    { {2,5}, {7,9} },
    { {3,4}, {6,1} },
    { {0,8}, {11,13} }
    };

  // prints each 2-D array
  for (int i = 0; i < 3; i++) {
    // prints each 1-D array
    for (int j = 0; j < 2; j++) {
      // prints each int
      for (int k = 0; k < 2; k++) {
        printf("C[%d][%d][%d] : %d ", i, j, k, C[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  int (*p)[2][2] = C;

  PRINT_SIZEOF(C[0][0][0]);
  PRINT_SIZEOF(C[0][0]);
  PRINT_SIZEOF(C[0]);
  PRINT_SIZEOF(C);

  return EXIT_SUCCESS;
}
