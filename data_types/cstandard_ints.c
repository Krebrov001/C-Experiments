#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


#define PRINT_SIZE(x) printf("%s : %zu\n", #x, x);

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

    printf("=================================\n\n");

    intmax_t numberMax1 = INTMAX_MIN;
    intmax_t numberMax2 = INTMAX_MAX;
    uintmax_t unsignedMax = UINTMAX_MAX;

    printf("INTMAX_MIN  : %" PRIdMAX "\n", numberMax1);
    printf("INTMAX_MAX  : %" PRIdMAX "\n", numberMax2);
    printf("UINTMAX_MAX : %" PRIuMAX "\n", unsignedMax);

    int8_t number1 = INT8_MIN;
    int8_t number2 = INT8_MAX;
    uint8_t number3 = UINT8_MAX;

    printf("INT8_MIN  : %" PRId8 "\n", number1);
    printf("INT8_MAX  : %" PRId8 "\n", number2);
    printf("UINT8_MAX : %" PRIu8 "\n", number3);

    return EXIT_SUCCESS;
}
