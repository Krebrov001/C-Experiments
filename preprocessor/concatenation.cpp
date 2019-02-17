#include <iostream>
#include <typeinfo>
using namespace std;

// Macro concatenation operator:
// This macro joins the two "arguments" together into one text:  ab
#define JOIN(a, b) a##b
// Macro stringizing operator:
// This macro converts both of these "arguments" into string literals,
// and puts them adjacent right next to each other:  "a""b"
// In C as well as C++, two adjacent string literals are concetenated
// into a single string literal:  "ab"
#define PRINT_NAME(a, b) #a#b

#define VARNAME(x) #x
// This macro uses typeid() to compare the types of the passed in "arguments"
#define SAMETYPE(x, y) (typeid(x).name() == typeid(y).name())

int main() {

  int myVar   = 120;
  int yourVar = 50;

  cout << "The val is " << JOIN(my, Var)   << endl;
  cout << "The val is " << JOIN(your, Var) << endl;

  int A0;
  int A1;
  int A2;
  int A3;
  int A4;

  int regNum;

  cout << "What register do you want to store the value into?" << endl;
  cin  >> regNum;

  // The preprocessor expands macro definitions before compile time,
  // and definitely before runtime.
  // This is why the only "arguments" that you can use for macro expansion
  // are the ones whose values are known DURING PREPROCESSING.
  // You cannot have the user input a value during runtime and have that
  // as an "argument" for the macro expansion.
  // Since doing marco expansion is the preprocessor's job,
  // it treats the text regNum, not the value which it evaluates to,
  // as the "argument" of the macro.

  // The following macro expansion gets preprocessed into:  AregNum
  // Since AregNum was not declared in the program, the compiler
  // outputs an error!
  //JOIN(A, regNum) = 25;

  JOIN(A, 3) = 25;  // A3 = 25;

  //cout << PRINT_NAME(A, regNum) << " == " << JOIN(A, regNum) << endl;
  cout << PRINT_NAME(A, 3) << " == " << JOIN(A, 3) << endl;

  // ##A3   The preprocessor concatenates the first empty argument with A3 to result A3
  JOIN(, A3) = 7;  // A3 = 7;

  cout << PRINT_NAME(, A3) << " == " << JOIN(, A3) << endl;

  //cout << REGISTER << endl;

  // Apparently, a macro expansion (here it's REGISTER) cannot be treated
  // as the "argument" to another macro expansion.
  // That will not work.
  // To be more specific, the JOIN() and PRINT_NAME() macros do their jobs
  // well, but REGISTER remains unexpanded by the preprocessor.
  //JOIN(A, REGISTER) = 25;

  //cout << PRINT_NAME(A, REGISTER) << " == " << JOIN(A, REGISTER) << endl;


  int j = 20;
  float y = 290;

  cout << "Are " << VARNAME(j) << " and " << VARNAME(y)
       << " the same type? " << SAMETYPE(j, y) << endl;

  return 0;
}
