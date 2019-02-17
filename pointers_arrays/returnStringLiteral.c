#include <stdio.h>
#include <stdlib.h>

char* returnStringLiteral()
{
  // "Hello World" returns the base address of the string literal,
  // a pointer to the first char 'H'.
  char* myString = "Hello World";
  // Returns a pointer to the string literal "Hello World";
  return myString;
}


int main(void)
{
  // cptr is now also set to point to "Hello World"
  char* cptr = returnStringLiteral();
  // At initialization of C-string only!
  // Copies char-by-char starting at the given base address
  // into the C-string until it hits a '\0'.
  char cString[] = "Hello World";
  //char cString[] = returnStringLiteral();

  // Prints the character string and the base address from where it starts.
  // I am using the string literal "Hello World" as a kind of
  // global variable here.

  printf("string literal:\n");
  printf("%p : %s\n", "Hello World", "Hello World");

  printf("cptr:\n");
  printf("%p : %s\n", cptr, cptr);

  printf("cString:\n");
  printf("%p : %s\n", cString, cString);

  return EXIT_SUCCESS;
}
