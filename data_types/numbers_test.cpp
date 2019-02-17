#include <iostream>
#include <cstdint>
#include <cstdio>
using std::cout;
using std::endl;

int main() {
  char ch = 'A';
  short s = 512;
  s = ch;
  cout << s << endl;

  uint8_t a = 254;
  int16_t b = 512;
  b = a;
  uint16_t c = 512;
  c = a;
  cout << "b: " << b << "\nc: " << c << endl;

  s = 67;
  ch = s;
  cout << ch << endl;

  uint16_t num1 = 544;
  uint8_t num2 = num1;
  cout << "num1 is " << num1 << endl;
  cout << "num2 is " << num2 << endl;
  printf("num1 is %hd\n", num1);
  printf("num2 is %hhd\n", num2);

  num2 = 65;
  cout << "num2 is " << num2 << endl;
  printf("num2 is %hhd\n", num2);

  b = -4;
  a = b;
  printf("%hhu\n", a);

  s = 0x0409;  // 2^10 + 2^3 + 2^0
  int i = s;
  cout << i << endl;

  i = 0x00a04007;
  s = i;
  cout << s << endl;

  i = 0x00a08007;
  s = i;
  cout << s << endl;
  printf("%hd\n", s);
  printf("%hu\n", s);
  printf("%#hx\n", s);

  s = 0xffff;  // s = -1;
  i = s;
  printf("sign extend: %d : %u\n", i, i);

  unsigned short int us = 0xffff;
  i = us;
  printf("zero extend: %d : %u\n", i, i);

  return 0;
}

