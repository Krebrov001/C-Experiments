/*
 * https://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/
 */

#include <iostream>
using namespace std;

class Test {
 public:
  Test()
  {
    cout << "Constructor is called." << endl;
  }

  ~Test()
  {
    cout << "Destructor is called." << endl;
  }
};

int main()
{
  Test();  // Explicit call to constructor creates automatic/temporary object
  Test t;  // local regular object

  t.~Test();  // Explicit call to destructor

  /* t is destroyed here */
  return 0;
}
