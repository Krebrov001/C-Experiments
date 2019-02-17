/*
 * Here, the constructor initializer has a higher precedence than the default member initializer.
 * Here, if the default member initializer has some side effects associated with the expression,
 * the default member initializer will simply be ignored and the side effects will not execute.
 * int count will be initialized to 10.
 * The default member initializer will not execute, and the function will not be printed.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int foo()
{
    cout << "Inside foo()" << endl;
    return 3;
}

class Test {
  public:
    Test() : count(10) {
        cout << count << endl;
    }

  private:
    int count = foo();
};


int main()
{
    Test test1;

    return 0;
}
