#include <iostream>
using std::cout;
using std::endl;

int main() {
  #define MULT1(a, b) a * b
  #define MULT2(a, b) (a) * (b)

  int x = MULT1(3 + 2, 4 + 2);
  int z = MULT2(3 + 2, 4 + 2);

  cout << "x: " << x << "\nz: " << z << endl;

  #define ADD_FIVE1(a) (a) + 5
  #define ADD_FIVE2(a) ((a) + 5)

  x = ADD_FIVE1(3) * 2;
  z = ADD_FIVE2(3) * 2;

  // We use a trick involving exclusive-or to swap two variables
  #define SWAP(a, b) a ^= b; b ^= a; a ^= b;

  x = 10;
  int y = 5;

  // works OK
  SWAP(x, y);

  cout << "\nx: " << x << "\ny: " << y << endl;

  // What happens now?
  if (x < 0)
    SWAP(x, y);  // only the first statement, a ^= b; is part of the if ()
                 // the other two statements execute no matter what

  cout << "\nx: " << x << "\ny: " << y << endl;

  #define SWAP2(a, b) { a ^= b; b ^= a; a ^= b; }

  x = 10;
  y = 5;
  z = 4;

  #define SWAP3(a, b) do { a ^= b; b ^= a; a ^= b; } while ( 0 )

  /*
  // What happens now?
  if (x < 0)
    SWAP2(x, y);
  else
    SWAP2(x, z);
  */

  // What happens now?
  if (x < 0)
    SWAP3(x, y);
  else
    SWAP3(x, z);

  cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << endl;

  //SWAP3(x, 2 + 5);

  #define MAX(a, b) (((a) < (b)) ? (b) : (a))

  x = 5;
  y = 10;
  z = MAX(x++, y++);

  cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << endl;

  // I can use the \ to do a multi-line macro.
  #define SWAP(a, b) {          \
                       a ^= b;  \
		       b ^= a;  \
		       a ^= b;  \
		     }

  /*
     The preprocessor complains:
     warning: "SWAP" redefined
     #undef SWAP  solves this
   */

  if (x == 5)
    SWAP(x, y);

  #define PRINT_FIELD(field) animal.##field

  cout << PRINT_FIELD(height) << endl;
  // cout << animal.height << endl;

  #define SORT(algorithm, array, size) algorithm##_sort(##array##, \
                                                        ##size##)

  int list[5];
  int even_numbers[12];

  SORT(merge, list, 5);
  SORT(insertion, even_numbers, 12);

  #define MACRO(x) (x) + 2
  cout << MACRO(5) << endl;

  // Although the preprocessor outputs a warning, you CAN INDEED redefine preprocessor macros.

  #define MACRO(x) (1##x * 8)
  cout << MACRO(5) << endl;

  /* You can redefine macros to be anything */
  /* redifining a macro is the same as defining a new macro with the
     same name. The meaning of the new macro will "overwrite" the meaning
     of the old macro */
  /* The old macro was a simple constant, while the new macro is a
     function-like construct! */

  #define FOO 8
  cout << FOO << endl;

  #define FOO(x) (x * x * x)  // x^3
  cout << FOO(2) << endl;

  /*
      String-izing Tokens
      using #token inside a macro definition will create a new string
      with the literal name, or text, of the token, and insert it into
      the #token position in the source code.

      NOTE: In C, two or more adjacent string literals are concatenated
      into a single large string literal.
      if (int token == 5), the following macro produces:
      printf("token" " is %d", token)
      "token is 5"

      String-izing Tokens can be used to print out both
      the expression itself and the resulting value to which it evaluates.
   */

  #define PRINT_TOKEN(token) printf(#token " is %d", token)

  int my_number = 8;
  PRINT_TOKEN(my_number);
  PRINT_TOKEN((my_number * 9) + 8);

  return 0;
}
