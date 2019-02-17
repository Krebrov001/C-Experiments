/*
 * Name             : operator_precedence.cpp
 * Author           : Konstantin Rebrov
 * Created on       : 03 January 2018
 * Last modified on : 24 June 2018
 * Description      : This program tests operator precedence in the C
 *                    programming language. The main function calls several
 *                    other functions, or sub-programs to test various
 *                    features of operator precedence.
 * Sources          : https://www.youtube.com/watch?v=SO13fKrKHh4&list=PL3AEB91BB184B185B
 */

#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS

void function1() {
  int i = 1 + 2 * 3;  // 7
  printf("i = %d\n", i);
  int j = 1 * 2 * 3;  // 6
  printf("j = %d\n", j);
  j = 1 * 2 / 3;      // 0
  printf("j = %d\n", j);
  printf("\n");
}

void function2() {
  int i = 2;
  // the + operator has a higher precedence than <<
  // int j = 2 << 5;
  int j = i << 1 + 4;  // 64
  printf("i = %d\n", i);  // i = 2
  printf("j = %d\n", j);  // j = 64
  // i is not modified with the above expression,
  // but rather it is used as an rvalue.
  printf("\n");
}

void function3() {
  int i = 2, j = 5, k = 8;  // initializes 3 ints
  //if (4*6 < 9*8 && 4/2 < 2+1 || 2 << 3 > 6)
  //if (24  < 72  && 4/2 < 2+1 || 2 << 3 > 6)
  //if (T && 4/2 < 2+1 || 2 << 3 > 6)
  //if (T && 2 < 2+1 || 2 << 3 > 6)
  //if (T && 2 < 3 || 2 << 3 > 6)
  //if (T && T || 2 << 3 > 6)
  //if ( T || 2 << 3 > 6)       short-circuits the ||
  //if (T)
  if (4*6<9*8&&4/2<2+1||2<<3>6)
    printf("Inside if statement");  // this statement will execute
  printf("\n\n");
}

void function4() {
  // This statement is invalid, variables are undeclared, else would be
  // int i = 7;
  //int i=j=k=l=m=7;
  int p = 5, q = 2, r = 10;  // initializes 3 ints
  r += p *= q <<= 3;
  // r += p *= 16
  // r += 80
  printf("%d\n", r);  // 90
  printf("\n");
}

void function5() {
  int i = 1, j = 0, k = 0;
  j = i++ + ++i;
  k = i++ + i++;
  printf("i = %d\nj = %d\nk = %d\n", i, j, k);
  printf("\n");
}

int f() {
  printf("inside f\n");
  return 1;
}

int g() {
  printf("inside g\n");
  return 2;
}

int h() {
  printf("inside h\n");
  return 3;
}

int main() {
  function1();
  function2();
  function3();
  function4();
  function5();

  int final = f() + g() * h();
  printf("%d\n", final);
  // The output for the above statements is:
  /* __________
    | $
    |inside f
    |inside g
    |inside h
    |7
    |
   */
  printf("\n");

  int number = g() + f() / h();
  printf("number = %d\n", number);
  printf("\n");

  return EXIT_SUCCESS;
}
