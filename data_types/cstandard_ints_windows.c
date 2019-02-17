#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define PRINT_SIZE(x) printf("%s : %lu\n", #x, x);

int main(void)
{
    PRINT_SIZE(sizeof(int8_t))
    PRINT_SIZE(sizeof(int16_t))
    PRINT_SIZE(sizeof(int32_t))
    PRINT_SIZE(sizeof(int64_t))
    PRINT_SIZE(sizeof(uint8_t))
    PRINT_SIZE(sizeof(uint16_t))
    PRINT_SIZE(sizeof(uint32_t))
    PRINT_SIZE(sizeof(uint64_t))

    putchar('\n');

    PRINT_SIZE(sizeof(int_fast8_t))
    PRINT_SIZE(sizeof(int_fast16_t))
    PRINT_SIZE(sizeof(int_fast32_t))
    PRINT_SIZE(sizeof(int_fast64_t))
    PRINT_SIZE(sizeof(uint_fast8_t))
    PRINT_SIZE(sizeof(uint_fast16_t))
    PRINT_SIZE(sizeof(uint_fast32_t))
    PRINT_SIZE(sizeof(uint_fast64_t))

    putchar('\n');

    PRINT_SIZE(sizeof(int_least8_t))
    PRINT_SIZE(sizeof(int_least16_t))
    PRINT_SIZE(sizeof(int_least32_t))
    PRINT_SIZE(sizeof(int_least64_t))
    PRINT_SIZE(sizeof(uint_least8_t))
    PRINT_SIZE(sizeof(uint_least16_t))
    PRINT_SIZE(sizeof(uint_least32_t))
    PRINT_SIZE(sizeof(uint_least64_t))

    putchar('\n');

    PRINT_SIZE(sizeof(intmax_t))
    PRINT_SIZE(sizeof(uintmax_t))

    putchar('\n');

    PRINT_SIZE(sizeof(intptr_t))
    PRINT_SIZE(sizeof(uintptr_t))

    putchar('\n');

    return EXIT_SUCCESS;
}
