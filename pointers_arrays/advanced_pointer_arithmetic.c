#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>  /* C standard definitions - for ptrdiff_t */

void printShortArray(short* Array, size_t arraySize) {
  for (size_t i = 0; i < arraySize; i++) {
    printf("%hd ", Array[i]);
  }
  printf("\n");
}

int main(void) {
  int A[] = {8, 5, 3, 9, 2, 0, 1};
  int* p = &A[0];
  /* The following statements are the same. */
  /*
  printf("%p\n", p);
  p = A;
  printf("%p\n", p);
  p = &A;
  printf("%p\n", p);
  */

  int* q = &A[3];
  /* both these statements are equivalent. */
  /*
  printf("%p\n", q);
  q = A+3;
  printf("%p\n", q);
  */

  ptrdiff_t i = q - p;

  printf("p:\t%td\n", p);
  printf("q:\t%td\n", q);
  printf("p:\t%td\n", (ptrdiff_t)p);
  printf("q:\t%td\n", (ptrdiff_t)q);
  printf("%td\n", (ptrdiff_t)q - (ptrdiff_t)p);
  printf("%td\n", ((ptrdiff_t)q - (ptrdiff_t)p) / sizeof(*p));
  printf("%td\n", i);

  printf("\n");

  printf("sizeof(int*): %zu\n", sizeof(int*));
  printf("sizeof(size_t): %zu\n", sizeof(size_t));
  printf("sizeof(ptrdiff_t): %zu\n", sizeof(ptrdiff_t));

  printf("\n");

  char B[] = "wisdom";

  char* r = &B[0];
  char* s = &B[3];
  /* ptrdiff_t */ i = r - s;

  printf("r:\t%td\n", r);
  printf("s:\t%td\n", s);
  printf("r:\t%td\n", (ptrdiff_t)r);
  printf("s:\t%td\n", (ptrdiff_t)s);
  printf("%td\n", (ptrdiff_t)r - (ptrdiff_t)s);
  printf("%td\n", ((ptrdiff_t)r - (ptrdiff_t)s) / sizeof(*r));
  printf("%td\n", i);

  double C[] = {0.1, 3.14, 2.7, 8.9, 2.5, 3.0};

  double* t = &C[1];
  double* u = &C[5];
  /* ptrdiff_t */ i = t - u;

  printf("t:\t%td\n", t);
  printf("u:\t%td\n", u);
  printf("t:\t%td\n", (ptrdiff_t)t);
  printf("u:\t%td\n", (ptrdiff_t)u);
  printf("%td\n", (ptrdiff_t)t - (ptrdiff_t)u);
  printf("%td\n", ((ptrdiff_t)t - (ptrdiff_t)u) / sizeof(double));
  printf("%td\n", i);

  printf("\n");

  short Array[] = {5, 8, 9, 6, 10};
  short* ptr = &Array[0];

  printShortArray(Array, 5);
  printf("%lu\n", ptr);

  //printf("%d\n", ++*ptr);
  //printf("%d\n", *++ptr);
  printf("%d\n", *ptr++);

  printShortArray(Array, 5);
  printf("%lu\n", ptr);

  return EXIT_SUCCESS;
}
