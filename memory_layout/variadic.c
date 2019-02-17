#include <stdio.h>
#include <stdarg.h>

void simple_printf(...) {
  va_list args;
  va_start(args);

  int sum = 0;
  int i = va_arg(args, int);
  sum += i;
  i = va_arg(args, int);
  sum += i;
  printf("sum = %d\n", sum);
}

int main(void) {
  simple_printf(3, 4);

  return 0;
}
