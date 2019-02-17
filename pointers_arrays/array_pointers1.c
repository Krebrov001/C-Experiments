#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int A[5] = {5, 8, 9, 6, 10};
  int* p = A;
  printf("%p\n", A);
  printf("%p\n", &A);
  printf("%p\n", &A[0]);

  printf("%d\n", A[2]);
  printf("%d\n", 2[A]);

  printf("%d\n", *(A + 2));
  printf("%d\n", *(2 + A));

  printf("%c\n", "ABCD"[2]);
  printf("%c\n", 2["ABCD"]);

  int i = 0;
  for (i = 0; "Hello World"[i] != '\0'; i++)
    putchar(i["Hello World"]);

  return 0;
}
