/**
 * @file     constructor_init_list_syntax_differences.cpp
 * @author   Konstantin Rebrov
 * @version  09/03/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates a(x) vs a{x} inside of the constuction initializer
 * list. a{x} is the extended, or uniform constructor initializer list.
 * It got introduced in C++11.
 * A narrowing conversion is when a rvalue of a larger data type is
 * assigned into a lvalue of a smaller data type,
 * possibly resulting in loss of information.
 * a(x) will allow you to do a narrowing conversion, while a{x} will not.
 */
#include <iostream>
using std::cout;
using std::endl;


class Base {
  public:
    Base(int x) : _x(x) {}

    void print() {
      cout << static_cast<int>(_x) << endl;
    }
  private:
    char _x;
};


class Base2 {
  public:
    Base2(int x) : _x{x} {}

    void print() {
      cout << static_cast<int>(_x) << endl;
    }
  private:
    char _x;
};


int main()
{
    Base b1(300);
    b1.print();

    cout << endl;

    Base2 b2(300);
    b2.print();

    return 0;
}
