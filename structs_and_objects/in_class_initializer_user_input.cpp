/**
 * This program demonstrates how to use an in-class default member initializer
 * if you want the user to provide their own initial values (with error checking).
 * Initialize the data members to the return value of a private helper function of the class.
 *
 * This is an alternative to doing user input/error checking outside of the class,
 * and then passing the initial values to the class via the overloaded constructor.
 * It seems messier and less well structured to me.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Test {
  public:
    // You can use the synthesized default constructor.

    int getInt() {
        return num1;
    }

    float getFloat() {
        return num2;
    }
  private:
    /**
     * Allows the user to input a value and also does error checking.
     */
    int getValue_int();

    float getValue_float();

    int   num1 = getValue_int();
    float num2 = getValue_float();
};


int Test::getValue_int() {
    int input;
    do {
        cout << "Enter a number [0...9] inclusive: ";
	cin  >> input;
    } while (!(input >= 0 && input <= 9));
    
    return input;
}


float Test::getValue_float() {
    float input;
    do {
        cout << "Enter a number [0.0 ... 9.0] inclusive: ";
	cin  >> input;
    } while (!(input >= 0.0 && input <= 9.0));
    
    return input;
}


int main()
{
    Test test1;

    cout << "int: "   << test1.getInt() << endl;
    cout << "float: " << test1.getFloat() << endl;

    return 0;
}
