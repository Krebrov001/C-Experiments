/*
 * Name        : factorial.c
 * Author      : Konstantin Rebrov
 * Date        : 03/26/2017
 * Language    : C
 * Description : This program experiments with solving factorials recursively
 * Sources     : https://www.youtube.com/watch?v=t4MSwiqfLaY
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
  // print out the numbers being multiplied
  printf("%i %c ", num, (num == 1) ? '=' : '*');
  if (num == 1)
    return 1;
  return num * factorial(num - 1);
}

int main()
{
  printf("Enter a positive integer: ");
  int number;
  scanf("%i", &number);

  if (number < 1) {
    fprintf(stderr, "The number %i must be > %i\n", number, 0);
    exit(EXIT_FAILURE);
  }

  printf("%i! = %i\n", number, factorial(number));

  return EXIT_SUCCESS;
}
