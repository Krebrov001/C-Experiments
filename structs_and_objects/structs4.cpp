/**
 * This program demonstrates Different Alignment Conventions.
 * The difference in alignment conventions between Windows or x86-64 and
 * IA32 Linux.
 * Use -m32 to compile Linux IA32.
 */
#include <cstddef>  // includes offsetof(type, memeber);
#include <iostream>
using namespace std;

// Macro to print out a variable/expression and it's value.
#define PRINT(x) cout << #x" = " << x << endl;

struct Base {
    char c;
    int i[2];
    double v;
} mybase;

int main() {
    PRINT(sizeof(Base));
    PRINT(offsetof(Base, c));
    PRINT(offsetof(Base, i[0]));
    PRINT(offsetof(Base, i[1]));
    PRINT(offsetof(Base, v));

    PRINT((void*) &mybase);
    PRINT((void*) &mybase.c);
    PRINT((void*) &mybase.i[0]);
    PRINT((void*) &mybase.i[1]);
    PRINT((void*) &mybase.v);

    return 0;
}

