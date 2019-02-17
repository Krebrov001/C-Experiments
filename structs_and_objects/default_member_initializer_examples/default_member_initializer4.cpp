/*
 * This is a non-static default member initializer.
 * When the Test test1 object is created, int count gets the former value of global,
 * and global itself is incremented.
 * The value of count will be 4 and the value of global will be 5.
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int global = 4;

class Test {
  public:
    Test() {
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
