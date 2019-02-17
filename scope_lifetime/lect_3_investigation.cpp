/*
 * Name             : lect_3_investigation.cpp
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 24 December 2017
 * Last Modified on : 24 December 2017
 * Description      : This educational test program is an investigation of the
 *                    topics covered in Luke Sathrum's lecture 3.
 */

#include <iostream>  // C++ input/output stream - for cout, cin, cerr, endl,
                     // boolalpha, and noboolalpha
#include <cstdint>   // C standard integer types - for int8_t
#include <cstdio>    // C standard input/output - for printf() and scanf()
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

// global variables are accessible everywhere in the program.
int tuna = 5;

void printTuna() {
  cout << "Inside the funtion." << endl;
  cout << "global tuna: " << tuna << endl;
  double tuna = 3.14;
  cout << "local tuna: " << tuna << endl;
  cout << "global tuna: " << ::tuna << endl;
  // modify the global variable
  ::tuna = 1;
  cout << "new global tuna: " << ::tuna << endl;

  return;
}

// Program starts here
int main() {
  /* The following chunk of code tests std::boolalpha output stream modifier */
  cout << "True:  " << true << endl;
  cout << "False: " << false << endl;
  // apparently, std::boolalpha persists in the output stream, until another
  // command removes it
  cout << "True:  " << boolalpha << true << endl;
  cout << "True:  " << true << endl;
  cout << "False: " << false << endl;
  cerr << "True:  " << true << endl;
  cerr << "False: " << false << endl;
  // cerr is a different output stream than cout, therefore the above command
  // which set boolalpha to cout had no effect on cerr.
  // If I want my bools to print as true/false, I have to set boolalpha for
  // every single output stream I use.
  // The following statement sets boolalpha to cerr.
  cerr << "True:  " << boolalpha << true << endl;
  cerr << "True:  " << true << endl;
  cerr << "False: " << false << endl;
  // bool expressions in C/C++ are not limited to simple bool literals
  cerr << "4 < 5: " << (4 < 5) << endl;
  cout << endl;
  cout << "True:  " << true << endl;
  // use std::noboolalpha to unset boolalpha for a particular output stream,
  // in this case cout.
  cout << noboolalpha;
  cout << "True:  " << true << endl;
  cerr << "True:  " << true << endl;
  cerr << "False: " << false << endl;
  // the last statement unsets boolalpha for cerr.
  cerr << "True:  " << noboolalpha << true << endl;

  cout << endl;

  // This code tests the enumeration and switch statement.
  int8_t number;
  cout << "Enter your grade [1-100]: ";
  scanf("%hhd", &number);
  printf("You entered: %hhd\n", number);
  printf("%hhd / 10 = %hhd\n", number, (number / 10));

  //enum Grades {GRADE_A = 9, GRADE_B = 8, GRADE_C = 7, GRADE_D = 6};
  enum Grades {GRADE_D = 6, GRADE_C, GRADE_B, GRADE_A};

  // This integer division allows us to "throw away" the ones digit and reduce
  // a 95 to a 9 for example. How many times does 10 go into the number?
  // Then we can deal with the 80s, 90s, etc as single constants.
  // The integer division allows us to then compare the result of the
  // expression to one of the int constants defined in the enumeration.
  // The controlling expression has to evaluate to a literal of the given type.
  switch (number / 10) {
    case GRADE_A:
    // catches the 100, as well as extra credit up to 109
    case 10:
      cout << "A";
      break;
    case GRADE_B:
      cout << "B";
      break;
    case GRADE_C:
      cout << "C";
      break;
    case GRADE_D:
      cout << "D";
      break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
      cout << "F";
      break;
    default:
      cout << "Unrecognized input";
  }
  cout << endl;

  cout << endl;

  // This code tests block scope.
  /* A block is just a bunch of statements surrounded by braces {}.
     The braces limit the scope of variables declared inside the block
     to that block only.
     Nested scope: any variable declared outside the block, in a level above
     that block, is accessible inside the block as well, but the scope
     of variables internal to the block is constrained between the { }.
  */
  int num1 = 5;
  cout << "num1 = " << num1 << endl;
  cout << "Begin block of statements." << endl;
  {
    cout << "  num1 = " << num1 << endl;
    num1++;
    cout << "  num1 = " << num1 << endl;
    int num2 = 8;
    cout << "  num2 = " << num2 << endl;
    num1 = num2;
    cout << "  num1 = " << num1 << endl;
    num2 = 10;
    cout << "  num2 = " << num2 << endl;
  }  // scope of num2 ends here
  cout << "End block of statements." << endl;
  // This statement is invalid because the scope of num2 was constrained
  // to the block of statements above.
  //num1 = num2;
  cout << "num1 = " << num1 << endl;

  cout << endl;

  // This code tests the scope of local block variables with the same name
  // as main() variables.
  /* int num1 is a main() variable. When the program execution enters the block,
     it prints the main() num1, because there is no other num1 in that nested
     scope. Then an int num1 local to that block of statements is defined.
     Whenever you have nested scopes in your program, the program/compiler
     prefers the local version of the variable, because it is fresher!
     The variable local to the nested scope of the block of statements is given
     precedence. So after the int num1 is defined local to that block of
     statements, that specific local variable is used in every expression
     inside that block of statements. When the block ends, the scope for the
     local num1 also ends, and the print statement after the end of the block
     prints the value of the main() variable.
  */
  cout << "Begin second block of statements." << endl;
  {
    cout << "  num1 = " << num1 << endl;
    int num1 = 500;
    cout << "  num1 = " << num1 << endl;
  }  // scope of local int num1 ends here
  cout << "End second block of statements." << endl;
  cout << "num1 = " << num1 << endl;

  cout << endl;

  // This code tests the scope of global/local variables in C/C++
  /* First the global variable tuna is printed out.
     then a local variable tuna is created, and it takes over the scope for tuna
     because it is fresher!
     We access the global variable tuna using ::tuna
  */
  cout << "global tuna: " << tuna << endl;
  int tuna = 15;
  cout << "local tuna: " << tuna << endl;
  cout << "global tuna: " << ::tuna << endl;
  printTuna();
  cout << "Back in main()" << endl;
  cout << "local tuna: " << tuna << endl;
  cout << "global tuna: " << ::tuna << endl;
  /* the main() variable int tuna is accessible via the tuna identifier until
     a new variable inside the local block scope is declared that overwrites
     the tuna identifier. When float tuna is defined, using the tuna identifier
     inside the block from now on returns the float value 500.1
     As far as the program is concerned, ::tuna is a separate variable from tuna
     and refers to the global varialbe. So there are no conflicts.
  */
  cout << "Begin third block of statements." << endl;
  {
    cout << "  local tuna: " << tuna << endl;
    cout << "  global tuna: " << ::tuna << endl;
    // before the declaration of the block float tuna,
    // create a reference to the main() tuna to use it.
    int& main_tuna = tuna;
    float tuna = 500.1;
    cout << "  local block tuna: " << tuna << endl;
    cout << "  global tuna: " << ::tuna << endl;
    cout << "  main() tuna: " << main_tuna << endl;
  }  // scope of local block float tuna ends here
     // scope of the reference variable int& main_tuna also ends here
  cout << "End third block of statements." << endl;
  cout << "local tuna: " << tuna << endl;
  cout << "global tuna: " << ::tuna << endl;

  cout << endl;

  int num3 = 100;
  cout << "main variable num3: " << num3 << endl;
  cout << "Begin fourth block of statements." << endl;
  {
    cout << "  main variable num3: " << num3 << endl;
    char num3 = 'A';
    cout << "  local block variable num3: " << num3 << endl;
    // This statement won't work because the global variable ::num3
    // had not been declared.
    //cout << "  global variable num3: " << ::num3 << endl;
  }  // scope of local block variable char num3 ends here
  cout << "End fourth block of statements." << endl;
  cout << "num3: " << num3 << endl;

  cout << endl;

  // This code tests if a statement inside an if statement without the braces
  // is part of the main() function or part of the block.
  if (true)
    int new_number = 18;
  // This code won't work. The new_number is not part of the scope of main()
  // Apparently, any statement inside an if statement, even if there are no {}
  // belongs to the scope of the if statement and the if statement only
  // int new_number expires as soon as the if statement ends.
  //cout << "The new number is: " << new_number << endl;

  cout << endl;
  
  // What about loops?
  for (int i = 0; i < 10; i++)
    cout << "loop" << endl;
  // error: i was not declared in this scope
  // i goes out of scope as soon as the loop ends
  //cout << "i: " << i << endl;

  // We can print out j because j was declared in main()
  // and is used in the loop only occasionally.
  // However, i was declared IN the for loop construct,
  // therefore its scope is limited to the for loop.
  int j;
  for (j = 0; j < 10; j++)
    cout << "Loop" << endl;
  cout << "j: " << j << endl;  // j is a main() variable

  cout << endl;

  // but what about do-while loops?
  /* The statement inside the do-while loop is guaranteed to execute
     at least once. Even so, the statement inside the body of the loop
     belongs to the scope of the loop itself, and is not accessible in main()
     outside the loop.
  */
  do
    int inner_num = 16;
  while (false);
  // error: inner_num was not declared in this scope
  //cout << "inner_num: " << inner_num << endl;

  do
    cout << "do-while print statement" << endl;
  while (false);

  cout << endl;

  /* this chunk of code demonstrates that using the continue statement in a
     while loop causes infinite iteration. The continue statement skips over
     the update expression, in effect repeating the same iteration of the loop.
  */
  cout << "while loop: ";
  num1 = 5;
  while (num1 > 0) {
    cout << num1 << " ";
    //if (num1 == 2)
    //  continue;
    num1--;
  }
  cout << endl;

  /* Here, the continue statement does not cause an infinite loop.
     a continue statement in a for loop jumps to the update expression
     in the top right, then goes to the boolean expression in the middle
     and evaluates it to determine if the for loop is to execute a second time.
  */
  cout << "for loop: ";
  for (num1 = 5; num1 > 0; num1--) {
    cout << num1 << " ";
    if (num1 == 2)
      continue;
    cout << '_';
  }
  cout << endl;

  /* A continue statement in a do-while loop causes the program execution to
     stop and jump to the boolean expression inside the while () at the bottom.
  */
  cout << "do-while loop: ";
  num1 = 5;
  do {
    cout << num1 << ' ';
    num1--;
    if (num1 == 0)
      continue;
  } while (num1 > 0);
  cout << endl;

  return 0;
}
