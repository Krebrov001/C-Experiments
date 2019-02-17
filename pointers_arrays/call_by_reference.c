/*
 * Name             : call_by_reference.c
 * Author           : Konstantin Rebrov
 * Created on       : 07 January 2017
 * Last modified on : 07 January 2017
 * Description      : This program demonstrates different forms of parameters
 *                    when calling a function.
 * Sources:         : https://www.youtube.com/watch?v=LW8Rfh6TzGg
 *                    https://www.youtube.com/watch?v=UWYnUGnChhA
 *                    https://www.youtube.com/watch?v=sxHng1iufQE
 */

#include <stdio.h>   // C standard input/output
#include <stdlib.h>  // C standard library

/*
 * This function demonstrates pass by value.
 * int x = a;
 * This is allowed in pure C.
 */
void passByVal(int x) {
  printf("  Inside function\n");
  x = x + 1;
  printf("  Value of a:   %d\n", x);
  printf("  Address of a: %p\n", &x);  // pointer address
}

/*
 * This function demonstrates pass by reference.
 * int& x = a;
 * reference variables are only in C++, not in C.
 * So to use this feature, this file should be compiled as:
 * g++ call_by_reference.c
 */
void passByRef(int& x) {
  printf("  Inside function\n");
  x = x + 1;
  printf("  Value of a:   %d\n", x);
  printf("  Address of a: %p\n", &x);
}

/*
 * This function demonstrates pass by pointer.
 * int* x = &a;
 * This is allowed in pure C.
 */
void passByPtr(int* x) {
  printf("  Inside function\n");
  *x = (*x) + 1;
  printf("  Value of a:   %d\n", *x);
  printf("  Address of a: %p\n", x);
}

// This is the main method of the program.
// The program starts here at runtime.
int main() {
  int a = 5;
  printf("Value of a:   %d\n", a);
  printf("Address of a: %p\n", &a);  // pointer address
  passByVal(a);  // a++
  //passByRef(a);  // a++
  //passByPtr(&a);  // a++
  printf("Back in main()\n");
  printf("Value of a:   %d\n", a);
  printf("Address of a: %p\n", &a);

  printf("\n");

  /*
   * This code demonstrates that taking the address of a reference variable
   * is the exact same thing as taking the address of the original variable.
   * Note: references are only in C++.
   */
  int& b = a;
  printf("Value of b:   %d\n", b);
  printf("Address of b: %p\n", &b);
  int* ptr;
  ptr = &b;  // same as ptr = &a;
  printf("Value in ptr: %p\n", ptr);
  *ptr = 12;
  printf("Value of a:   %d\n", a);
  printf("Address of a: %p\n", &a);
  printf("Value of b:   %d\n", b);
  printf("Address of b: %p\n", &b);

  return EXIT_SUCCESS;
}
