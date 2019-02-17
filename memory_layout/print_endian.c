/**
 * This program has a collection of functions that demonstrate how to print out
 * the byte ordering (endinanness) of C data types.
 */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char* byte_ptr;

/* The .2 precision, when used with integer data types, tells the minimum
   number of digits to print, padding it with leading zeroes.
   Here, we are forcing an upper-order nibble to be printed as a hex digit,
   even if that nibble is 0.
   Normally, if the byte holds a 10, a will be printed.
   With the .2 precision modifier, 0a will be printed.
   0 is the value of the upper nibble (0000).
 */
void show_bytes(byte_ptr start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2hhx", start[i]);
    printf("\n");
}

/* These procedures pass the address of the local variable x to show_bytes()
   Effectively, the local variable residing in the show_int() or show_float()
   stack frame is printed. */

void show_int(int x) {
    show_bytes((byte_ptr) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_ptr) &x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_ptr) &x, sizeof(void*));
}

void show_short(short x) {
    show_bytes((byte_ptr) &x, sizeof(short));
}

void show_double(double x) {
    show_bytes((byte_ptr) &x, sizeof(double));
}

void test_show_bytes(int val) {
    /* initialize locals */
    int ival   = val;
    float fval = (float) ival;  /* creates a new bit pattern */
    int* pval  = &ival;

    /* short lvalue = int rvalue;
       Implicit conversion from int rvalue to a short rvalue.
       Only the least-significant 16 bits get converted into the short.
       It punts the most-significant 16 bits which do not fit into a short.
     */
    short sval = val;
    /* Once again, we have an implicit conversion of float rvalue into
       double rvalue, which then gets placed into the double lvalue dval.
       A new bit pattern is generated for the double-precision floating-point.
       all float values fit exactly into a double */
    double dval = fval;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
    /*
      void* x = pval;
      void* lvalue = int* rvalue;
      No type cast is required to convert a regular pointer (of any other type)
      into a void* in C.
      The void* is a generic untyped pointer that can store any pointer type,
      any memory address.

      byte_ptr start = (byte_ptr) &x;
      byte_ptr lvalue = byte_ptr rvalue.
      However, when converting a non-void* to a non-void* of a different type
      you have to explicitly type cast.
      The type of pointer matters not when holding the address, but when
      dereferencing and accessing the object/variable.
      void* cannot dereference the memory address which it contains, so it
      doesn't care, but pointers of other types do!
    */
    show_short(sval);
    show_double(dval);
}


int main(void)
{
  test_show_bytes(12345);
  printf("=============================\n");

  int num1 = 12345;
  printf("%i\n", num1);
  show_bytes((byte_ptr) &num1, sizeof(num1));
  printf("\n");

  float fum1 = num1;  /* implicit conversion int to float */
  printf("%f\n", fum1);
  show_bytes((byte_ptr) &fum1, sizeof(fum1));
  printf("\n");

  short sum1 = 12345;
  printf("%hi\n", sum1);
  show_bytes((byte_ptr) &sum1, sizeof(sum1));
  printf("\n");

  int* ptr1 = &num1;
  printf("%p\n", ptr1);
  show_bytes((byte_ptr) &ptr1, sizeof(ptr1));
  printf("\n");

  int a = 2607352;
  printf("%d\n", a);
  show_bytes((byte_ptr) &a, sizeof(a));
  printf("\n");

  int b = 0x4a1f23e0;
  printf("int b:\n");
  printf("%#x\n", b);
  printf("%d\n", b);
  /*
  printf("%f\n", *(float*) &b);
  */
  show_bytes((byte_ptr) &b, sizeof(b));

  printf("float f_b = *(float*) &b;\n");
  printf("float f_b\n");
  float f_b = *(float*) &b;
  printf("%f\n", f_b);
  printf("\n");

  show_bytes("12345", 6);
  printf("\n");

  printf("=============================\n\n");
  // CS:APP p. 0x68

  short x = 12345;
  short mx = -x;

  show_bytes((byte_ptr) &x, sizeof(short));
  show_bytes((byte_ptr) &mx, sizeof(short));

  return EXIT_SUCCESS;
}

