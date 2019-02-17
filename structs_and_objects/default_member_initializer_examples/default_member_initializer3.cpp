/*
 * Here we have both a non-static default member initializer and a constructor initializer.
 * The constructor initializer has a higher priority than the default member initializer.
 * The default member initializer is used as a fallback option only if there is no
 * constructor initializer for that data member.
 * A constructor initializer, directly specified, has precedence.
 * Here, if the default member initializer has some side effects associated with the expression,
 * the default member initializer will simply be ignored and the side effects will not execute.
 * 10 is printed to stdout.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Test {
  public:
    Test() : count(10) {
        cout << count << endl;
    }

  private:
    int count = 5;
};


int main()
{
    Test test1;

    return 0;
}
