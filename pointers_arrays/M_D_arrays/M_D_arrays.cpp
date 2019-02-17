#include <iostream>
using std::cout;
using std::endl;

#include "M_D_arrays.h"

void print1Darray(const int p[], size_t size) {
  size_t i;

  for (i = 0; i < size; i++) {
    cout << p[i] << " ";
  }
  cout << endl;

  return;
}

void print2Darray(const int p[][3], size_t size) {
  size_t i, j;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 3; j++) {
      cout << p[i][j] << " ";
    }
  cout << endl;
  }

  return;
}

void print3Darray(const int p[][2][2], size_t size) {
  size_t i, j, k;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 2; j++) {
      cout << '\t';
      for (k = 0; k < 2; k++) {
        cout << p[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return;
}

void edit1Darray(int* p, size_t size, int newVal) {
  size_t i;

  for (i = 0; i < size; i++) {
    p[i] = newVal;
  }

  return;
}

void edit2Darray(int (*p)[3], size_t size, int newVal) {
  size_t i, j;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 3; j++) {
      p[i][j] = newVal;
    }
  }

  return;
}

void edit3Darray(int (*p)[2][2], size_t size, int newVal) {
  size_t i, j, k;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) {
        p[i][j][k] = newVal;
      }
    }
  }

  return;
}
