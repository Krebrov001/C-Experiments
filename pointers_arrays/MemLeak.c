#include <stdio.h>    /* C standard input/output - for printf(), scanf(), getchar() */
#include <stdlib.h>   /* C standard library      - for EXIT_SUCCESS, malloc() */
#include <ctype.h>    /* C character type        - for toupper() */
#include <stdbool.h>  /* C standard bool         - for true */

/* Uninitialized static global variable is stored in the bss section,
   and automatically set to 0 by default. */
static size_t totalBytesAllocated = 0;

void allocateMemory();

int main(void)
{
  char input;

  printf("Welcome to the memory leak program.\n\n");

  while (true) {
    printf("===================================================\n");
    printf("Allocate an additional 1 KB of dynamic memory? ");

    fflush(stdin);
    input = getchar();

    if (toupper(input) != 'Y')
      break;

    allocateMemory();
  }

  printf("===================================================\n");
  printf("\nTotal allocated data is %lu bytes.\n\n", totalBytesAllocated);

  fflush(stdin);
  getchar();  /* To keep the terminal window from closing suddenly. */

  return EXIT_SUCCESS;
}

void allocateMemory()
{
  /* Allocates 256 * 4 == 1024 bytes == 1 KB */
  size_t bytesToAllocate = 256 * sizeof(int);
  totalBytesAllocated += bytesToAllocate;
  int* ptr = malloc(bytesToAllocate);
  printf("\t1 KB of memory allocated.\n\n");

  /* The dynamic memory is not freed when the function returns.
     We have a memory leak! */
  free(ptr);

  return;
}
