#include <iostream>
using namespace std;

int main() {
  int p[4][3];

  int num = 2;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      p[i][j] = num;
      num += 2;
    }
  }

  cout << "Multidimensional array of ints:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      cout << p[i][j] << ' ';
    }
    cout << endl;
  }

  cout << sizeof(p[0][0]) << endl;
  cout << sizeof(p[0]) << endl;
  cout << sizeof(p) << endl;

  int (*r)[3] = p;  // Declares a pointer to a 1-D array of 3 integers.

  cout << endl;

  cout << "p\t"           << p           << endl;
  cout << "&p\t"          << &p          << endl;
  cout << "*p\t"          << *p          << endl;
  cout << "p+1\t"         << p+1         << endl;
  cout << "*(p+1)\t"      << *(p+1)      << endl;
  cout << "*(p+1)+2\t"    << *(p+1)+2    << endl;
  cout << "*(*(p+1)+2)\t" << *(*(p+1)+2) << endl;
  cout << "p[1]\t"        << p[1]        << endl;
  cout << "p[1]+2\t"      << p[1]+2      << endl;
  cout << "*(p[1]+2)\t"   << *(p[1]+2)   << endl;
  cout << "p[1][2]\t"     << p[1][2]     << endl;

  cout << endl;

  return 0;
}
