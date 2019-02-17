/*
 * Name        : recursive_sum.c
 * Author      : Konstantin Rebrov
 * Date        : 03/26/2017
 * Language    : C
 * Description : This program finds the recursive sum of a number,
 *               means find the sum of all consecutive positive integers
 *               from that number to 1.
 * Sources     : https://www.youtube.com/watch?v=t4MSwiqfLaY
 */

#include <stdio.h>
#include <stdlib.h>

int recursiveSum(int num) {
  // print out the numbers being added
  printf("%i %c ", num, (num == 1) ? '=' : '+');
  if (num == 1)
    return 1;
  return num + recursiveSum(num - 1);
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

  printf("The recursive sum of %i:\n", number);
  printf("%i\n", recursiveSum(number));

  return EXIT_SUCCESS;
}
