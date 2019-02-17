#include <iostream>
using namespace std;

union myUnion {
    double a;

    class box {
        int height;
	int weight;
      public:
        box (int h = 0, int w = 0) : height(h), weight(h) {}
    } b;
};


/* This code does not compile because the union myUnion { ... }
   contains a POD double a, and a class box { ... } b;
   This class box { ... } b has a constructor.
   Anything that has a constructor, destructor, virtual function, or is not a "plain data" (POD), cannot be put into
   union. box { ... } b; has a constructor. Similarly, for the same reason you cannot put std::string into a union.
   std::string has constructor and destructor.
   In C++, unions may not contain classes with non-trivial (means not created by compiler) constructors or destructors.
   This is because the compiler has no means of telling which constructor or destructor to use when a union instance
   is created or destroyed.
   - From C++ Pocket Reference, p. 87:
   The members of unions cannot be objects that define constructors or destructors,
   or that overload the assignment operator.
   In short, the members of unions are only allowed to be PODs!
 */


int main()
{
    myUnion stuff;

    return 0;
}
