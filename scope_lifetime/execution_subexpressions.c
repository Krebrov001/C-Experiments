#include <stdio.h>
#include <stdlib.h>

int one(void)
{
  printf("One ");
  return 1;
}

int two(void)
{
  printf("Two ");
  return 1;
}

int main(void) {
  one()+two();
  one()&&two();
  printf("\n");
  two()+one();
  two()&&one();
  printf("\n");
  return EXIT_SUCCESS;
}
