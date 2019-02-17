#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <string.h>  // C strings library

void func() {
  int* pointer = malloc(sizeof(int));
  free(pointer);
}

int main() {

  for (int i = 0; i < 100000000000; i++) {
    func();
  }

  return EXIT_SUCCESS;
}
