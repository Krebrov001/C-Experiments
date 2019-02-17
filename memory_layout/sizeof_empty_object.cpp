#include <iostream>
using namespace std;


struct Emptystruct {
    // empty struct
};


class Emptyclass {
    // empty class
};


class Nausea {
  public:
    static int count;  // static variable only
};

int Nausea::count = 0;


union Emptyunion {
    // empty union
};


int main()
{
    Emptystruct obj0;
    Emptyclass  obj1;
    Nausea      obj2;
    Emptyunion  objU;

    // The size of an object of empty struct or class is 1.
    // The size of a static int variable is 4, just like a regular int.

    cout << sizeof(obj0) << endl;
    cout << sizeof(obj1) << endl;
    cout << sizeof(obj2) << endl;
    // The correct way to quality a static member variable of a class type.
    cout << sizeof(Nausea::count) << endl;
    // "Overloaded syntax" provided by the compiler, even though the static
    // variable count itself is not a part of any single object.
    cout << sizeof(obj2.count) << endl;

    cout << sizeof(objU) << endl;

    return 0;
}
