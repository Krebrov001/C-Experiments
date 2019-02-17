/*
 * The Ch programming language is an interpreted programming language sharing most of
 * C's syntax. In the Ch programming language, the global scope can hold code in addition
 * to simple declarations and definitions of global variables.
 * This is because Ch source files are not compiled down to the assembly level, but
 * instead they are "scripted" by the Ch language interpreter.
 * Interpreted programming languages usually can contain code just about anywhere,
 * outside of any function definitions.
 * The statement global = 9; is interpreted (by the Ch interpreter of course) to be an
 * assignment. It happily updates the value in the global variable.
 * gcc on the other hand, reads this as a data definition without a type or storage class,
 * and this is the second definition of global in the same scope, so it outputs an error.
 * According to the Ch interpreter, all code in the global scope is executed first, line by
 * line, even if that code is "geographically" below main() in the source file.
 * Then the main() function executes.
 * If any functons are called at this time, they are also executed, and when they return,
 * the program execution jumps back to the place in the code where that function was called,
 * either in main() xor outside of it in the global scope.
 * If a Ch program would be written as a C program, without any code in the global scope
 * outside the function definitions, only having simple declarations and definitions
 * of global variables there, the Ch interpreter not finding any code in the global scope,
 * would immediately begin executing the code in the main() function.
 * It would behave identically as if it were compiled and run as a real C program.
 * So it means that almost every C source file is able to be "scripted" by the Ch interpreter,
 * but not every Ch source file is able to be compiled by the C compiler.
 */

#include <stdio.h>

int global = 8;

global = 9;

printf("Before main()\n");

int main() {
    printf("global: %d\n", global);
    
    return 0;
}

printf("After main()\n");
