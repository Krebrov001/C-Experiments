/*
 * Here there is a non-static default member initializer.
 * Every single time when a Test object is created,
 * it's int count data member will be initialized with the return value of the function.
 * So we call the function to get the return value.
 * Only then after that's done the body of the constructor executes.
 * All the data members of the class must be initialized before body of the constructor executes.
 * Output of this program is:
 * _______________
 * | $ ./a.out
 * |Inside foo()
 * |3
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
    Test() {
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
