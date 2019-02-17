#include <iostream>  // C++ standard input/output stream - for cout, endl
#include <cstdio>    // C standard input/output          - for printf()
#include <cstdlib>   // C standard library               - for size_t, EXIT_SUCCESS
#include <cstdint>   // C standard integer data types    - for uint8_t


/* This union occupies 4 bytes (32 bits) in memory.
   It demonstrates different data representations for this memory:
     signed int,
     unsigned int,
     single-precision float,
   And also this union allows you to access the individual bytes themselves,
   using either array syntax or data member syntax.
     It contains either an array of 4 bytes (unsigned integers),
     or a struct with four byte-sized data members (also unsigned integers).
 */
typedef union {

  signed int i;

  unsigned int u;

  float f;

  uint8_t bytes_array[4];

  struct {
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
  } bytes_list;

} data;


int main()
{
  data number;

  // Set all the bytes individually.
  number.bytes_list.b0 = 0xcd;
  number.bytes_list.b1 = 0xcc;
  number.bytes_list.b2 = 0xcc;
  number.bytes_list.b3 = 0x3d;

  size_t i = 0;

  // Loops through all bytes in the union.
  // i goes from 0 to 1 less than the number of bytes in the union's
  // largest field.
  for (i = 0; i < sizeof(number.i); i++) {
    printf("number.bytes_array[%zu] : %#hhx\n", i, number.bytes_array[i]);
  }
  std::cout << std::endl;

  i = 0;

  // C++11 syntax:
  // a ranged for-loop. Prints out all elements in the array or vector.
  // bytes is a const lvalue reference. It is another name for the variable
  // which it refers to. That variable cannot be changed.
  // What really happens in this loop:
  // const uint8_t& byte = number.bytes_array[counter]
  // the counter "variable" is hidden, it is maintened by the compiler
  // and invisible to the programmer (probably stored inside a register).
  for (const uint8_t& byte : number.bytes_array) {
    printf("number.bytes_array[%zu] : %#hhx\n", i, byte);
    i++;
  }
  std::cout << std::endl;

  // Prints out all 4 bytes being iterpreted as different data types.
  // number.i is the class data member while i is a variable local to main()
  std::cout << number.i << std::endl;
  std::cout << number.u << std::endl;
  std::cout << number.f << std::endl;
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
