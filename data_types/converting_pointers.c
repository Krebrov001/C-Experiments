// This code demonstrates conversions from regular pointers to void*'s and vice-versa
// In C vs C++. Compile it under two languages, and gcc/g++ vs clang/clang++.
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char* byte_ptr;


int main(void)
{
    int num1 = 12345;

    /*
    int*     ptr1 = &num1;
    byte_ptr ptr2 = &num1;
    float*   ptr3 = &num1;
    float*   ptr4 = (float*) &num1;
    void*    ptr5 = &num1;

    printf("int*     ptr1: %p\n", ptr1);
    printf("byte_ptr ptr2: %p\n", ptr2);
    printf("float*   ptr3: %p\n", ptr3);
    printf("float*   ptr4: %p\n", ptr4);
    printf("void*    ptr5: %p\n", ptr5);

    ptr1 = ptr5;
    ptr2 = ptr5;
    ptr3 = ptr5;
    ptr4 = ptr5;
    */

    void* v_ptr = &num1;
    int*  i_ptr = v_ptr;

    return EXIT_SUCCESS;
}
