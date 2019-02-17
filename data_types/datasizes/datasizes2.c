/*
 * Data Sizes 2
 *
 * written by:            Konstantin Rebrov
 * created on:            12/16/2017
 * last modified on:      05/31/2018
 *
 * This program tests the size and range of the integer data types in C.
 * For each data type, we have a singed and an unsigned version.
 * Additionally, both the full name of each data type, and the shorthand version are used.
 * The goal is to see what the upper and lower limits of each data type are,
 * and what kind of data gets stored on overflow.
 *
 * First the size of the declared data types and the corresponding pointer are printed in bytes.
 *
 * Then test values are loaded into the singed version of the data type.
 * The expected value along with the actual value stored in the variable are printed to stdout.
 *    - The smallest signed negative value.
 *    - The largest signed positive value.
 *    - One more than the largest signed positive value.
 *    - One less than the smallest signed negative value.
 *    - Two more than the largest signed positive value.
 * Then test values are loaded into the unsinged version of the data type.
 * The expected value along with the actual value stored in the variable are printed to stdout.
 *    - The smallest unsigned value 0.
 *    - The largest possible unsigned value.
 *    - The signed value -1.
 *    - One more than the largest possible unsigned value.
 *    - The signed value -2.
 * 
 */
#include <stdio.h>

