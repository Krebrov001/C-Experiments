#include <iostream>  // C++ input/output stream
#include <cstdio>    // C standard input/output - for printf()
using namespace std;


void printStrings(const char array[][7], const int numStrings) {
  for (int i = 0; i < numStrings; i++) {
    printf("%s\n", array[i]);
  }
}


int main() {
  char strings[4][7] = { {'J', 'a', 'v', 'a', 'C', '#', '\0'},
                         {'O', 'r', 'a', 'c', 'l', 'e', '\0'},
                         {'a', 'p', 'p', 'l', 'e', 's', '\0'},
                         {'o', 'r', 'a', 'n', 'g', 'e', '\0'} };
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      cout << strings[i][j];
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < 4; i++) {
    printf("%s\n", strings[i]);
  }
  cout << endl;

  char* ptr = (char*) strings;
  for (int x = 0; x < 28; x++) {
    printf("%c", *(ptr + x));
  }
  cout << endl << endl;

  printStrings(strings, 4);
  cout << endl;

  return 0;
}
