#include <stdlib.h>  // for malloc()
#include <stdio.h>   // for printf()
#include "strdup.h"

int main(void)
{
    char* const a = strdup("hello");
    printf("%s\n", a);
    printf("%p\n", a);
    printf("%p\n", "hello");
}
