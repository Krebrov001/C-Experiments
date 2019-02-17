#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    if (-2147483648 > 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    putc('\n', stdout);

    return EXIT_SUCCESS;
}
