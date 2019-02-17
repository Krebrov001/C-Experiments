/*
 * The size of a union is the size of its largest field.
 * The size of a struct is the size of all its fields,
 * and also including any optional padding for alignment.
 */

#include <stdio.h>
#include <stdlib.h>

typedef union
{
  int a;
  float b;
  double c;  /* 8 bytes, largest field */
} myUnion;

typedef struct
{
  int a;
  float b;
  double c;
} myStruct;

int main(void) {
  printf("%zu\n", sizeof(myUnion));
  printf("%zu\n", sizeof(myStruct));

  return EXIT_SUCCESS;
}
