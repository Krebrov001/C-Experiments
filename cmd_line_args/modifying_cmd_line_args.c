/*
 * Name     : modifying_cmd_line_args.c
 * Author   : Konstantin Rebrov
 * Date     : 05/30/2017
 * Language : C
 * Sources  : Advanced Linux Programming
 */

/*-----------------------------------------------------------
                 Description:
 This program demonstrates that the command-line arguments passed in ARE modifiable.

 This program should be run with at least 1 command line argument.
   ./arg a bb ccc
 
 The command-line arguments are stored sequentially as '\0' terminated "char arrays",
 or string literals, in the kernel section of the program's memory.
 For the above example:
                        ASCII code  char  address
			  46         .      0x1   *(argv[0])
			  47         /      0x2
			  97         a      0x3
			 114         r      0x4
			 103         g      0x5
			   0        \0      0x6
			  97         a      0x7   *(argv[1])
			   0        \0      0x8
			  98         b      0x9   *(argv[2])
			  98         b      0xa
			   0        \0      0xb
			  99         c      0xc   *(argv[3])
			  99         c      0xd
			  99         c      0xe
			   0        \0      0xf
-----------------------------------------------------------*/

#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS

// This macro prints the element in the array argv (a char*),
// and the string literal which it points to.
// Example:
// argv[0] : |./arg|
// 
#define PRINT_ARG(x) printf("%s: |%s|\n" #x, x);

int main (int argc, char* argv[]) {

  /*
  PRINT_ARG(argv[0])
  PRINT_ARG(argv[1])
  PRINT_ARG(argv[2])
  */

  printf("%s\n", argv[0]);
  printf("%s\n", argv[1]);
  printf("%s\n", argv[2]);
  printf("%s\n", argv[3]);

  printf("-----------------\n");

  // Overwrites the '\0' delimiting the command-line arguments
  // argv[0], argv[1], and argv[2] with 'x'
  *(argv[1]-1) = 'x';  // "Joins" argc[0] and argv[1]
  *(argv[1]+1) = 'x';  // "Joins" argv[1] and argv[2]

  /*
  PRINT_ARG(argv[0])
  PRINT_ARG(argv[1])
  PRINT_ARG(argv[2])
  */

  printf("%s\n", argv[0]);
  printf("%s\n", argv[1]);
  printf("%s\n", argv[2]);
  printf("%s\n", argv[3]);

  return EXIT_SUCCESS;
}
