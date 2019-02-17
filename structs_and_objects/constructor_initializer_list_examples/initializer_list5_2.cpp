/**
 * @file    initializer_list5_2.cpp
 * @author  Konstantin Rebrov
 * @version 09/02/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates the fifth reason why you should use constructor
 * initializer lists.
 * When you have a data member of a class with the same name as the parameter
 * to the constructor.
 * You want to initialize the data member with the parameter.
 *
 * If you don't use the constructor initializer list, the assignment will not work.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  int _x;  // data members of a class are private by default.

  public:
    Base(int _x) {
      // Instead of assigning the local parameter to the data member,
      // this statement assigns the local parameter to itself.
      // The local parameter hides the scope of the _x data member.
      _x = _x;
      cout << "local _x: " << _x << endl;
    }

    void print();
};

void Base::print()
{
    cout << "_x: " << _x << endl;
}


int main()
{
    Base b0(10);

    // Uninitialized variable
    // Prints a garbage value.
    b0.print();

    return 0;
}
