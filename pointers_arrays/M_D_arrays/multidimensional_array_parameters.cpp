#include <iostream>
#include <cstdlib>   // cstdlib also includes size_t!
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include "M_D_arrays.h"
  
void fillMultiLevelArray(int** p, size_t numRows, size_t numCols);

void printMultiLevelArray(int** p, size_t numRows, size_t numCols);

int main()
{
  int A[2] = {1, 2};  // 1-D array of ints

  int B[2][3] = {  // 2-D array is an array of 1-D arrays with 3 ints
    {2, 4, 6},
    {5, 7, 8} };

  int C[3][2][2] = {     // 3-D array is an array of 2-D arrays of 2*2 ints
    { {2, 5}, {7, 9} },
    { {3, 4}, {6, 1} },
    { {0, 8}, {11, 13} }
                   };

  print1Darray(A, 2);  // name of a 1-D array is a pointer to int (base data type)
  cout << endl;

  edit1Darray(A, 2, 1);
  
  print1Darray(A, 2);
  cout << endl;

  cout << endl;

  print2Darray(B, 2);  // name of a 2-D array is a pointer to 1-D array of 3 ints
  cout << endl;

  edit2Darray(B, 2, 1);
  
  print2Darray(B, 2);
  cout << endl;

  cout << endl;

  print3Darray(C, 3);  // name of a 3-D array is a pointer to 2-D array of 2*2 ints
  cout << endl;

  edit3Darray(C, 3, 1);
  
  print3Darray(C, 3);
  cout << endl;

  cout << string('=', 30) << endl;

  int** p = nullptr;

  size_t numRows = 0;
  size_t numCols = 0;

  cout << "How many rows do you want? ";
  cin  >> numRows;
  cout << "How many columns do you want? ";
  cin  >> numCols;

  p = new int*[numRows];

  for (size_t i = 0; i < numRows; i++) {
    p[i] = new int[numCols];
  }

  fillMultiLevelArray(p, numRows, numCols);

  printMultiLevelArray(p, numRows, numCols);

  for (size_t i = 0; i < numRows; i++) {
    // Free each int array that p[i] points to.
    delete[] p[i];
    p[i] = nullptr;
  }

  // Free the int* array that p points to.
  delete[] p;
  p = nullptr;

  return EXIT_SUCCESS;
}

void fillMultiLevelArray(int** p, size_t numRows, size_t numCols) {
  size_t i, j;
  int number = 1;

  for (i = 0; i < numRows; i++) {
    for (j = 0; j < numCols; j++) {
      *(*(p+i)+j) = number;
      number++;
    }
  }

  return;
}

void printMultiLevelArray(int** p, size_t numRows, size_t numCols) {
  size_t i, j;

  for (i = 0; i < numRows; i++) {
    for (j = 0; j < numCols; j++) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }

  return;
}
