/**
 * @file     Google_modulo.c
 * @author   Konstantin Rebrov
 * @version  07/12/2018
 *
 * Google this keyword: "-2 % 256"
 * You get the answer 254.
 * The correct answer is -2.
 *
 * Google Calculator gives a wrong answer for modulo when the dividend
 * (first operand) is negative.
 * My program demonstrates how this bug of Google Calculator could have
 * come about. It is because the dividend is treated as an unsigned value.
 * A negative number becomes a large positive number, and that large positive
 * number becomes the dividend of the % operator.
 *
 * The % operator is not just one operator. It is two different operators:
 * One works for an unsigned divisor.
 * Another works for a signed two's complement divisor.
 * This is because a bit pattern > INT_MAX could be interpreted either as
 * a large positive number or as a negative number.
 *
 * The algorithms for signed divisor and unsigned divisor are different.
 * The % operator should be implemented differently in these two scenarios.
 *
 * I wrote two functions that do x % 256 in both of these scenarios.
 * The function signed_mod_256() works with a signed divisor.
 * The function unsigned_mod_256() works with an unsigned divisor.
 *
 * The % operator in C works in both of these scenarios.
 *
 */
#include <stdio.h>
#include <stdlib.h>

/*
 These macros enable you to print the names of variables or expressions
 along with the values that they evaluate to.

 The passed in argument can be printed in signed, unsigned, or hexadecimal
 format. The hexadecimal format is especially nice because it allows you
 to see the underlying bit representation of the parameter.

 These macros are especially intuitively named for self-documenting code.
 They are designed to keep complicated printf statements from obscuring the
 readability of the code.
 */

#define PRINT_SIGNED_INT(x) printf("%s = %d\n", #x, x)

#define PRINT_UNSIGNED_INT(x) printf("%s = %u\n", #x, x)

#define PRINT_INT_HEX(x) printf("%s = %#.8x\n", #x, x)

/**
 * This function returns (dividend % 256) for signed numbers.
 * It works similar to (+/-) (abs(x) % 256)
 *
 * My algorithm finds % 256 (2^8) by extracting the low order 8 bits from
 * the dividend.
 * If the dividend is positive, that byte is padded with leading 0's.
 * If the dividend is negative, that byte is padded with leading 1's
 * to preserve the signedness.
 *
 * @param signed int dividend - The dividend is of a signed type because
 *     the most-significant bit is counted as a negative weight.
 *     The modulo algorithm changes if you want it to work correctly with
 *     negative signed numbers as well.
 */
int signed_mod_256(signed int dividend)
{
  /*
   Determines the number of bits left in the divisor, if we extract the
   8 low order bits. The result is the number of bits to shift by.
   */
  int shiftBy = (sizeof(dividend) - 1) << 3;

  /*
   Produces a copy of the sign bit over all the bits except for the
   8 low order bits, which are intended to be extracted from the number.
   Those 8 corresponding bit positions are necessarily filled with 0's.
   Because the dividend is a signed int, an arithmetic right shift is made.
   */
  int sign_mask = (dividend >> shiftBy) & ~0xFF;

  /*
   Extracts the 8 low order bits from the number, and fills in the remaining
   bit positions to the left with 0's.
   The dividend is type cast to unsigned to make a logical right shift.
   */
  int least_significant_byte = ((unsigned) dividend << shiftBy) >> shiftBy;

  /*
   The least_significant_byte is the result of the modulo operation, and
   the sign_mask preserves the sign of the remainder if the dividend was
   a negative number.
   */
  return sign_mask | least_significant_byte;
}


/**
 * This function returns (dividend % 256) for unsigned numbers.
 *
 * This is just a simpler version of the signed_mod_256() algorithm.
 * This one doesn't have to take the sign bit into account, since it is assumed
 * that all inputs are supposed to be unsigned.
 *
 * My algorithm finds % 256 (2^8) by extracting the low order 8 bits from
 * the dividend.
 * Because the dividend is positive, that byte is padded with leading 0's.
 *
 * @param unsigned int dividend - The dividend is of an unsigned type because
 *     the most-significant bit is counted as a positive weight.
 */
int unsigned_mod_256(unsigned int dividend)
{
  /*
   Determines the number of bits left in the divisor, if we extract the
   8 low order bits. The result is the number of bits to shift by.
   */
  int shiftBy = (sizeof(dividend) - 1) << 3;

  /*
   Extracts the 8 low order bits from the number, and fills in the remaining
   bit positions to the left with 0's.
   Because the dividend is a signed int, a logical right shift is made.
   */
  return (dividend << shiftBy) >> shiftBy;
}


int main(void)
{
  /*
   Here we can see what the dividend would look like as an unsigned number
   if the bit pattern would be reinterpreted.
   */
  signed int signed_dividend = -2;
  PRINT_SIGNED_INT(   signed_dividend);
  PRINT_UNSIGNED_INT( signed_dividend);
  PRINT_INT_HEX(      signed_dividend);

  putchar('\n');

  /*
   The % operator in C returns the right answer for a signed operand.
   */
  signed int signed_remainder = signed_dividend % 256;
  PRINT_SIGNED_INT(   signed_remainder);
  PRINT_UNSIGNED_INT( signed_remainder);
  PRINT_INT_HEX(      signed_remainder);

  putchar('\n');

  /*
   My signed_mod_256() function returns the right answer for a signed operand.
   */
  signed int signed_dividend_mod_256 = signed_mod_256(signed_dividend);
  PRINT_SIGNED_INT(   signed_dividend_mod_256);
  PRINT_UNSIGNED_INT( signed_dividend_mod_256);
  PRINT_INT_HEX(      signed_dividend_mod_256);

  putchar('\n');

  /*
   My unsigned_mod_256() function returns the right answer for an unsigned
   operand only.
   It returns the wrong answer for a signed operand.
   */
  unsigned int unsigned_dividend_mod_256 = unsigned_mod_256(signed_dividend);
  PRINT_SIGNED_INT(   unsigned_dividend_mod_256);
  PRINT_UNSIGNED_INT( unsigned_dividend_mod_256);
  PRINT_INT_HEX(      unsigned_dividend_mod_256);

  putchar('\n');

  return EXIT_SUCCESS;
}