int main(void) {

  signed char a;
  char c;  // same as signed char c;
  unsigned char b;
  char* bp;

  printf("Size of signed char:          %2zu bytes\n", sizeof(a));
  printf("Size of unsigned char:        %2zu bytes\n", sizeof(b));
  printf("Size of char:                 %2zu bytes\n", sizeof(c));
  printf("Size of char pointer:         %2zu bytes\n", sizeof(bp));

  printf("%c", '\n');

  // the %+hhd or %+hhi format specifier is for signed char
  a = -128;
  printf("signed char value -128: %+hhd\n", a);
  a = 127;
  printf("signed char value +127: %+hhd\n", a);
  a = 128;
  printf("signed char value +128: %+hhd\n", a);
  a = -129;
  printf("signed char value -129: %+hhd\n", a);
  a = 129;
  printf("signed char value +129: %+hhd\n", a);

  printf("\n");

  c = -128;
  printf("char value -128: %+hhd\n", c);
  c = 127;
  printf("char value +127: %+hhd\n", c);
  c = 128;
  printf("char value +128: %+hhd\n", c);
  c = -129;
  printf("char value -129: %+hhd\n", c);
  c = 129;
  printf("char value +129: %+hhd\n", c);

  printf("\n");

  // the %hhu format specifier is for unsigned char
  b = 0;
  printf("unsigned char value    0: %hhu\n", b);
  b = 255;
  printf("unsigned char value +255: %hhu\n", b);
  b = -1;
  printf("unsigned char value   -1: %hhu\n", b);
  b = 256;
  printf("unsigned char value +256: %hhu\n", b);
  b = -2;
  printf("unsigned char value   -2: %hhu\n", b);
  b = 257;
  printf("unsigned char value +257: %hhu\n", b);

  printf("\n");

  signed short int d;
  short e;  // same as signed short int e;
  unsigned short int f;
  unsigned short g;  // same as unsigned short int g;
  short int* sp;

  printf("Size of signed short int:     %2zu bytes\n", sizeof(d));
  printf("Size of short:                %2zu bytes\n", sizeof(e));
  printf("Size of unsigned short int:   %2zu bytes\n", sizeof(f));
  printf("Size of unsigned short:       %2zu bytes\n", sizeof(g));
  printf("Size of short int pointer:    %2zu bytes\n", sizeof(sp));

  printf("\n");

  // the %+hd or %+hi format specifier is for signed short int
  d = -32768;
  printf("signed short int value -32768: %+hd\n", d);
  d = 32767;
  printf("signed short int value +32767: %+hd\n", d);
  d = 32768;
  printf("signed short int value +32768: %+hd\n", d);
  d = -32769;
  printf("signed short int value -32769: %+hd\n", d);
  d = 32769;
  printf("signed short int value +32769: %+hd\n", d);

  printf("\n");

  e = -32768;
  printf("short value -32768: %+hd\n", e);
  e = 32767;
  printf("short value +32767: %+hd\n", e);
  e = 32768;
  printf("short value +32768: %+hd\n", e);
  e = -32769;
  printf("short value -32769: %+hd\n", e);
  e = 32769;
  printf("short value +32769: %+hd\n", e);

  printf("\n");

  // the %hu format specifier is for unsigned short int
  f = 0;
  printf("unsigned short int value      0: %hu\n", f);
  f = 65535;
  printf("unsigned short int value +65535: %hu\n", f);
  f = -1;
  printf("unsigned short int value     -1: %hu\n", f);
  f = 65536;
  printf("unsigned short int value +65536: %hu\n", f);
  f = -2;
  printf("unsigned short int value     -2: %hu\n", f);
  f = 65537;
  printf("unsigned short int value +65537: %hu\n", f);

  printf("\n");

  g = 0;
  printf("unsigned short value      0: %hu\n", g);
  g = 65535;
  printf("unsigned short value +65535: %hu\n", g);
  g = -1;
  printf("unsigned short value     -1: %hu\n", g);
  g = 65536;
  printf("unsigned short value +65536: %hu\n", g);
  g = -2;
  printf("unsigned short value     -2: %hu\n", g);
  g = 65537;
  printf("unsigned short value +65537: %hu\n", g);

  printf("\n");

  signed int h;
  int i;  // same as signed int i;
  unsigned int j;
  unsigned k;  // same as unsigned int k;
  int* ip;

  printf("Size of signed int:           %2zu bytes\n", sizeof(h));
  printf("Size of int:                  %2zu bytes\n", sizeof(i));
  printf("Size of unsigned int:         %2zu bytes\n", sizeof(j));
  printf("Size of unsigned:             %2zu bytes\n", sizeof(k));
  printf("Size of int pointer:          %2zu bytes\n", sizeof(ip));

  printf("\n");

  // the %+d or %+i format specifier is for signed int
  h = -2147483648;
  printf("signed int value -2147483648: %+i\n", h);
  h = 2147483647;
  printf("signed int value +2147483647: %+i\n", h);
  h = 2147483648;
  printf("signed int value +2147483648: %+i\n", h);
  h = -2147483649;
  printf("signed int value -2147483649: %+i\n", h);
  h = 2147483649;
  printf("signed int value +2147483649: %+i\n", h);

  printf("\n");

  i = -2147483648;
  printf("int value -2147483648: %+d\n", i);
  i = 2147483647;
  printf("int value +2147483647: %+d\n", i);
  i = 2147483648;
  printf("int value +2147483648: %+d\n", i);
  i = -2147483649;
  printf("int value -2147483649: %+d\n", i);
  i = 2147483649;
  printf("int value +2147483649: %+d\n", i);

  printf("\n");

  // the %u format specifier is for unsigned int
  j = 0;
  printf("unsigned int value           0: %u\n", j);
  j = 4294967295;
  printf("unsigned int value +4294967295: %u\n", j);
  j = -1;
  printf("unsigned int value          -1: %u\n", j);
  j = 4294967296;
  printf("unsigned int value +4294967296: %u\n", j);
  j = -2;
  printf("unsigned int value          -2: %u\n", j);

  printf("\n");

  k = 0;
  printf("unsigned value           0: %u\n", k);
  k = 4294967295;
  printf("unsigned value +4294967295: %u\n", k);
  k = -1;
  printf("unsigned value          -1: %u\n", k);
  k = 4294967296;
  printf("unsigned value +4294967296: %u\n", k);
  k = -2;
  printf("unsigned value          -2: %u\n", k);

  printf("\n");

  signed long int l;
  long m;  // same as signed long int m;
  unsigned long int n;
  unsigned long o;  // same as unsigned long int o;
  long int* lp;

  printf("Size of signed long int:      %2zu bytes\n", sizeof(l));
  printf("Size of long:                 %2zu bytes\n", sizeof(m));
  printf("Size of unsigned long int:    %2zu bytes\n", sizeof(n));
  printf("Size of unsigned long:        %2zu bytes\n", sizeof(o));
  printf("Size of long int pointer:     %2zu bytes\n", sizeof(lp));

  printf("\n");

  // the %+ld or %+li format specifier is for signed long int
  l = -9223372036854775808;
  printf("signed long int value -9223372036854775808: %+ld\n", l);
  l = 9223372036854775807;
  printf("signed long int value +9223372036854775807: %+ld\n", l);
  l = 9223372036854775808;
  printf("signed long int value +9223372036854775808: %+ld\n", l);
  l = -9223372036854775809;
  printf("signed long int value -9223372036854775809: %+ld\n", l);
  l = 9223372036854775809;
  printf("signed long int value +9223372036854775809: %+ld\n", l);

  printf("\n");

  m = -9223372036854775808;
  printf("long value -9223372036854775808: %+ld\n", m);
  m = 9223372036854775807;
  printf("long value +9223372036854775807: %+ld\n", m);
  m = 9223372036854775808;
  printf("long value +9223372036854775808: %+ld\n", m);
  m = -9223372036854775809;
  printf("long value -9223372036854775809: %+ld\n", m);
  m = 9223372036854775809;
  printf("long value +9223372036854775809: %+ld\n", m);

  printf("\n");

  // the %lu format specifier is for unsigned long int
  n = 0;
  printf("unsigned long int value                     0: %lu\n", n);
  n = 18446744073709551615;
  printf("unsigned long int value +18446744073709551615: %lu\n", n);
  n = -1;
  printf("unsigned long int value                    -1: %lu\n", n);
  n = 18446744073709551616;
  printf("unsigned long int value +18446744073709551616: %lu\n", n);
  n = -2;
  printf("unsigned long int value                    -2: %lu\n", n);

  printf("\n");

  o = 0;
  printf("unsigned long value                     0: %lu\n", o);
  o = 18446744073709551615;
  printf("unsigned long value +18446744073709551615: %lu\n", o);
  o = -1;
  printf("unsigned long value                    -1: %lu\n", o);
  o = 18446744073709551616;
  printf("unsigned long value +18446744073709551616: %lu\n", o);
  o = -2;
  printf("unsigned long value                    -2: %lu\n", o);

  printf("\n");

  signed long long int p;
  long long q;  // same as signed long long int q;
  unsigned long long int r;
  unsigned long long s;  // same as unsigned long long int s;
  long long int* llp;

  printf("Size of signed long long int:    %2zu bytes\n", sizeof(p));
  printf("Size of long long:               %2zu bytes\n", sizeof(q));
  printf("Size of unsigned long long int:  %2zu bytes\n", sizeof(r));
  printf("Size of unsigned long long:      %2zu bytes\n", sizeof(s));
  printf("Size of long long int pointer:   %2zu bytes\n", sizeof(llp));

  printf("\n");

  // the %+lld or %+lli format specifier is for signed long long int
  p = -9223372036854775808;
  printf("signed long long int value -9223372036854775808: %+lld\n", p);
  p = 9223372036854775807;
  printf("signed long long int value +9223372036854775807: %+lld\n", p);
  p = 9223372036854775808;
  printf("signed long long int value +9223372036854775808: %+lld\n", p);
  p = -9223372036854775809;
  printf("signed long long int value -9223372036854775809: %+lld\n", p);
  p = 9223372036854775809;
  printf("signed long long int value +9223372036854775809: %+lld\n", p);

  printf("\n");

  q = -9223372036854775808;
  printf("long long value -9223372036854775808: %+lld\n", q);
  q = 9223372036854775807;
  printf("long long value +9223372036854775807: %+lld\n", q);
  q = 9223372036854775808;
  printf("long long value +9223372036854775808: %+lld\n", q);
  q = -9223372036854775809;
  printf("long long value -9223372036854775809: %+lld\n", q);
  q = 9223372036854775809;
  printf("long long value +9223372036854775809: %+lld\n", q);

  printf("\n");

  // the %llu format specifier is for unsigned long long int
  r = 0;
  printf("unsigned long long int value                     0: %llu\n", r);
  r = 18446744073709551615;
  printf("unsigned long long int value +18446744073709551615: %llu\n", r);
  r = -1;
  printf("unsigned long long int value                    -1: %llu\n", r);
  r = 18446744073709551616;
  printf("unsigned long long int value +18446744073709551616: %llu\n", r);
  r = -2;
  printf("unsigned long long int value                    -2: %llu\n", r);

  printf("\n");

  s = 0;
  printf("unsigned long long value                     0: %llu\n", s);
  s = 18446744073709551615;
  printf("unsigned long long value +18446744073709551615: %llu\n", s);
  s = -1;
  printf("unsigned long long value                    -1: %llu\n", s);
  s = 18446744073709551616;
  printf("unsigned long long value +18446744073709551616: %llu\n", s);
  s = -2;
  printf("unsigned long long value                    -2: %llu\n", s);

  printf("\n");

  return(0);  // return 0;
}

