#include <stdio.h>     // C standard input/output - for printf()
#include <stdlib.h>    // C standard library      - for EXIT_SUCCESS
#include <locale.h>    // C locale library        - for setlocale()
#include "toBinary.h"  // toBinary library        - for printFormatted8bits()

int main(void)
{
  /*
  char* locale_name = setlocale(LC_CTYPE, "en_US.utf8");
  if (locale_name == NULL) {
    exit(EXIT_FAILURE);
  } else {
    printf("locale set to %s\n", locale_name);
  }
  */

  unsigned char charValue;

  printf("  %-8s%8s%10s%8s%12s\n", "binary", "hex", "unsigned", "signed", "character");
  
  for (charValue = 0; charValue != 255; charValue++) {
    printFormatted8bits(charValue);
    printf("%#8hhx%10hhu%+8hhi%8c\n", charValue, charValue, charValue, charValue);
  }
  printFormatted8bits(charValue);
  printf("%#8hhx%10hhu%+8hhi%8c\n", charValue, charValue, charValue, charValue);

  return EXIT_SUCCESS;
}
