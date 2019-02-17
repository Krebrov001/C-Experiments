#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <string.h>  // C strings library       - for strlen()

int main() {
  char name[4];
  //char name[5];
  name[0] = 'J';
  name[1] = 'O';
  name[2] = 'H';
  name[3] = 'N';
  //name[4] = '\0';

  printf("%s\n", name);
  /******************************

  strlen() returns a size_t, which is an unsigned integer type capable
  of holding an array index.
  a size_t is also the type returned by the sizeof() operator
  To find out what size_t is typedef'd to, use the following command:
      echo | gcc -E -xc -include 'stddef.h' - | grep size_t
      typedef long unsigned int size_t;
  The printf format length and specifier for long unsigned int is %lu

   ******************************/
  printf("The string has %lu printable characters\n", strlen(name));

  return EXIT_SUCCESS;
}
