/**
 * This program displays that the command-line arguments and environment variables
 * live directly above in memory relative to the function call stack.
 * The command-line arguments and environment variables are toward higher memory addresses.
 */
#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    char name[] = "Konstantin";
    
    // Enable the first line to print data on the stack, and command-line arguments and environment variables.
    // Enable the second line to print the .rodata strings section in the memory.

    char* cp = name;
    //char* cp = "Konstantin";

    char* c2 = "hohoho";

    /* The pointer starts attached to the 'K' char, which lives in the memory for the main() function's
     * stack frame. If we increment it, it will creep into the command-line arguments and environment
     * variables section of the memory, and start printing them until it reaches the kernel portion
     * of the memory and segfaults due to inadequate permissions.
     */
    while (true) {
        cout << *cp++;
    }

    return EXIT_SUCCESS;
}
