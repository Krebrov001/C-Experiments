/**
 * Homework Question: What will be the output of this program?
 * Neso Academy : Conditional Operator in C
 * https://www.youtube.com/watch?v=rULDbIbrXis&index=32&list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM
 */
#include <stdio.h>

int main() {
  int var  = 75;
  int var2 = 56;
  int num;

  num = sizeof(var) ? (var2 > 23 ? ((var == 75) ? 'A' : 0) : 0) : 0;

  printf("%d\n", num);
  return 0;
}
