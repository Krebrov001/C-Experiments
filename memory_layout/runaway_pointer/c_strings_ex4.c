/**
 * This program exists to prove a point, that the command-line arguments and environment variables
 * are stored in higher addresses of memory, directly above the stack space for the main() function.
 * There is a runaway pointer here on purpose:
 * If we print all bytes in memory starting from a memory location in the stack, and going up
 * towards higher memory addresses, we would eventually see the command-line arguments and
 * environment variables.
 */
#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <string.h>  // C strings library


/* This function has a runaway pointer! */
void Print(const char* word);


int main() {
  char greeting[20] = "Hello";
  char myName[] = "Konstantin";
  printf("%p\n", greeting);
  printf("%p\n", &greeting);
  Print(greeting);
  Print(myName);
  Print("cat");

  return EXIT_SUCCESS;
}

/* const char* means that the data that the pointer points to cannot be modified */
void Print(const char* word) {
  printf("%p\n", word);
  printf("%p\n", &word);
  int i = 0;
  while ((*word+i) != '\0') {
    printf("%c", *(word+i));
    i++;
  }
  printf("\n");
  return;
}
