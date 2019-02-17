/**
 * @file    initializer_list5_3.cpp
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
 * However, you can use this->_x to get it to work.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  int _x;  // data members of a class are private by default.

  public:
    Base(int _x) {
      // The local parameter hides the scope of the _x data member,
      // but this->_x refers to the data member.
      this->_x = _x;
    }

    void print();
};

void Base::print()
{
    // _x is implied to be this->_x in the member functions unless
    // a local variable hides its scope.
    cout << "_x: " << _x << endl;
}


int main()
{
    Base b0(10);

    // Hey, this->_x worked!
    b0.print();

    return 0;
}
