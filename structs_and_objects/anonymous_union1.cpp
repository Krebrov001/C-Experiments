#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    // To declare an anonymous union, just don't provide a tag.
    // An anonymous union is simply a way to have two variables share the same memory space.
    // There is no object. You access the variables as if they were standalone variables, non data members.
    // These variables occupy the same location in memory, they start at the same memory address.
    // There is a similar concept in HLA also.
    union {
        int a;
	float b;
    };

    a = 25;             // Set a to 25
    cout << a << endl;  // cout 25
    cout << b << endl;  // cout Nonsense!
    cout << endl;
    b = 26.9f;          // Set b to 26.9f
    cout << a << endl;  // cout Nonsense!
    cout << b << endl;  // cout 26.9
    cout << endl;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;

    return EXIT_SUCCESS;
}
