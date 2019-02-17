/**
 * @file     synthesized_default_constructor.cpp
 * @author   Konstantin Rebrov
 * @version  08/19/2018
 *
 * @section DESCRIPTION
 *
 * This program tests the features of the synthesized default constructor.
 *
 * For most classes, the synthesized default constructor works like this:
 *    - If there is an in-class initializer, use it to initialize the member.
 *    - Otherwise, default-initialize the member
 *      (POD types are left uninitialized, garbage value)
 *      If a data member or object itself is of a class type, then default-initializing
 *      it entails calling the default constructor.
 *
 * Classes that have data members of POD types should rely on the synthesized default
 * constructor ONLY if all such members have in-class initializers.
 *
 * The compiler generates the default constructor automatically only if we do not declare
 * any constructors. If we declare any constructors, the class will not have a default
 * constructor unless we define the default constructor ourselves.
 * A definition is also an implicit declaration.
 *
 * See CS4N p 46
 */
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


/**
 * The Test class has only one data member, int k.
 * There is an in-class default member initializer for int k.
 * The in-class default member initializer initializes the variable,
 * and executes before the body of the constructor.
 * That is why we can print the initialized value of the variable
 * in the constructor.
 *
 * The Test::Test() constructor is used to demonstrate that if a data member (or object)
 * itself is of a class type, then default-initializing it entails calling its default constructor.
 *
 * The Test::getTest() member function is used to return the value of the internal data member
 * to the outside world, in this case the Dog object.
 */
class Test {
  public:
    Test() {
      cout << "The Test constructor was called with a default value int k = " << k << endl;
    }

    int getTest() {
      return k;
    }

  private:
    int k = 1;  // In-class default member initializer.
};


/**
 * This class demonstrates features of the synthesized default constructor.
 *
 * If there is an in-class default member initializer, it is used to initialize
 * that data member, as int num2.
 *
 * Otherwise, the data members are default-initialized.
 * A data member of a POD type is left uninitialized (garbage value).
 * A data member of a class type is default-initialized by calling its default constructor.
 *
 * Data members are initialized in the order that they appear in the class.
 *
 * First, the Test::Test() constructor is called as part of the step of setting the initial
 * values for the Dog object. And we see the message printed to the screen as a
 * confirmation that the code indeed behaves this way.
 *
 * Then the int num1 is default-initialized to some garbage value.
 *
 * Then the int num2 gets its initial default value via the in-class default member initializer.
 */
class Dog {
  public:
    // There is a synthesized default constructor.

    /**
     * This function is used to determine if the synthesized default constructor for the Dog class
     * indeed did what I think it did.
     * All the values of the internal data members are printed out.
     *
     * Because Test::k is a private data member of the Test class,
     * Dog class cannot access it directly.
     * However, it can use the Test::getTest() public member function.
     *
     * Test test1 object is a private data member of the Dog class.
     * The outside world doesn't know about it.
     * Dog class can access test1's public member functions, but the outside world
     * has to go through the Dog class first.
     * That is why I am using the Dog::printDog() public member function to print
     * the value of Test test1.
     */
    void printDog() {
        cout << "Test::k = " << test1.getTest() << endl;
	cout << "num1    = " << num1 << endl;
	cout << "num2    = " << num2 << endl;
    }

  private:
    Test test1;
    int num1;
    int num2 = 2;  // In-class default member initializer.
};


int main()
{
    // Create a Dog object
    // (This class the Test::Test() constructor too!)
    Dog d1;

    // Print a horizontal line to signify that we're done initializing the Dog object.
    cout << string(20, '-') << endl;

    // Display the values of the member variables of the Dog class.
    d1.printDog();

    return 0;
}

