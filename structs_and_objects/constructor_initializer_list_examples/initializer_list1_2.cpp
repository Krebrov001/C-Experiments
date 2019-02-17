/**
 * @file    initializer_list1_2.cpp
 * @author  Konstantin Rebrov
 * @version 08/19/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates the second (incorrect) way to use the
 * an assignment operator inside the body of the constructor instead of
 * a constructor data member initializer list.
 *
 * The class Base has a const int _x data member.
 * Because it is a const, it cannot be changed after its initializetion.
 *
 * The data member variable is default-initialized, which means that the garbage
 * value remains. Then when the assignment operator executes, there is an error,
 * because the variable is a const, and you can't change its value!
 *
 * This code will not compile!
 * The compiler complains because of two reasons:
 * 1. The data member const int x is uninitialized.
 *    It should be initialized.
 * 2. Assignment of a const (read-only) data member.
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Base {
  public:
    // Default constructor : attempts to assign 0 to _x.
    Base() {
        _x = 0;
    }

    // Parametrized constructor : attempts to assign the value of the paramter to _x.
    Base(int x) {
        _x = x;
    }

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
