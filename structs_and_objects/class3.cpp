#include <cstddef>  // includes offsetof(type, memeber);
#include <iostream>
using namespace std;

// Macro to print out a variable/expression and it's value.
#define PRINT(x) cout << #x" = " << x << endl;

class Base {
  public:
    char a;
    int i;
} mybase;

int main() {
    PRINT(sizeof(Base));
    PRINT(offsetof(Base, a));
    PRINT(offsetof(Base, i));

    PRINT((void*) &mybase);
    PRINT((void*) &mybase.a);
    PRINT((void*) &mybase.i);

    return 0;
}

