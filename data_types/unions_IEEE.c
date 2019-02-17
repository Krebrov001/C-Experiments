#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef unsigned int hex_number_t;

typedef union {
  float f;
  hex_number_t h;
} IEEE;

int main(void) {
  IEEE num1;
  num1.f = 0;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.h = 0x7f800000;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.h = 0xff800000;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.f = 2.75;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.h = 0x7f800008;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.f = M_PI;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.f = 0.1;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.f = FLT_MAX;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  num1.f = FLT_MIN;

  printf("num1.f = %f\n", num1.f);
  printf("num1.h = %#x\n", num1.h);
  printf("\n");

  return EXIT_SUCCESS;
}
