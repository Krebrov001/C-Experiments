/*
 * https://www.youtube.com/watch?v=rI88W3yu8Qw
 */

#include <stdio.h>
#include <stdlib.h>

/* complex is a special keyword for dealing with complex numbers
   introduced in C99.
   To prevent a possible name collision, I am using complexNumber instead
   of complex as a typedef for my struct type.
 */
/* the name after the struct is optional */
/* struct { ... } is a data type. */
/* typedef data_type complexNumber; */
typedef struct {
  int real_part;
  int imaginary_part;
} complexNumber;

/* This function accepts two objects of the complexNumber struct type by value
   and returns an object of the complexNumber struct type by value.
 */
complexNumber addComplexNumber1(complexNumber c1, complexNumber c2)
{
  complexNumber temp;
  temp.real_part = c1.real_part + c2.real_part;
  temp.imaginary_part = c1.imaginary_part + c2.imaginary_part;
  return temp;
}

/* This function accepts two pointers to objects of the complexNumber struct type (pass by pointer).
   The pointers are const to prevent inadvertent modification of the passed in struct objects.
   This function also returns an object of the complexNumber struct type by value.
 */
complexNumber addComplexNumber2(const complexNumber* c1, const complexNumber* c2)
{
  complexNumber temp;
  temp.real_part = (*c1).real_part + (*c2).real_part;
  temp.imaginary_part = c1->imaginary_part + c2->imaginary_part;
  return temp;
}

/* This function accepts two pointers to objects of the complexNumber struct type (pass by pointer).
   The pointers are const to prevent inadvertent modification of the passed in struct objects.
   This function returns a pointer to an object of a complexNumber struct type.
   It is worth noting that the local variable temp of the complexNumber struct type expires after the function ends, and the function's stack frame
   is cleared off the stack.
 */
complexNumber* addComplexNumber3(const complexNumber* c1, const complexNumber* c2)
{
  complexNumber temp;
  temp.real_part = (*c1).real_part + (*c2).real_part;
  temp.imaginary_part = c1->imaginary_part + c2->imaginary_part;
  return &temp;
}

int main(void) {
  complexNumber c1 = {1, 5},
                c2 = {2, 6};

  /* This statement declares/defines 2 objects of the complexNumber
     struct type and a pointer to an object of the complexNumber
     struct type.
   */
  complexNumber result1, result2, *result3;

  /* addComplexNumber1() and addComplexNumber2() both return
     an object of the complexNumber struct type */
  /* complexNumber lvalue = complexNumber rvalue */
  /* This performs a shallow field-by-field copy from the returned rvalue
     to the destination lvalue */
  result1 = addComplexNumber1(c1, c2);
  result2 = addComplexNumber2(&c1, &c2);

  /* addComplexNumber3() returns a pointer to an object of the complexNumber
     struct type. */
  result3 = addComplexNumber3(&c1, &c2);

  /* As soon as I try to access the fields of the complexNumber object,
     which is local to the addComplexNumber3() function,
     via the -> operator, I get a Segmentation Fault,
     because the program is trying to access a memory location which
     it no longer has access to.
   */
  /*
  result1.real_part = result3->real_part;
  result1.imaginary_part = result3->imaginary_part;

  printf("Hello World\n");

  printf("addComplexNumber1: %d + %di\n", result1.real_part, result1.imaginary_part);
  printf("addComplexNumber2: %d + %di\n", result2.real_part, result2.imaginary_part);
  printf("addComplexNumber3: %d + %di\n", result3->real_part, result3->imaginary_part);
  */

  /* The function call addComplexNumber1(c1, c2) returns an rvalue object
     of the complexNumber struct type. */
  printf("sum of complex number is %d + %di\n",     \
         addComplexNumber1(c1, c2).real_part,       \
         addComplexNumber1(c1, c2).imaginary_part);
  /* without the \ at the end of lines */
  printf("sum of complex number is %d + %di\n",
         addComplexNumber2(&c1, &c2).real_part,
         addComplexNumber2(&c1, &c2).imaginary_part);
  /* The dereference attempts to access a memory location
     that has already been cleared off the stack,
     so I get a Segmentation Fault. */
  /*
  printf("sum of complex number is %d + %di\n",
         addComplexNumber3(&c1, &c2)->real_part,
         addComplexNumber3(&c1, &c2)->imaginary_part);
    */

  return EXIT_SUCCESS;
}
