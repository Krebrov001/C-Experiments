#include <stdio.h>
#include <time.h>    // C time library     - for time()
#include <stdlib.h>  // C standard library - for EXIT_SUCCESS, rand()

int main(void)
{
  const char* message = "Enter a number [0 - 3] inclusive: ";
  // printf accepts a const char*,
  // the base address of a C-string
  // Gets rid of warning:
  // format not a string literal and no format arguments
  printf("%s", message);

  int number;
  scanf("%d", &number);

  /*
   * The scope of the variable int inner_var starts from inside case 1
   * and continues until the }.
   * In case 2, 3, and default, the variable int inner_var is still in
   * scope, but the initialization of inner_var is skipped.
   * So the code accesses an uninitialized variable.
   */
  switch (number) {
    case 0:
      printf("case 0: nothing happens\n");
      break;
    case 1:
      ;  // There should be a statement after the label.
      int inner_var = 8;
      printf("case 1: inner_var defined\n");
      printf("inner_var = %d\n", inner_var);
      break;
    case 2:
      printf("case 2: inner_var definition skipped\n");
      printf("inner_var = %d\n", inner_var);
      break;
    case 3:
      printf("case 3: inner_var definition skipped\n");
      printf("inner_var assigned 4\n");
      inner_var = 4;
      printf("inner_var = %d\n", inner_var);
      break;
    default:
      printf("default case\n");
      break;
  }

  srand(time(NULL));

  // rand() returns a random number, either even or odd
  // % 2 returns 0 if it is an even number, and 1 if it is an odd number
  // An even number or an odd number is equally likely.
  // The effect is that either 1 (true) or 0 (false) is equally likely
  if (rand() % 2) {
    goto Label;
  }

  printf("int outer_var initialized\n");
  int outer_var = 5;

  // If the above conditional statement is true, the program execution
  // jumps over the initialization of int outer_var.
  // However, int outer_var is in scope nonetheless!
  Label:
  printf("%d\n", outer_var);

  return EXIT_SUCCESS;
}
