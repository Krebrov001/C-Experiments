/*
 * Here, the constructor initializer has a higher precedence than the default member initializer.
 * Here, if the default member initializer has some side effects associated with the expression,
 * the default member initializer will simply be ignored and the side effects will not execute.
 * The value of count will be 10 and the value of global will still be 4.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int global = 4;

class Test {
  public:
    Test() : count(10) {
        cout << count << endl;
    }

  private:
    int count = global++;
};


int main()
{
    Test test1;

    cout << global << endl;

    return 0;
}
