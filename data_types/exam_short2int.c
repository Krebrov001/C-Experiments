#include <stdio.h>

int main() {
  unsigned int x = 0xDEADBEEF;
  unsigned short y = 0xFFFF;
  signed int z = -1;
  if (x > (signed short) y)
    printf("Hello");
  if (x > z)
    printf("World");
}
