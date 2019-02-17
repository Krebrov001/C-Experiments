/**
 * @file    initializer_list5_1.cpp
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
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  int _x;  // data members of a class are private by default.

  public:
    Base(int _x) : _x(_x) {}

    void print();
};

void Base::print()
{
    cout << "_x: " << _x << endl;
}


int main()
{
    Base b0(10);
    b0.print();

    Base b1(12);
    b1.print();

    return 0;
}
