#include <stdio.h>   // C standard input/output
#include <stdlib.h>  // C standard library - for EXIT_SUCCESS
#include <stdint.h>  // C standard integer data types

int main() {
  uint32_t a = 0x12345678;

  uint8_t b = *(uint8_t*)&a;

  printf("a: %#x\n", a);
  printf("b: %#hhx\n", b);

  return EXIT_SUCCESS;
}
