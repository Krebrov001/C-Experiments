#include <iostream>
using namespace std;

int main() {
    char* buffer = new char[5];
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = 'c';

    buffer + 0;  /* &'a' */
    buffer + 1;  /* &'b' */
    buffer + 2;  /* &'c' */

    return 0;
}
