/**
 * @file call_function_before_main.cpp
 * @author Konstantin Rebrov
 * @version  08/16/2018
 *
 * This program demonstrates how to call a function before main() in C++.
 *
 * The "main" idea of this program, the underlying principle,
 * is that global and static variables are initialized before the
 * main() function is called.
 *
 * If the initialization of these variables entails calling functions,
 * then those functions will be necessarily called before main().
 *
 * How To Call Some Function Before main In C++?
 * https://www.youtube.com/watch?v=UVS-rxx7XtM&index=21&list=PLk6CEY9XxSIDy8qVHZV-Nf-r9f2BkRZ6p
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int moo() {
    cout << "Inside moo()" << endl;
    return 3;
}

int foo() {
    cout << "Inside foo()" << endl;
    return 3;
}


// class Bar {...} is a data type
// class Bar {...} bar; declares an object of the Bar class.
// This code calls the constructor, which is a function!
class Bar {
  public:
    Bar() {
        cout << "Inside Bar::Bar()" << endl;
    }
    static int Ra;
} bar;

// To initialize the global_variable, I need to call the function foo()
int global_variable = foo();

// Ra is a static variable belonging to the Bar class.
// To initialize the static variable, I need to call the function moo()
int Bar::Ra = moo();

// Generates the following pseudo-assembly code:
// mov 5, a
// mov 10, b
// mov a, c
// add b, c
int a = 5;
int b = 10;
int c = a + b;

int main() {
    cout << "Inside main()" << endl;
    return 0;
}
