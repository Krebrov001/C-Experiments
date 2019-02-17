#include <iostream>  // C++ streams library
#include <cstdlib>   // C standard library - for atoi(), exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <cmath>     // C math library     - for M_PI, M_E
using std::cout;
using std::cerr;
using std::endl;


/**
 * This function uses the XOR swap to swap two variables
 * passed by pointers.
 * In other words, the local int* variables x and y point to the real variables
 * somewhere else in the memory of the calling function.
 * The pointers themselves do not get swapped or unrooted, they get dereferenced and the values
 * inside the variables to which the pointers are pointing to get swapped.
 *
 * This function has a weak point.
 * If both of the pointers are pointing to the same variable,
 * then the combination value will necessarily be 0.
 * However, there is no other variable from which to retrieve the original value.
 *
 * @param int* x, int* y - two variables passed by pointers to be swapped, or rather
 *                         two pointers pointing to variables to be swapped.
 *   The function does not check if the pointers are not pointing to the same memory location.
 */
void XORswapValuesByPointers(int* x, int* y)
{
  cout << "XOR swap" << endl;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *x = *x ^ *y;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *y = *x ^ *y;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *x = *x ^ *y;
  cout << "*x: " << *x << " *y: " << *y << endl;

  return;
}


/**
 * This function uses the Arithmetic swap to swap two variables
 * passed by pointers.
 * In other words, the local int* variables x and y point to the real variables
 * somewhere else in the memory of the calling function.
 * The pointers themselves do not get swapped or unrooted, they get dereferenced and the values
 * inside the variables to which the pointers are pointing to get swapped.
 *
 * This function has a weak point.
 * If both of the pointers are pointing to the same variable,
 * then the combination value will necessarily be the sum of the two values,
 * or rather double the rvalue inside the variable to which both pointers are pointing to,
 * because it will be that vlaue plus itself.
 * Then when we attempt to subtract one of the values out of the combination,
 * we end up subtracting the combination value from itself, which is now stored
 * in the single variable that both pointers are pointing to.
 * The result in subtracting the value from itself and resaving the result back into
 * the same variable is 0.
 *
 * @param int* x, int* y - two variables passed by pointers to be swapped, or rather
 *                         two pointers pointing to variables to be swapped.
 *   The function does not check if the pointers are not pointing to the same memory location.
 */
void arithmeticSwapValuesByPointers(int* x, int* y)
{
  cout << "Arithmetic swap" << endl;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *x = *x + *y;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *y = *x - *y;
  cout << "*x: " << *x << " *y: " << *y << endl;
  *x = *x - *y;
  cout << "*x: " << *x << " *y: " << *y << endl;

  return;
}


int main(int argc, char* argv[])
{
  int a = 0, b = 0;

  // If the correct number of command-line arguments is not given, the program ends here.
  if (argc != 3) {
    cerr << "Usage: x and y must be int values" << endl;
    cerr << argv[0] << " x y" << endl;

    exit(EXIT_FAILURE);
  }

  // a is assigned the first command-line argument
  // b is assigned the second command-line argument
  a = atoi(argv[1]);
  b = atoi(argv[2]);

  /* Do the XOR swap on a and b. */
  /* It is worth noting that unlike Arithmetic swap, XOR swap does not risk a problem of
     overflowing if the "combined value" (sum) is beyond the valid range of an int. This is
     because the operations are performed BITWISE (bit-by-bit), with no addition or carry out */
  
  cout << "XOR swap" << endl;

  cout << "a: " << a << " b: " << b << endl;
  a = a ^ b;
  cout << "a: " << a << " b: " << b << endl;
  b = a ^ b;
  cout << "a: " << a << " b: " << b << endl;
  a = a ^ b;
  cout << "a: " << a << " b: " << b << endl;

  cout << endl;

  // Reset the values of a and b.
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  
  /* Repeat the experiment, using Arithmetic swap this time. */

  cout << "Arithmetic swap" << endl;

  cout << "a: " << a << " b: " << b << endl;
  a = a + b;
  cout << "a: " << a << " b: " << b << endl;
  b = a - b;
  cout << "a: " << a << " b: " << b << endl;
  a = a - b;
  cout << "a: " << a << " b: " << b << endl;

  cout << endl;

  /* XOR swap by pointers does work when the pointers point to different variables. */

  XORswapValuesByPointers(&a, &b);

  cout << endl;

  /* Demonstrate that the XOR swap does not work as expected when
     the pointers point to the same variable. */

  int x = 5;
  cout << "x = " << x << endl;
  XORswapValuesByPointers(&x, &x);
  cout << "x = " << x << endl;

  cout << endl;

  /* Demonstrate that Arithmetic swap by pointers works when the pointers point
     to different variables. */

  arithmeticSwapValuesByPointers(&a, &b);

  cout << endl;

  /* However, similar to XOR swap, Arithmetic swap by pointers does not work
     when the pointers point to the same variable. */

  x = 5;
  cout << "x = " << x << endl;
  arithmeticSwapValuesByPointers(&x, &x);
  cout << "x = " << x << endl;

  cout << endl;

  /* Demonstrating that XORing a variable with itself zeroes out that variable. */

  x = 5;
  cout << "x = " << x << endl;
  x ^= x;
  cout << "zeroing out x using XOR" << endl;
  cout << "x = " << x << endl;

  cout << endl;

  /* Demonstrate how to use the XOR swap to swap two float values. */

  float pi = M_PI;
  float e  = M_E;

  cout << "pi: " << pi << "\te:  " << e  << endl;

  // Set the int pointers to point to the float variables, using this
  // tricky syntax!
  int* ptr1 = (int*) &pi;
  int* ptr2 = (int*) &e;

  // Since a float is the same size as an int,
  // the XOR swap works via dereferencing pointers!
  *ptr1 = *ptr1 ^ *ptr2;
  cout << "pi: " << pi << "\te:  " << e  << endl;
  *ptr2 = *ptr1 ^ *ptr2;
  cout << "pi: " << pi << "\te:  " << e  << endl;
  *ptr1 = *ptr1 ^ *ptr2;
  cout << "pi: " << pi << "\te:  " << e  << endl;

  cout << endl;

  return EXIT_SUCCESS;
}

