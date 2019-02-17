#include <cstddef>  // includes offsetof(type, memeber);
#include <iostream>
using namespace std;

// Macro to print out a variable/expression and it's value.
#define PRINT(x) cout << #x" = " << x << endl;

#pragma pack(1)  // disables padding

struct Base {
    char a;
    char b;
    char c;
    int i;
} mybase;

int main() {
    PRINT(sizeof(Base));
    PRINT(offsetof(Base, a));
    PRINT(offsetof(Base, b));
    PRINT(offsetof(Base, i));
    PRINT(offsetof(Base, c));

    PRINT((void*) &mybase);
    PRINT((void*) &mybase.a);
    PRINT((void*) &mybase.b);
    PRINT((void*) &mybase.i);
    PRINT((void*) &mybase.c);

    return 0;
}

