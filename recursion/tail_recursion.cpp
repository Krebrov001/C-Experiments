// Use gcc or g++ -O2 to enable tail recursion optimization.
// Try it in GDB.
// to compile:
// g++ -g -O2 tail_recursion.cpp 
//
// g++ places the recursion "loop counter" variables int i into the register $rax.
//
// Without this optimization, g++ would create a runtime stack growing toward the lower memory addresses.
// Each int i local to it's own stack frame would have it's own different memory address,
// and these memory addresses would be progressively lower numbers.

#include <cstdlib>   // for EXIT_SUCCESS
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;


// This function demonstrates tail recursion.
// The recursive function call is in the tail of the function.
// All calculations are done above.
// The compiler can discard the data in the current stack frame, so we are taking up only O(1) stack space
// for all the recursive function calls!
void fact1(int i, int& result, const int& n)
{
    if (!(i <= n)) {
        return;
    } else {
        result = result * i;
	fact1(i + 1, result, n);
    }
}


// A little bit more idiomatic and easier to read factorial function,
// but without tail recursion. :(
// The recursive function call is not the last thing done in the function.
// The returned value is being mutiplied by i.
// This i belongs to the current stack frame.
// We are accessing the data of the current stack frame after the recursion, after we return,
// So the compiler cannot clear away the current stack frame.
// It has to keep it, which results in O(n) space on the stack.
int fact2(int i, int n)
{
    if (!(i <= n)) {
        return 1;
    } else {
        return i * fact2(i + 1, n);
    }
}


int main()
{
    int n = 0;
    cout << "Enter an int value\n > " << flush;
    cin  >> n;

    int result = 1;
    fact1(2, result, n);
    cout << n << "! = " << result << endl;

    cout << n << "! = " << fact2(2, n) << endl;

    return EXIT_SUCCESS;
}

