/*
 * Int Data Overflow
 *
 * written by:          Konstantin Rebrov
 * created on:          18 December 2017
 * last modified on:    18 December 2017
 * sources: mycodeschool Know your data type: int - C Programming Tutorial 08
 *
 * This program demonstrates what happens on integer overflow.
 * Try to enter 100000 for a and 200000 for b.
 * The output overflows the program, and the remaining bits result in
 * a negative value.
 *
 */
#include <stdio.h>

int main()
{
  int a, b, c;

  printf("Enter a: ");
  scanf("%d", &a);
  printf("Enter b: ");
  scanf("%d", &b);

  c = a * b;
  printf("a * b = %d\n", c);

  return 0;
}

