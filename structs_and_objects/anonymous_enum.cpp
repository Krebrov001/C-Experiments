#include <iostream>
using namespace std;

int main()
{
    /* An anonymous enum:
       There is no tag.
     */
    enum { INT, FLOAT } DATA_TYPE;

    DATA_TYPE = INT;

    /* A named enum:
       The only advantage is that I can use the tag to define variables of that enum type again later in the code.
     */
    enum color { WHITE, BLUE, RED, GOLD, BLACK } colorA;

    colorA = RED;

    color colorB = BLUE;

    // The enumerated values declared inside the enum { ... } are always cessible through the global scope.
    // This is not like in a union, struct, or class, where you have to scope-quality the data members.
    // Names declared inside an enum { ... } are not data members.
    // They are enumerated values, shorthand for integers.
    // If you would have to scope-quality them every single time, the code would get very ugly really quickly.
    // Because these are enumerated values, not data members,
    // you don't need an object in order to access them.
    //
    // And additionally the compiler will not even allow you to scope-quality enumerated variables:
    // anonymous_enum.cpp: In function ‘int main()’:
    // anonymous_enum.cpp:18:20: error: ‘color’ is not a class or namespace
    //      color colorB = color::BLUE;
    // 	                     ^
    // Yes, color is neither a class nor a namespace.
    // color is just the tag, the "name", of the enumerated type!
    // You only have to scope-quality names declared inside classes or namespaces.


    return 0;
}
