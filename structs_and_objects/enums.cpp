#include <iostream>
using std::cout;
using std::endl;

// In C++, a f() declaration is a prototype for a function that takes no arguments.
//
// In C however, a f() declaration means that the function takes an arbitrary amount of arguments.
// A function prototype specifies the arguments/parameters that the function takes.
// Since a f() declaration in C does not specify the arguments/parameters for the function,
// It is not a prototype!
//
// To make a prototype for a function in C, that takes no arguments, use:  f(void);
// C++ also accepts this syntax, for backwards compatibility with C,
// however, to make a prototype for a function in C++, that takes no arguments,
// this is sufficient:  f();
extern void enums_function();
// function declarations are extern by default.

int main() {
  enum Registers {RAX, RBX, RCX, RDX, R1 = 8, R2, R3, R4};

  /*
  for Registers operator++(Registers &regs, int dummy)
  {
    return r = (r == RDX) ? R1 : Registers(r + 1);
  }
  */

  // Printing out the rvalues of the Register enumerated type.
  cout << RAX << RDX << R1 << R4 << endl;

  cout << (R1 + RCX) << endl;

  // int lvalue = Registers rvalue;
  // The rvalue of the Registers enumerated type is implicitly converted into a rvalue of type int:
  // int lvalue = int rvalue;
  int number = RDX;
  cout << number << endl;

  // const int& lvalue = Registers rvalue;
  // Once again, the Registers rvalue is implicitly converted into an int rvalue:
  // const int& lvalue = int rvalue;
  // Then that int rvalue is placed into an "anonymous" lvalue or memory location,
  // And the const lvalue reference is assigned to refer to that "anonymous" lvalue:
  // const int& lvalue = int lvalue;
  const int& register_value = RBX;
  cout << register_value << endl;

  cout << endl;

  int a = 1;
  // Comparing values of a traditional enum to ints
  // if (int lvalue == Registers rvalue)
  // The value at a is placed into a register in the computer, generating an int rvalue,
  // and the rvalue of the enumerated type is converted to an rvalue of type int
  // if (int rvalue == int rvalue)
  if (a == RBX) {
    cout << true << endl;
  }

  // Declaring a variable of an enum type.
  Registers ebx = RBX;
  cout << "ebx: " << ebx << endl;

  // The value at a is placed into a register in the computer, generating an int rvalue,
  // and the value at ebx is placed into a register in the computer, generating an rvalue of the enumerated type
  // then the rvalue of the enumerated type is implicitly converted into an int rvalue.
  if (a == ebx) {
    cout << true << endl;
  }

  // what does this error mean?
  // Although the constants in an enumeration type are given as int values
  // and can be used as integers in many contexts, remember that an enumeration
  // type is a separate type and treat it as a type different from type int.
  // Here we are attempting to assign an rvalue of type int
  // into a lvalue of type Registers.
  // main()::Registers means that the enumerated type Registers is defined in the main() function
  //ebx = 24;  // error: invalid conversion from ‘int’ to ‘main()::Registers’


  // This statement will work because R1 (which is 8) is an rvalue of an enumerated type.
  ebx = R1;
  cout << "ebx: " << ebx << endl;

  // This statement will work becaue we are typecasting the rvalue of type int, 24,
  // into an rvalue of type Registers, which is an enumerated type.
  // Both sides of the = assignment operator have the same type.
  // Registers lvalue = Registers rvalue;
  ebx = static_cast<Registers>(24);
  cout << "ebx: " << ebx << endl;

  // Same as above, only using C-style typecasts.
  ebx = (Registers) 81;
  cout << "ebx: " << ebx << endl;

  cout << endl;

  // The constants in an enumeration type can be assigned char rvalues.
  // These char rvalues are converted into int rvalues, and then assigned to the constants in an enumeration type.
  enum Cyrillic_Letters { AZ = 'A', BUKI = 'B', VEDI = 'V' };
  cout << "AZ: " << AZ << endl;

  Cyrillic_Letters letter = VEDI;
  cout << letter << endl;

  cout << "An int takes up " << sizeof(int) << " bytes." << endl;
  cout << "A value of an enumeration type takes up " << sizeof(AZ) << " bytes." << endl;
  cout << "A value of an enumeration type takes up " << sizeof(letter) << " bytes." << endl;

  cout << endl;

  /* error: redeclaration of ‘RAX’
     note: previous declaration ‘main()::Registers RAX’
  */
  //enum RegSet { EAX, EBX, RAX, RBX };
  // traditional enum rvalues do not allow you to have the same enum rvalue twice within the same scope.
  // The above statement fails because RAX, and RBX, were already declared as enum rvalues of
  // the enumeration type main()::Registers.
  // When you have the name RAX in a statement, does it represent RAX (0) as part of main()::Registers
  // or does it represent RAX (2) as part of main()::RegSet?
  // That is an ambiguity, the compiler can't tell the difference.

  enums_function();

  // C++11 added a new version of enumerations called strong enums, or enum classes.
  // Unlike traditional enums, strong enums, or enum classes, allow you to declare enum rvalues multiple times.
  // You just have to qualify them to state which enum rvalue
  // from which strong enum class do you want to use.
  enum class Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
  enum class Weather { Rain, Sun };
  // You can qualify an enum value by providing the enum name followed by two colons followed by the value.
  // You must do this to say which enum class does the enum rvalue belong to.
  // As seen above, Sun is an rvalue of two different enums.
  // We have to qualify it to prevent ambiguity:
  // Days::Sun  Weather::Sun
  Days d = Days::Sun;
  Days e = Days::Tue;
  Weather w = Weather::Sun;

  // This statement works because traditional enum rvalues can be implicitly convered to integers.
  /* int */ a = R4;
  cout << a << endl;

  // error: cannot convert ‘main()::Days’ to ‘int’ in assignment
  // rvalues of a strong enum, or enum class, cannot be implicitly converted to integers.
  //a = Days::Sat;
  //cout << a << endl;

  // However, rvalues of a strong enum, or enum class, can be explicitly convered to integers,
  // via typecasting.
  a = static_cast<int>(Days::Sat);
  cout << a << endl;

  /* when comparing lvalues and rvalues of a strong enum type,
     both sides of the == operator should have the same strong enum type */

  // error: no match for ‘operator==’ (operand types are ‘main()::Days’ and ‘int’)
  // Do not compare a lvalue of a strong enum type to an int rvalue.
  // main()::Days lvalue == int rvalue
  /*
  if (d == 0) {
    cout << "d == 0" << endl;
  }
  */

  // Compare a lvalue of a strong enum type to an rvalue of THAT SAME strong enum type.
  // main()::Days lvalue == main()::Days rvalue
  if (d == Days::Sun) {
    cout << "d == Days::Sun" << endl;
  }

  // error: no match for ‘operator==’ (operand types are ‘main()::Days’ and ‘main()::Weather’)
  // You CANNOT however, compare a lvalue of a strong enum type to an rvalue of a DIFFERENT strong enum type.
  // Only compare lvalues and rvalues of the same strong enum type.
  // main()::Days lvalue == main()::Weather rvalue
  /*
  if (d == Weather::Rain) {
    cout << "d == Weather::Rain" << endl;
  }
  */

  return 0;
}


void enums_function() {
  cout << endl;

  // The main()::Registers enumerated type is restricted in scope to main(),
  // as the statement suggests.
  // This enumerated type RegSet is local to the enums_function(),
  // hence it does not conflict with the main()::Registers enum.
  // This is worth noting because both RAX and RBX are declated in both these enumerated types.
  enum RegSet { EAX, EBX, RAX, RBX };
  RegSet r = RAX;
  cout << r << endl;

  cout << endl;
}
