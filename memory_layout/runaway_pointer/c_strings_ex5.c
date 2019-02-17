/*
 The string literals "house" and "bear" are stored in the .rodata segment
 of the memory, sometiems also called the text segment.
 The Print() function prints the base address of the passed in string literal,
 the address of the pointer itself in the stack frame, and the entire string
 literal until it hits a '\0'.
 The PrintText() function prints 1000 chars directly in memory after the passed
 in string literal.
 Here the string literal "house", residing in the .rodata segment is passed into
 the PrintText() function, which then prints out 1000 chars in the .rodata
 segment.
 This demonstrates a point:
 The string literal "bear" directly follows the string literal "house" in the
 memory, which is in turn followed by the string literal "%p".
 */
#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <string.h>  // C strings library

#define WORD_A "house"
#define WORD_B "bear"

void Print(const char* word);

void PrintText(const char* word);

int main() {
  Print(WORD_A);
  Print(WORD_B);
  printf("\n");
  PrintText(WORD_A);

  return EXIT_SUCCESS;
}

void Print(const char* word) {
  printf("%p\n", word);
  printf("%p\n", &word);
  int i = 0;
  while (*(word+i) != '\0') {
    printf("%c", *(word+i));
    i++;
  }
  printf("\n");
  return;
}

void PrintText(const char* word) {
  for (int i = 0; i < 10000; i++) {
    printf("%c", *(word + i));
  }
  printf("\n");
}
