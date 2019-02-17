/*
 * Name     : environ-demo.c
 * Author   : Konstantin Rebrov
 * Date     : 05/30/2018
 * Language : C
 *
 * Description:
 * Command-line arguments for a C/C++ program are stored sequentially as '\0' terminated
 * "char arrays" in the kernel section of the program's memory.
 * Environment variables are also stored sequentially as '\0' terminated "char arrays"
 * directly after the command-line arguments in the memory.
 * There is also an array of char *'s in the memory, where each char pointer points to
 * the next string representing the next command-line argument or environment variable.
 */
#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS

int main (int argc, char* argv[])
{
  //----------------------------------------------------------------------------------
  // Note:
  //
  // argv is an array of pointers to character strings.
  // In other words, argv points to the base of an array of char *'s pointing to each
  // of the command-line arguments string literals.
  //
  // environ points to the base of an array of char *'s pointing to each of the
  // environment variables string literals.
  //
  // In the kernel section of the program's memory, first we have the array of char *'s
  // to each of the command-line arguments, then there is a NULL pointer
  // delimiting the end of the argv array.
  // Then right after that we have the array of char *'s to each of the environment variables,
  // then there is a NULL pointer delimiting the end of the environ array.
  //
  // A NULL pointer marks the "end" of the array of char pointers.
  //
  // environ is actually an offset from argv!
  // environ == (argv + (argc + 1))
  // We are offsetting argv by the number of command-line arguments, plus the NULL pointer
  // delimiting the "end" of argv. The following memory locations belong to environ.
  //
  // It is worth noting that the individual char making up the string literals for
  // the command-line arguments and environment variables also come one right after
  // another in memory.
  //----------------------------------------------------------------------------------

  extern char** environ;

  if (environ == (argv + (argc + 1))) {
    printf( "The char *'s to the environment variables\n"
            "directly follow the char *'s to the command-line arguments in memory!\n");
  }

  printf("\n");

  printf("The name of this program is '%s'.\n", argv[0]);
  printf("This program was invoked with %d arguments.\n", argc - 1);

  printf("\n");

  // var initially points to the base of the array of char pointers.
  // Then it gets incremented, moving to the next char*, and prints the next
  // string literal stored at the memory location *var,
  // until the loop ends.
  char** var = argv;

  // There are two arrays of char *'s laid out one after the other in memory:
  // argv, and environ.
  // When we reach the end of an array of char *'s,
  // we increment arrays_seen.
  int arrays_seen = 0;

  // While we haven't reached the end of the array of char *'s
  // to the environment variables.
  while (arrays_seen != 2) {
    printf("  %s\n", *var);  // Print the string literal that the char* points to.
    var++;  // move on to the next char pointer

    // If var has reached the end of the "array" of char *'s
    if (*var == NULL) {
      arrays_seen++;  // Increase the number of arrays seen by 1.
      var++;          // Move var over the NULL pointer.
    }
  }

  printf("\n");
  printf("\n");
  printf("Hit ENTER to continue.\n");

  getchar();

  // Reset var back to the base of the array of char *'s;
  var = argv;

  char curr_char;

  // This code takes advantage of the fact that the C-strings for all the command-line
  // arguments and environment variables are all laid out sequentially in memory,
  // being '\0' terminated.
  //
  // *var returns a char pointer to somewhere inside the strings.
  // *(*var) returns the char at that position.
  // (*var)++ makes the char pointer point to the next char in the C-strings array
  // holding the command-line arguments and environment variables.
  //
  // This code prints out all the chars for the command-line arguments and environment variables
  // until it runs past the region of memory holding the command-line arguments and environment variables
  // into another region in memory which it is not allowed to access, so a segmentation fault occurs.
  while (1) {
    curr_char = *(*var);
    if (curr_char != '\0') {
      putchar(curr_char);
    } else {
      putchar('\n');
    }
    (*var)++;
  }

  return EXIT_SUCCESS;
}
