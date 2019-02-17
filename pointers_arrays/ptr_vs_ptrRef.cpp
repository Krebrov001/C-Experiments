/*
 * Name             : ptr_vs_ptrRef.cpp
 * Author           : Konstantin Rebrov
 * Created on       : 08 January 2017
 * Last modified on : 08 January 2017
 * Description      : This program demonstrates pointer reference variables,
 *                    which are basically references to pointer variables,
 *                    or another name for the same pointer.
 * Sources          : https://www.youtube.com/watch?v=7HmCb343xR8
 */

#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
using std::cout;
using std::endl;

/* global variables */
int box1 = 1;
int box2 = 2;
int* gptr;

/* function prototypes */
void passByPtr(int* ptr);
void passByPtrRef(int*& ptrRef);

// This is the main method of the program.
// The program starts here at runtime.
int main() {

  int* p = &box1;
  gptr = &box2;

  cout << "\n______ Current conditions ______\n";

  //passByPtr(p);
  passByPtrRef(p);

  // check the value of pointer p
  if (p == &box1) {
    cout << "p is pointing to box1" << endl;
  } else if(p == &box2) {
    cout << "p is pointing to box2" << endl;
  } else {
    cout << "p is pointing to another box" << endl;
  }

  // check the value of pointer gptr
  if (gptr == &box1) {
    cout << "gptr is pointing to box1" << endl;
  } else if(gptr == &box2) {
    cout << "gptr is pointing to box2" << endl;
  } else {
    cout << "gptr is pointing to another box" << endl;
  }

  // check the value of the int variables
  cout << "box1 contains the value: " << box1 << endl;
  cout << "box2 contains the value: " << box2 << endl;

  return EXIT_SUCCESS;
}

/*
 * This function just changes the values of the box variables.
 * This function creates a copy of pointer p as pointer ptr,
 * but it does not change where the original pointer p in the main() function
 * points to.
 * int* ptr = p;
 * int* ptr = p = &box1;
 */
void passByPtr(int* ptr) {
  *ptr = 3;  // box1 = 3;
  /* Neither does the functon change where gptr points do. */
  ptr = gptr;  // ptr = gptr = &box2;
  *ptr = 4;  // box2 = 4;
  cout << "\n______ passByPtr has been called __\n";
}

/*
 * This function creates a pointer reference to the original pointer p in main()
 * basically it is another name for the pointer p.
 * int*& ptrRef = p;
 * int*& ptrRef = p = &box1;
 * If ptrRef is modified, then p is also modified.
 * This code changes the value of p itself, or rather where it points to.
 */
void passByPtrRef(int*& ptrRef) {
  *ptrRef = 5;  // box1 = 5;
  /*
   * assigns gptr to ptrRef, or assigns gptr to p
   * This code causes the original pointer p to point to where gptr is
   * pointing to, box2;
   */
  ptrRef = gptr;  // p = gptr = &box2;
  /* p, ptrRef are now pointing to box2 */
  *ptrRef = 6;  // box2 = 6;
  cout << "\n______ passByPtrRef has been called __\n";
  /* and p is now poiting to box2 */
}
