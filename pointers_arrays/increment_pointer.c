#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  const char* p = "Hello";
  while (*p++)
    printf("%c", *p);
  return 0;
}
