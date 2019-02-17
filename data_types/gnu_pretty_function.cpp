/**
 * The __PRETTY_FUNCTION__ is a GNU compiler extension which is actually
 * a C-string that evaluates to the "pretty" name of a function,
 * means including the function's return type and the types of its
 * formal parameters.
 *
 * I'm using __PRETTY_FUNCTION__ to determine the data type of the passed
 * in expression to the function, during the runtime!
 */
#include <iostream>
#include <cstdlib>
#include <cstdint>
using std::cout;
using std::endl;
using std::string;

/*
void IntAndFloatingPoint(int a, double b) {
    cout << "double function" << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << a << " " << b << endl;
}
*/

void IntAndFloatingPoint(int a, float b) {
    cout << "float function" << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << a << " " << b << endl;
}

template<typename T>
void myFunction(T stuff)
{
    /*
    This is the string class fill chars constructor.
    string string::string(size_t n, char c);
    The first argument size_t n, is the number of characters to fill.
    The second argument char c, is the char to fill the string with.
    The string class fill chars constructor returns an instance of a
    string object.
    */
    cout << string(50, '=') << endl;
    cout << __func__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << stuff << endl;
    cout << string(50, '-') << endl;
}

int main()
{
    cout << __PRETTY_FUNCTION__ << endl << endl;

    IntAndFloatingPoint(5, 3.14);
    cout << endl;

    myFunction(5);
    myFunction(5u);
    myFunction(5l);
    myFunction(0x8);
    myFunction(0x80000000);
    myFunction('a');
    myFunction("horse");

    int8_t num1 = 68;
    int16_t num2 = 69;
    int32_t num3 = 70;
    int64_t num4 = 71;
    myFunction(num1);
    myFunction(num2);
    myFunction(num3);
    myFunction(num4);

    string word1 = "horse";
    myFunction(word1);

    myFunction(true);
    myFunction(false);

    cout << endl;

    myFunction(__PRETTY_FUNCTION__);

    cout << endl;

    return EXIT_SUCCESS;
}
