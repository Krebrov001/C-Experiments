#include <stdio.h>

#define PRINT_INT(x) printf("%s = %d\n", #x, x);

int main()
{
    int a = 21;
    int b = 025;
    int c = 0x15;
    int d = 0b00010101;

    PRINT_INT(a)
    PRINT_INT(b)
    PRINT_INT(c)
    PRINT_INT(d)

    return 0;
}
