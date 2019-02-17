#include <iostream>
using namespace std;

// This function does not work because you're not passing the array to it,
// you're passing a pointer to the first element of the array.
// When an array is passed to a function, during array decaying,
// all information about the size of the array is lost.
// This is why it is impossible to do a range-based modern C++11 for-loop on it.
// You have the array's base address, but you don't know how far the array extends in memory.
// Once you start looping, you don't know where to stop.
//void printArray1(int* bar)
/*
void printArray1(int bar[])
{
    for (int i : bar) {
        cout << i << endl;
    }
}
*/


// This way of printint the array will work.
// In this case, we do not have array decaying going on here.
// We are passing an array "object" by reference, a reference to an array.
// We can use the array just like a vector<>& or int&!
// In doing to we need to specify the full type of the array.
// First of all we need to surround the &bar with (): (&bar)
// If we do not do so, we would get int& bar[3], an array of three ints passed by reference!
// Then we also have to provide the size of the array explicitly because int[3] and int[4] are different different
// data types!
void printArray2(int (&bar)[3])
//void printArray2(int &bar[3])
{
    for (int i : bar) {
        cout << i << endl;
    }
}


// The following syntax is equivalent to:
// void infoArray(int* x)
// The number in the [] is just "documentation" for the number of elements that you're
// "supposed" to pass in. You can omit it if you wish. You can even specify a smaller size.
// You can even specify a size of 0. Only you can't specify a negative size.
//void infoArray(int x[100])
void infoArray(int x[0])
{
    cout << "array[0] = " << x[0] << endl;
    cout << "array[1] = " << x[1] << endl;
}


// We can pass in an array of any size using template non-type parameters.
// Instead of having typename and the name of a data type,
// we have a data type, and a variable.
template <size_t array_size>
void printArray3(int (&bar)[array_size])
{
    for (int i : bar) {
        cout << i << endl;
    }
}


int main()
{
    int bar[3] = {1, 2, 3};
    for (int i : bar) {
        cout << i << endl;
    }

    //printArray1(bar);
    //printArray2(bar);
    infoArray(bar);
    printArray3(bar);
    
    cout << endl;

    int foo[5] = {1, 3, 4, 9, 5};
    printArray3(foo);

    return 0;
}

