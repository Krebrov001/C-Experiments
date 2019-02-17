#include <iostream>
using namespace std;

int main() {
  /* int** points to new array of 4 int *'s */
  int** p = new int*[4];

  /* int* points to new array of 3 ints */
  p[0] = new int[3];
  p[1] = new int[3];
  p[2] = new int[3];
  p[3] = new int[3];

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

  cout << endl;

  cout << "Array of int*'s:" << endl;
  for (int i = 0; i < 4; i++) {
    cout << p+i << " : " << p[i] << endl;
  }

  cout << endl;

  for (int i = 0; i < 4; i++) {
    delete[] p[i];
    p[i] = NULL;
    cout << "p[" << i << "] freed!" << endl;
  }
  delete[] p;
  p = NULL;
  cout << "p freed!" << endl;
  cout << "p : " << p << endl;

  return 0;
}
