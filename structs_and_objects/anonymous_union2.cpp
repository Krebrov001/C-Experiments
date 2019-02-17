#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    // Example from CS7N: tricky structs.
    // You can also declare arrays inside of anonymous unions.
    // Endiannes is an issue here.
    union {
        char a[12];
	int b[2];
    };

    b[0] = 1819043144;
    b[1] = 1867980911;
    b[2] = 6581362;

    // Get ready for a surprize!
    cout << a << endl;

    return EXIT_SUCCESS;
}
