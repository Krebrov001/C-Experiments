#include <stdio.h>

int main() {
  #ifdef __cplusplus
    printf("C++\n");
  #endif
  #ifdef __STDC__
    printf("C\n");
  #endif
  printf("Size of 'a': %ld\n", sizeof('a'));
  int number = 10 //* comment */ 2;
  ;
  printf("number = %d\n", number);

  return 0;
}
