/*
 * Name             : unsigned_int_loops.cpp
 * Author           : Konstantin Rebrov
 * Created on       : 27 December 2017
 * Last modified on : 27 December 2017
 * Description      : It is convenient to use an unsigned int as a loop counter
 *                    in some scenarios, such as the index of an array, vector,
 *                    or C++ string. This value cannot be negative. However,
 *                    this can also lead to problems of infinite loops.
 *                    Here I demonstrate some ways to bypass that problem and
 *                    use an unsigned int as a loop counter without generating
 *                    an infinite loop.
 * Sources          : https://stackoverflow.com/q/9044059
 */

#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
#include <climits>   // C data type limits - for UINT_MAX
using std::cout;
using std::endl;

int main() {
  // infinite loop
  /*
  for (unsigned int i = 10; i >= 0; i--)
    cout << i << endl;
  */

  // outputs [9-0] inclusive  Note: update expression is empty and the
  //                          decrement is inside the boolean expression
  for (unsigned int i = 10; i-- != 0; )
    cout << i << ' ';

  cout << endl;

  // outputs [9-1] inclusive
  for (unsigned int i = 10; --i != 0; )
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // Note: no need for any casts, -1 is equivalent to UINT_MAX in this context,
  // and -1 is better because it is type independent.
  // Also, no need to include climits
  for (unsigned int i = 10; i != -1; i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // An alternative way, using UINT_MAX instead of -1
  for (unsigned int i = 10; i != UINT_MAX; i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // This code compares i to whatever the unsigned equivalent of 0 - 1 is.
  // unsigned is really just the same as unsigned int on most compilers so
  // this code really checks to see if i goes below 0.
  for (unsigned int i = 10; i != (unsigned) 0 - 1; i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // Basically the same as the loop on top except using a C++ cast instead of a
  // C style cast. C++ casts are safer and are more easily visible/searchable
  // in code.
  for (unsigned int i = 10; i != static_cast<unsigned int>(0 - 1); i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // This code compares i to the bitwise not of unsigned 0, which is all 1s.
  // If i is signed, all 1s is -1, if i is unsigned, all 1s is the max
  // unsigned int value.
  for (unsigned int i = 10; i != ~(unsigned) 0; i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // Same as the loop above, however you don't need the unsigned int type cast
  // to compare the bitwise not of 0 to i.
  // I must point out that this loop and the preceding one work with any size
  // of the unsigned int data type. No matter what size in bytes the int
  // literal 0 takes up, all the bits get flipped to 1.
  for (unsigned int i = 10; i != ~0; i--)
    cout << i << ' ';

  cout << endl;

  // outputs [10-0] inclusive
  // Based on the same principle as the loop above, compares i to 32 1s in
  // binary or 8 fs in hexadecimal, which is equal to -1 for signed int or
  // UINT_MAX for unsigned int. However, this construct assumes that an
  // unsigned int occupies 4 bytes or 32 bits, hence the 8 fs representing the
  // individual nibbles all being full. On wierd and uncommon compilers/
  // operating systems/architectures, an unsigned int may not be 4 bytes long,
  // which could lead to some problems.
  for (unsigned int i = 10; i != 0xffffffff; i--)
    cout << i << ' ';

  cout << endl;

  return EXIT_SUCCESS;
}
