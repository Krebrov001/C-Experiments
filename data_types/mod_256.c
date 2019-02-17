#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int16_t f = 0x82b5;
    int16_t f_mod_256 = f % 256;
    int16_t f_result = 0xffb5;

    printf("f = %hi\n", f);
    printf("f_mod_256 = %hi\n", f_mod_256);
    printf("f_result = %hi\n", f_result);

    return 0;
}
