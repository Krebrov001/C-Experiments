/*
 * C is a compiled language.
 * According to the C programming language, the global scope can only hold
 * data declarations and definitions, not instructions.
 * You can only put code (which gets compiled down into assembly instructions)
 * inside of a function.
 * Declarations and definitions are not really code.
 * They just state that something is there, they are not instructions.
 * The program execution begins in the main() function, and goes into other
 * functions if main() calls them.
 * If you have an instruction or code outside of a function,
 * when is it going to be executed?
 * It is not going to be executed at all, therefore the pure ANSI C programming
 * language only allows you to put declarations and definitions outside of
 * any function.
 * Declarations and definitions are stated/initialized by the OS and/or
 * runtime environment before the actual program execution starts,
 * before the process itself starts running.
 * It is not the responsibility of the process to worry about global
 * declarations and definitions.
 * They are initialized when the process starts, just as the .text segment,
 * containing the code instructions for the compiled program, is initialized
 * when the process starts.
 */

#include <stdio.h>

int global = 8;

//printf("Before main()\n");

global = 9;

int main() {
  printf("global: %d\n", global);

  return 0;
}

//printf("After main()\n");
