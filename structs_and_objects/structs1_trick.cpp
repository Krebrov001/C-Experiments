#include <cstddef>  // includes offsetof(type, memeber);
#include <iostream>
using namespace std;

struct Base {
    char a;
    char b;
    int i;
    char c;
} mybase;

int main() {
    (&mybase.i)[-1] = 1819043144;
    (&mybase.i)[0]  = 1867980911;
    (&mybase.i)[1]  = 6581362;

    // Get ready for a surprise!
    cout << &mybase.a << endl;

    return 0;
}

