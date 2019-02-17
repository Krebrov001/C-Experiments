#include <stdio.h>
#include <stdlib.h>

void f() {
  //putchar('a');
  fputc('a', stderr);
}

#define PRINT_VAL(x) printf("%s = %d\n", #x, x)

int main(void) {
  int i = 5, b = 9;
  int c;
  c = (2, 5, 11);
  PRINT_VAL(i);
  PRINT_VAL(b);
  PRINT_VAL(c);

  printf("\n");

  int x = 10;
  int y = 15;

  /* The comma operator returns its second argument,
     in this case it prints 15 (the value of y). */
  printf("%d\n", (x, y));

  /* prints 12 */
  y = (x++, ++x);
  printf("%d\n", y);

  printf("\n");

  x = 10;
  y = (x++, printf("x = %d\n", x), ++x, printf("x = %d\n", x), x++);
  
  PRINT_VAL(y);
  PRINT_VAL(x);

  printf("\n");

  for (int j = 0; j < 2; j++, f())
    ;

  return EXIT_SUCCESS;
}
