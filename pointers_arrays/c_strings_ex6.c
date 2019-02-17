// character arrays and pointers
#include <stdio.h>
#include <string.h>

void print(const char* B) {
  /* B[0] = 'A'; */

  while (*B != '\0') {
    printf("%c", *B);
    B++;
  }
  printf("\n");
}

int main() {
  //char C[] = "Hello";  // string gets stored in the space allocated for array
  char* C = "Hello";  // string gets stored as a compile time constant
                      // in the text segment of the program
  //C[0] = 'A';  // runtime error because you cannot change the
                 // value of a string literal stored in the text segment of the program
  print(C);

  return 0;
}
