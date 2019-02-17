/*
 * Name             : multi_d_arrays.cpp
 * Author           : Konstantin Rebrov
 * Created on       : 26 December 2017
 * Last modified on : 27 December 2017
 * Description      : This program demonstrates some operations on a 2-dimensional char array.
 *                    The char array is printed as is, then it is modified and printed in different ways:
 *                     - as is
 *                     - chars reversed
 *                     - words reversed
 *                     - both chars and words reversed (completely in reverse order)
 */

#include <iostream>  // C++ standard input/output stream - for cout, endl, and overloaded bitwise operators
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
using std::cout;
using std::endl;

int main() {
  char multi_array[2][5] = { {'H', 'e', 'l', 'l', 'o'},
                             {'W', 'o', 'r', 'l', 'd'} };

  // Prints out the first word forwards, and then the second word forwards.
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      cout << multi_array[i][j];
    }
    if (i == 0)
      cout << ' ';
  }
  cout << endl << endl;;

  // Modifies the individual characters in the array.
  multi_array[0][0] = 'J';
  multi_array[0][4] = 'y';
  multi_array[1][1] = 'u';

  // Prints the new array.
  // Prints out the first word forwards, and then the second word forwards.
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      cout << multi_array[i][j];
    }
    if (i == 0)
      cout << ' ';
  }
  cout << endl << endl;;

  // Prints out the first word backwards, and then the second word backwards.
  // Swaps the order of the individual letters in each word.
  for (int i = 0; i < 2; i++) {
    for (int j = 4; j >= 0; j--) {
      cout << multi_array[i][j];
    }
    if (i == 0)
      cout << ' ';
  }
  cout << endl << endl;;

  // Prints out the second word forwards, and then the first word forwards.
  // Swaps the order of the words.
  for (int i = 1; i >= 0; i--) {
    for (int j = 0; j < 5; j++) {
      cout << multi_array[i][j];
    }
    if (i == 1)
      cout << ' ';
  }
  cout << endl << endl;;

  // Prints out the second word backwards, and then the first word backwards.
  // Swaps the order of the words and the order of the individual letters in each word.
  // The whole entire char array is printed completely backwards, like in Arabic.
  for (int i = 1; i >= 0; i--) {
    for (int j = 4; j >= 0; j--) {
      cout << multi_array[i][j];
    }
    if (i == 1)
      cout << ' ';
  }
  cout << endl << endl;;

  return EXIT_SUCCESS;
}
