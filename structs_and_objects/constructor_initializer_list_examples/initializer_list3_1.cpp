/**
 * @file    initializer_list3_1.cpp
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
 * 4. So now the constructor member initialization list executes.
 *    Now we need to initialize the private data member One a object in the
 *    Two class. So One a is initialized with the local formal parameter One b.
 *    This entails calling the copy constructor of the One class.
 *    So this means that the One b object is copied into the One a data member.
 * 5. Now the member initializer list is done executing, so we enter the body of
 *    the Two parametrized constructor and the message is printed.
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
    // The parametrized constructor.
    One(int x) : _x(x) {
      cout << "One class parametrized constructor called with: " << x << endl;
    }

    // The copy constrcuctor is invoked when a an object is copied into another one.
    One(const One& obj) {
      this->_x = obj._x;
      cout << "One class copy constructor called with: " << obj._x << endl;
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
    Two(One b) : a(b) {
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
