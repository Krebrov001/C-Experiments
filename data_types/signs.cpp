#include <cstdint>
#include <iostream>
using namespace std;
//using std::cout;
//using std::endl;


/*
 * This function prints an 8 bit integer in binary.
 * The internal data representation of an 8 bit integer is of course,
 * an 8 bit binary number ex: %1111_1111
 * Basically, the loop goes through each bit from left to right
 * and each bit is shifted over to the 1s position.
 * It is then ANDed with a 1 to check if it is a 1 or a 0 at that bit position.
 * If most significant 4 bits have already been printed, a _ is printed for
 * cleanly formatted output.
 * This algorithm could also be used to print out to a stringstream.
 *
 * @param uint8_t value - The unsigned 8 bit number.
 *
 */
void showBits(uint8_t value) {
  cout << '%';
  for (int8_t i = 7; i >= 0; --i) {
    cout << ((value >> i) & 1);
    if (i == 4)
      cout << '_';
  }
}


// this is the main method of the program
// the program starts here at runtime
int main() {
  system("clear");

  uint8_t i = 0;
  for (i = 0; i < 255; i++) {
    showBits(i);
    printf(" : %d %hhd\n", i, i);
  }
  showBits(i);
  printf(" : %d %hhd\n", i, i);

  return 0;
}

