/**
 * @file find_UMax_TMax_TMin.c
 * @author Konstantin Rebrov
 * @version 07/07/2018
 *
 * @section DESCRIPTION
 *
 * Problem Statement:
 * Programatically find UMax, TMax, and TMin,
 * without depending on w, the bit width.
 */
#include <stdio.h>   /* C standard input/output - for print() */
#include <limits.h>  /* C integral data type limits - for INT_MIN, INT_MAX, UINT_MAX */
#include <stdlib.h>  /* C standard library - for EXIT_SUCCESS */
#include <stdint.h>  /* C standard integer data types - for uint8_t */

#define PRINT_INT(x) printf("%s = %d\n", #x, x);

#define PRINT_UNSIGNED(x) printf("%s = %u\n", #x, x);

 int main(void)
 {
     unsigned int UMax = ~0U;
     signed int TMax   = UMax >> 1;  /* unsigned - logical right shift */
     signed int TMin1  = (-TMax - 1);
     signed int TMin2  = ~TMax;

     uint8_t tests_passed = 0;

     /* putchar('\n'); is equivalent to putc('\n', stdout); */

     PRINT_UNSIGNED(UMax)
     if (UMax == UINT_MAX) {
       printf("UMax == UINT_MAX\n");
       tests_passed++;
     }
     putchar('\n');

     PRINT_INT(TMax)
     if (TMax == INT_MAX) {
       printf("TMax == INT_MAX\n");
       tests_passed++;
     }
     putchar('\n');

     PRINT_INT(TMin1)
     if (TMin1 == INT_MIN) {
       printf("TMin1 == INT_MIN\n");
       tests_passed++;
     }
     putchar('\n');

     PRINT_INT(TMin2)
     if (TMin2 == INT_MIN) {
       printf("TMin2 == INT_MIN\n");
       tests_passed++;
     }
     putchar('\n');

     printf("Your code passes %hhd tests.\n", tests_passed);

     return EXIT_SUCCESS;
 }
