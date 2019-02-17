/*
 * Filename         : structs_memory1.c
 * Title            : Structs and Memory Investigation 1
 * Author           : Konstantin Rebrov
 * Language         : C
 * Created on       : 04 Feb 2017
 * Last modified on : 29 Dec 2018 (Name change)
 * Description: This program demonstrates various pointer/memory address
 *              tricks with structs.
 * Sources: Lecture 3 | Programming Paradigms (Stanford)
 *          https://www.youtube.com/watch?v=H4MQXBF6FN4
 */

#include <stdio.h>   // C standard input/output - for printf() and scanf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS
#include <stdint.h>  // C standard integer data types


struct Fraction {
  int num;
  int denum;
};


int main() {
  struct Fraction pi;

  pi.num = 5;
  pi.denum = 20;

  printf("The first  field of the struct is: %d ", pi.num);
  printf("Address: %p\n", &pi.num);
  printf("The second field of the struct is: %d ", pi.denum);
  printf("Address: %p\n", &pi.denum);

  printf("\n");

  printf("struct Fraction pi takes up %lu bytes\n", sizeof(pi));
  printf("pi.num takes up %lu bytes\n", sizeof(pi.num));
  printf("pi.denum takes up %lu bytes\n", sizeof(pi.denum));

  printf("\n");

  // this gives me a pointer to a struct, 8 bytes starting at &(pi.denum)
  // then dereferencing that pointer modifies pi.denum
  ((struct Fraction*) &(pi.denum))->num = 12;
  printf("The first  field of the struct is: %d ", pi.num);
  printf("Address: %p\n", &pi.num);
  printf("The second field of the struct is: %d ", pi.denum);
  printf("Address: %p\n", &pi.denum);

  printf("\n");

  // writes to the denum field of an "imaginary" struct.
  // That number is written to four bytes ahead of pi.denum
  ((struct Fraction*) &(pi.denum))->denum = 33;

  int* ptr = &pi.num;
  for (int i = 0; i < 3; i++) {
    printf("Address: %p | Data: %d\n", ptr, *ptr);
    ptr++;
  }
  printf("\n");

  printf("Data: %d\n", (&pi)[1].num);  // gets 33 out
  printf("Data: %d\n", (*((&pi) + 1)).num);  // gets 33 out

  printf("\n");

  ((&pi) + 1)->denum = 100;
 
  ptr = &pi.num;
  for (int i = 0; i < 4; i++) {
    printf("Address: %p | Data: %d\n", ptr, *ptr);
    ptr++;
  }
  printf("\n");

  return EXIT_SUCCESS;
}
