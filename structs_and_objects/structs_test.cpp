#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library      - for EXIT_SUCCESS
#include <cstdio>    // C standard input/output - for printf()
#include <cstdint>   // C standard integer data types
using std::cout;
using std::endl;

struct Time {
  int8_t hours;
  int8_t minutes;
  int8_t seconds;
  void printTime() {
    printf("The time is %02hhd:%02hhd:%02hhd\n", hours, minutes, seconds);
  }
};

int main() {
  Time clock1;
  clock1.hours   = 5;
  clock1.minutes = 30;
  clock1.seconds = 10;

  clock1.printTime();

  Time clock2;
  clock2.hours   = 2;
  clock2.minutes = 20;
  clock2.seconds = 8;

  clock2.printTime();

  clock2 = clock1;

  clock2.printTime();

  cout << "A clock takes up " << sizeof(clock1) << " bytes." << endl;

  return EXIT_SUCCESS;
}
