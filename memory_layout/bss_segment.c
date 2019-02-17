#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS

static int i;
static int i = 27;
static int i;

int main(void)
{
  static int i;
  printf("%d\n", i);

  return EXIT_SUCCESS;
}
