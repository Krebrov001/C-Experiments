/*
 * When the Test object is created, the default constructor is called,
 * which prints the value of the int count data member.
 * Here, int count is declared, but not defined. It is uninitialized.
 * When we define a variable without an initializer, the variable is default initialized.
 * Variables of a class type are initialized by the default constructor, if it exists.
 * Variables of a built-in data type declared inside a function are uninitialized.
 * The value of an uninitialized variable of a built-in type is undefined.
 * Some garbage value will be printed.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Test {
  public:
    Test() {
        cout << count << endl;
    }

  private:
    int count;
};


int main()
{
    Test test1;

    return 0;
}
