#include <stdlib.h>
#include <stdio.h>


// Prints the passed in expression literally, and also its value as a pointer and as an integer.
#define PRINT(x) printf(#x" = %p : %lu\n", x, x);

int global1 = 3;
int global2;

void function(void)
{
    int t = 5;
    PRINT(&t);
}


int main(int argc, char* argv[])
{
    printf(".text segment: contains the code\n");
    PRINT(&function);

    char* cp = "Hello World";
    printf(".rodata segment: contains the string literals\n");
    PRINT(cp);

    printf(".data segment: contains initialized globals\n");
    PRINT(&global1);

    printf(".bss segment: contains uninitialized globals\n");
    PRINT(&global2);

    int* ip   = malloc(sizeof(int));
    char* str = malloc(40 * sizeof(char));
    printf("Heap segment: contains dynamically allocated data\n");
    PRINT(ip);
    PRINT(str);

    int num1;
    printf("Stack segment: contains function activation records\n");
    PRINT(&num1);
    function();

    printf("Command-line arguments and environment variables\n");
    PRINT(argv);
    PRINT(argv[0]);

    return EXIT_SUCCESS;
}
