#include <iostream>
using std::cout;
using std::endl;

// Declares a new global variable.
int myglobal = 3;

/*
 * What does this function do?
 * This function returns an int& - a reference to an int variable
 * When myglobal is returned by foo(),
 * it is not the value (rvalue) of myglobal that is returned,
 * but rather a reference to it is returned,
 * which is an lvalue!
 */
int& foo() {
  return myglobal;
}

int main() {

  // The data type on the left is an int& - a reference to an int variable
  // The data type on the right is also an int&, because that's what foo() returns.
  //
  // Hmm... what happens when we do this?
  //   int i = 5;  The data types on both sides of the = assignment operator are the same.
  //
  // foo() returns a reference to myglobal, which is an lvalue
  // a reference variable requires an lvalue on the right side of the = assignment operator
  //

  int& reference_variable = foo();

  //
  // We can think of the above statement as:
  // int& reference_variable = myglobal;  // myglobal is returned by foo()
  // reference_variable now refers to myglobal
  // reference_variable is now another name for myglobal

  // This should print a 3 out.
  cout << reference_variable << endl;

  cout << "Address of myglobal:           " << &myglobal << endl;
  cout << "Address of reference_variable: " << &reference_variable << endl;

  // The data type on the left side is an int& lvalue
  // The data type on the right side is an int rvalue
  // int& = int;
  // The rvalue 5 is placed into the lvalue refferred to by reference_variable.
  reference_variable = 5;

  // reference_variable is another name for myglobal
  // Since reference_variable refers to myglobal,
  // the above assignment changed the value stored at that location in memory.
  cout << myglobal << endl;

  // What does this statement do?
  // foo() returns an int&
  // foo() returns a reference to myglobal, which is an lvalue
  //
  // The data type on the left side is an int& lvalue
  // The data type on the right side is an int rvalue
  // int& = int;
  // The rvalue 50 is placed into the memory location of the returned lvalue,
  // which is a reference to myglobal.
  //

  foo() = 50;

  //
  // This is basically the same as:
  // myglobal = 50;

  // the foo() returned a reference (another name) to myglobal
  // the statement above modified myglobal
  cout << myglobal << endl;

  cout << endl;
  // foo() returns a reference to myglobal
  // reference_variable is a reference to myglobal
  // These two statements work the same.
  //

  cout << reference_variable << endl;
  cout << foo() << endl;

  //
  // cout << int& << endl;
  // An int& is an lvalue.
  // That lvalue is implicitly converted into an rvalue, and
  // then printed out to the screen.
  cout << endl;


  /* Use cases of reference variables (lvalue references) */

  // Case 1:
  // int& lvalue = int lvalue;
  // The int& lvalue is set as another name for the int lvalue
  // Example:
  //   int i;
  //   int& reference variable = i;

  // Case 2:
  // int& lvalue = int& lvalue;
  // the int& lvalue on the left side of the = assignment operator
  // is set as another name for the memory location which is referred to by the
  // int& on the right side of the = assignment operator.

  // Case 3:
  // int& lvalue = int rvalue;
  // The int rvalue is stored into the memory location referred to by the
  // int& on the left side of the = assignment operator.

  // int& lvalue = int lvalue;
  //int& reference_variable = myglobal;

  // int& lvalue = int& lvalue;
  int& another_reference = reference_variable;

  // int& lvalue = int rvalue;
  another_reference = 100;

  cout << "myglobal:           " << myglobal << endl;
  cout << "reference_variable: " << reference_variable << endl;
  cout << "another_reference:  " << another_reference  << endl;
  cout << "foo():              " << foo() << endl;

  cout << "Address of myglobal:           " << &myglobal << endl;
  cout << "Address of reference_variable: " << &reference_variable << endl;
  cout << "Address of another_reference:  " << &another_reference  << endl;
  cout << "Address of foo():              " << &( foo() ) << endl;

  // The most interesting thing is that int& foo() { return myglobal; }
  // foo() returns an "anonymous" reference to myglobal,
  // or a "temporary" another name for that memory location.

  return 0;
}
