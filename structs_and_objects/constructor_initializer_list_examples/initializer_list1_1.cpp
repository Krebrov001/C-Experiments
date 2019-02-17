/**
 * @file    initializer_list1_1.cpp
 * @author  Konstantin Rebrov
 * @version 08/19/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates the first (correct) way to use the
 * constructor data member initializer list.
 *
 * The class Base has a const int _x data member.
 * Because it is a const, it cannot be changed after its initializetion.
 *
 * The constructor data member initializer list initializes the data
 * member, or constructs it with an initial value.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  public:
    // Default constructor : sets _x to the default value 0.
    Base() : _x(0) {}

    // Parametrized constructor : sets _x to the value of the paramter.
    Base(int x) : _x(x) {}

    // Prints the value of the internal data member.
    void print_x()
    {
        cout << "_x: " << _x << endl << endl;
    }
  private:
    // A const variable cannot be changed!
    const int _x;
};


int main()
{
    // Create a base object using the default constructor.
    Base b0;
    b0.print_x();

    // Create a base object using the parametrized constructor.
    Base b1(10);
    b1.print_x();

    return 0;
}
