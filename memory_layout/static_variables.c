#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS and size_t

/*
 * This function demonstrates the use of static variables.
 * Local variables in functions are auto by default.
 * auto variables get created and destroyed each time the
 * function begins and ends.
 * static variables are created and initialized only once
 * when the function is first called, and then after that they
 * are not destroyed when the function ends, but rather come
 * alive again with their former values the next time the
 * function is called. static variables are only destroyed when
 * the whole entire program ends.
 * Both auto and static local variables are only visible inside
 * the function; other functions cannot see/use them.
 */
void counter() {
  //auto int num = 0;
  static int num = 0;
  num++;
  printf("function run %d\n", num);
}

int main() {

  for (size_t i = 0; i < 5; i++) {
    counter();
  }

  return EXIT_SUCCESS;
}
