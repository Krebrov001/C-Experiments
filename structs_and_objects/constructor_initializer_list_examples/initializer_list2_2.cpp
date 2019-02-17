/**
 * @file    initializer_list2_2.cpp
 * @author  Konstantin Rebrov
 * @version 09/02/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates the second point about where the constructor initializer
 * list is a must in C++:
 * When you have a reference variable as a private data member.
 *
 * This version of the program demonstrates the wrong way to do it:
 * first trying to default-initialize the variable, then assignment.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  public:
    // No default constructor here because,
    // what would be a default value for a reference variable?
    //Base() {}

    // Parametrized constructor : attempts to default-initialize the reference
    // variable, then assign a value to it.
    // Equivalent to:
    // int& _x;
    // _x = x;
    Base(int x) {
      _x = x;
    }

    // Prints the value of the internal data member.
    void print_x()
    {
        cout << "_x: " << _x << endl << endl;
    }
  private:
    // A reference variable must be initialized.
    int& _x;
};


int main()
{
    // We can't default-construct the Base object because there is no default constructor.

    // Create a base object using the parametrized constructor.
    Base b1(10);
    b1.print_x();

    return 0;
}
