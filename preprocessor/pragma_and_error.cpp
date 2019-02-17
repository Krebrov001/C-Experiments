#include <cstdio>

#define PRINT_TOKEN(token) printf(#token ": %d\n", token)

int main() {
  int n = 5;

  /*
     What is the difference between #pragma message("") and #error?

     #pragma message("") follows the syntax of a macro or a function call with a string argument.
     #error needs no parentheses, curly braces, or double quotes,
     the following text is printed as it is.

     #pragma message("") remains untouched by the preprocessor
     #pragma message("") displays the string parameter during the compilation
     into assembly code stage
     It does not stop the compilation process.

     #error displays the following text both during the preprocessing stage and
     during the compilation stage.
     #error prints to stderr, but the preprocessor outputs the preprocessed code
     to stdout anyway.
     When compiling (g++ -S ...) , #error stops the compilation process and
     prints to stderr.
     The *.s assembly code file is generated anyway, but it only contains one line giving information about the file,
     and no actual assembly code instructions:
	.file	"pragma_and_error.cpp"

     both #pragma message("") and #error print to stderr

     #pragma message("") is used for general purpose notice.
     #error is used to stop compilation and indicate an error
   */

  #pragma message("Meditate your arms and legs!")
  //#error Meditate your arms and legs!

  PRINT_TOKEN(n);

  return 0;
}
