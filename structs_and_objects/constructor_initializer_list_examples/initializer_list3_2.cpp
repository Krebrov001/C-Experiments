/**
 * @file    initializer_list3_2.cpp
 * @author  Konstantin Rebrov
 * @version 09/02/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates the third reason why you should use constructor
 * initializer lists.
 *
 * If you have a class that is a data member of another class, and it does not have
 * a default constructor, the only way you can initialize that object is by calling
 * it's parametrized constructor through the constructor initialization list.
 *
 * However, if that class which is the data member, does have a default constructor,
 * then we can just default-construct it, and then do the assignment to it in
 * the Two constructor.
 *
 * These numbers describe what happens at each line of the output.
 *
 * 1. First the One one object is created using the parametrized constructor.
 * 2. Then the string separator is printed.
 * Then, what are the steps we need to do to create the Two two object?
 * 3. First, the parametrized constructor of the Two class is called,
 *    and one object is passed in as an actual argument.
 *    Then the formal parameter One b in the Two class constructor is initialized
 *    with the actual argument One one object from the main() function.
 *    This entails calling the copy constructor of the One class.
 *    And now the parameter One b inside the Two class constructor is created.
 * 6. Because there is neither an in-class initializer for the data member
 *    One a, nor a constructor member initializer list for it,
 *    One a is default-initialized, which entails calling the default constructor.
 * if and only if (the overloaded assignment operator is defined)
 * {
 * 8. If a class doesn't have an assignment operator explicity declared,
 *    the compiler will create one for you. The synthesized default assignment
 *    operator basically does a field-by field copy. If that doesn't satisfy you,
 *    of you also want the assignment operator to print a message to the screen,
 *    you have to define the overloaded assignment operator yourself, and this time
 *    you have to code all the operations that are to be performed during assignment.
 * }
 * 7. After the assignment operator executes, the message inside the (replaced)
 *    constructor is printed.
 * 
 */
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;


class One {
  public:
    One() {
      _x = 0;
      cout << "One class default constructor called with 0" << endl;
    }

    // The parametrized constructor.
    One(int x) : _x(x) {
      cout << "One class parametrized constructor called with: " << x << endl;
    }

    // The copy constrcuctor is invoked when a an object is copied into another one.
    One(const One& obj) {
      this->_x = obj._x;
      cout << "One class copy constructor called with: " << obj._x << endl;
    }

    One& operator =(const One& obj) {
      cout << "One class assignment operator called with " << obj._x << endl;
      this->_x = obj._x;
    }

    // This is needed so that class Two can access the inner data member of One.
    // _x is private in One, so Two (the outside world) has to get this data
    // using a getter function.
    int get_x() {
      return _x;
    }
  private:
    int _x;
};


class Two {
  public:
    Two(One b) {
      a = b;
      cout << "Two class parametrized constructor called with: " << a.get_x() << endl;
    }
  private:
    One a;
};


int main()
{
    One one(10);

    cout << string(30, '-') << endl;

    Two two(one);

    return 0;
}
