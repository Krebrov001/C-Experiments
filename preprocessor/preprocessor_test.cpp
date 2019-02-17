/*
 * Name        : preprocessor_test.cpp
 * Date        : 02/17/2017
 * Author      : Konstantin Rebrov
 * Description : This program tests some preprocessor directives.
 * Sources     : C++ Pocket Reference
 */

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::boolalpha;

/*
void function1() {
  cout << "funtion 1 called" << endl;
}

void function2() {
  cout << "funtion 2 called" << endl;
}

int add_five(int a);
int add_ten(int a);
*/

int main() {
  // output the values of some common preprocessor macros
  cout << "The date: " << __DATE__ << endl;
  cout << "The time: " << __TIME__ << endl;
  cout << "The date and the time: " << __TIMESTAMP__ << endl;
  cout << "The file: " << __FILE__ << endl;
  cout << "ANSI C: " << __STDC__ << endl;
  cout << "C++: " << __cplusplus << endl;

  // #pragma writes a message to stdout during compilation
  #pragma message("Hello, World!")

  // testing the #if preprocessor directive
  #if ((5 * 3) == 15)
  cout << "#if (5 * 3) == 15 test succeeded" << endl;
  #else
  cout << "An error occurred." << endl;
  #endif

  cout << "If ANSI C is true: " << boolalpha << __STDC__
  << "\nIf C++ is true: " << boolalpha << __cplusplus << endl;

  #ifdef __STDC__
  cout << "ANSI C is true." << endl;
  #else
  cout << "ANSI C is false." << endl;
  #endif

  #ifdef __cplusplus
  cout << "C++ is true." << endl;
  #else
  cout << "C++ is false." << endl;
  #endif

  // changing the __LINE__ value
  cout << "The current line: " << __LINE__ << endl;
  #line 100
  cout << "New line: " << __LINE__ << endl;
  cout << "Next line: " << __LINE__ << endl;

  // testing the #define preprocessor directive
  #define IDENTIFIER_1
  #ifdef IDENTIFIER_1
  cout << "identifier 1 defined" << endl;
  #else
  cout << "identifier 1 not defined" << endl;
  #endif
  #ifndef IDENTIFIER_1
  cout << "identifier 1 not defined" << endl;
  #else
  cout << "identifier 1 defined" << endl;
  #endif
  cout << "Undefine identifier 1" << endl;
  #undef IDENTIFIER_1
  #ifdef IDENTIFIER_1
  cout << "identifier 1 defined" << endl;
  #else
  cout << "identifier 1 not defined" << endl;
  #endif
  #ifndef IDENTIFIER_1
  cout << "identifier 1 not defined" << endl;
  #else
  cout << "identifier 1 defined" << endl;
  #endif

  // demonstrating #define substitution
  #define SPECIAL_NUMBER 3.14
  cout << "Special number is " << SPECIAL_NUMBER << endl;
  #define SPECIAL_VARIABLE pi_num
  float SPECIAL_VARIABLE = SPECIAL_NUMBER;
  cout << "Pi: " << pi_num << endl;

  #define THE_PROGRAMMER "Konstantin Rebrov"
  cout << THE_PROGRAMMER << " made the file " << __FILE__ << endl;

  // changing the __LINE__ and __FILE__ values
  #line 1 "NewName.cpp"
  cout << "New filename: " << __FILE__ << endl;
  #line 79 "preprocessor_test.cpp"
  cout << "Restore defaults: " << "line #" << __LINE__ << " filename: "
  << __FILE__ << endl;

  // testing #if comparissons
  #define NUM_ONE 1
  #define NUM_TWO 2
  #if (NUM_ONE != 1)
  cout << boolalpha << false << endl;
  #elif (NUM_ONE == 1)
  cout << boolalpha << true << endl;
  #else
  cout << "else" << endl;
  #endif
  #if ((NUM_ONE + NUM_ONE) == NUM_TWO)
  cout << "1 + 1 = " << 2 << endl;
  #else
  cout << 1 << '+' << 1 << "!= 2" << endl;
  #endif

  // cool_number needs to be #defined
  //cout << cool_number << endl;

  /*

  FUNCTION();

  int number = 1;
  int num_2 = 200;
  number = ADD(ARGUMENT);\
  cout << "number: " << number << endl;
  number = 5 OP 4;
  cout << "number: " << number << endl;

  //#define Display_message printf("Hello World!\n");
  #define Display_message cout << "Hello World" << endl;
  Display_message

  int array??(5??);
  if (true ??!??! false) ??<
    cout << "trigraphs!" << endl;
   ??>

   int number = 5 OP \
   (num2 OP 2);

   #define MIN(a, b) (((a) < (b)) ? (a) : (b))

   #define function_body { \
   int a = 5;\
   cout << a << endl;\
   return x + a;\
   }

   number = MIN(8, 7);
   number = MIN(num2, 8);
   number = MIN(4, 10);

  */

  // this ends the program
  return 0;
}


/*
int add_five(int a) {
  return a + 5;
}

int add_ten(int a) {
  return a + 10;
}

int add_a(int x) function_body
*/
