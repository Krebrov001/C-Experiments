#include <stdio.h>


struct S1 {
  char c;
  int i[2];
  double v;
};


struct S2 {
  double v;
  int i[2];
  char c;
};


int main() {
  struct S1 first_struct;
  struct S2 second_struct;

  printf("size of first struct: %lu\n", sizeof(first_struct));
  printf("size of second struct: %lu\n", sizeof(second_struct));

  return 0;
}
