/*
 * Here we have a non-static default member initializer.
 * Each object of the Test class will have the int count data member initially set to 5.
 * This is a feature of C++11 only.
 * It will be used as a member initializer if none is present in the constructor,
 * but in the class the sequence of members for initialization is determined.
 * The value of count printed in the constructor is 5.
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
    int count = 5;
};


int main()
{
    Test test1;

    return 0;
}
