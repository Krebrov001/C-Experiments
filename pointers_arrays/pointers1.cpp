/*
 * Name        : pointers1.cpp
 * Author      : Konstantin Rebrov
 * Date        : 08/11/2017
 * Language    : C++
 * Description : This program explores using pointers in C++
 * Sources     : https://www.youtube.com/watch?v=JTttg85xsbo
 *               https://www.youtube.com/watch?v=d3kd5KbGB48
 */

#include <iostream>  // C++ input/output - for overloaded <<, cout, endl
#include <cstdio>    // C standard input/output - for printf(), scanf()
using std::cout;
using std::endl;
using std::string;

int main() {
  cout << "An int takes up " << sizeof(int) << " bytes." << endl;
  cout << "A char takes up " << sizeof(char) << " bytes." << endl;
  cout << "A short takes up " << sizeof(short) << " bytes." << endl;
  cout << "A float takes up " << sizeof(float) << " bytes." << endl;
  cout << "A double takes up " << sizeof(double) << " bytes." << endl;
  cout << endl;

  int num = 251988228;
  int* p;
  p = &num;
  printf("Address: %p  Value: %d\n", p, *p);
  printf("Address: %p  Value: %d\n", p+1, *(p+1));
  printf("\n");
  char* pc;
  pc = (char*) p;
  printf("Address: %p  Value: %d\n", pc, *pc);
  printf("Address: %p  Value: %d\n", pc+1, *(pc+1));
  printf("Address: %p  Value: %d\n", pc+2, *(pc+2));
  printf("Address: %p  Value: %d\n", pc+3, *(pc+3));
  printf("\n");
  short* ps = (short*) p;
  printf("Address: %p  Value: %d\n", ps, *ps);
  printf("Address: %p  Value: %d\n", ps+1, *(ps+1));
  printf("\n");

  float val = 1.8441174e-34;
  printf("Floating point value: %e\n", val);
  float* flt_ptr = &val;
  printf("Address: %p  Value: %e\n", flt_ptr, *flt_ptr);
  printf("Address: %p  Value: %e (garbage value)\n", flt_ptr+1, *(flt_ptr+1));
  printf("\n");
  pc = (char*) flt_ptr;
  printf("Address: %p  Value: %d\n", pc, *pc);
  printf("Address: %p  Value: %d\n", pc+1, *(pc+1));
  printf("Address: %p  Value: %d\n", pc+2, *(pc+2));
  printf("Address: %p  Value: %d\n", pc+3, *(pc+3));
  printf("\n");
  ps = (short*) flt_ptr;
  printf("Address: %p  Value: %d\n", ps, *ps);
  printf("Address: %p  Value: %d\n", ps+1, *(ps+1));
  printf("\n");

  // string constructor in action
  cout << string(50, '=') << endl;
  int x = 5;
  cout << "x: " << x << endl;
  cout << "Address of x: " << &x << endl;

  int* pointer_p;
  cout << "Address of pointer_p: " << &pointer_p << endl;
  cout << "Uninitialized pointer: " << pointer_p << endl;

  pointer_p = &x;
  cout << "Address of x in pointer_p: " << pointer_p << endl;
  cout << "Dereference pointer_p: " << *pointer_p << endl;
  *pointer_p = 6;
  cout << "Dereference pointer_p: " << *pointer_p << endl;
  cout << "x: " << x << endl << endl;;

  int** pointer_q = &pointer_p;
  cout << "Double pointer_q: " << pointer_q << endl;
  cout << "Dereference double pointer_q: " << *pointer_q << endl;
  cout << "Dereference double pointer_q twice: " << *(*pointer_q) << endl;
  cout << endl;

  cout << "The address of the double pointer_q itself: " << &pointer_q << endl;
  int*** pointer_r = &pointer_q;
  cout << "The value stored in triple pointer_r: " << pointer_r << endl;
  cout << "Dereference triple pointer_r once: " << *pointer_r << endl;
  cout << "Dereference triple pointer_r twice: " << *(*pointer_r) << endl;
  cout << "Dereference triple pointer_r 3 times: " << *(*(*pointer_r)) << endl;
  // for the sake of operator precedence, it's better to write the statement:
  // *(*(*pointer_r)) = 10;  // code looks cleaner too, no ambiguity.
  ***pointer_r = 10;
  cout << "Value of x through triple pointer_r: " << *(*(*pointer_r)) << endl;
  cout << "Value of x is: " << x << endl << endl;

  // x is now 10;
  *(*(*pointer_r)) = *(*pointer_q) + (*pointer_p)/2;
  // x = x + x/2;
  // x = 10 + 10/2;
  // x = 10 + 5;
  // x = 15;
  cout << "New value of x: " << x << endl << endl;

  // pointer_p is a single-level pointer and
  // pointer_r is a triple-level pointer
  // pointer_p is an int* and pointer_r is an int***
  // int* and int*** are different data types, therefore the following
  // statement is not valid;
  // pointer_r = pointer_p;
  /* If we want to assign pointer_p to pointer_r, we need to typecast */
  pointer_r = (int***) pointer_p;
  cout << "New value of triple pointer_r is: " << pointer_r << endl;
  cout << "x is: " << *pointer_r << endl;
  printf("x is: %d\n", *pointer_r);

  cout << "Pointer address [hex]: " << *pointer_q << endl;
  cout << "Decimal value: " << *((int*)  pointer_q) << endl;

  return 0;
}

