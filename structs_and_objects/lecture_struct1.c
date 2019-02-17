#include <math.h>

struct S1 {
  char c;
  int i[2];
  double v;
};

int main() {
  struct S1 str1;
  str1.c = 'A';
  str1.i[0] = 4;
  str1.i[1] = 5;
  str1.v = HUGE_VAL;
}
