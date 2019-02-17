/*
 * Name        : odd_even_arrays.cpp
 * Author      : Konstantin Rebrov
 * Date        : 03/19/2017
 * Description : Testing array output
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArray(int array[], int size);

int main() {
  int odd[5] = {1, 3, 5, 7, 9};
  int even[5] = {2, 4, 6, 8, 10};
  int a = 1;
  cout << "int a takes up size: " << sizeof(a) << endl;
  cout << "int odd[] takes up size: " << sizeof(odd) << endl;
  cout << "odd[0] takes up size: " << sizeof(odd[0]) << endl;
  cout << "There are " << sizeof(odd) / sizeof(odd[0]);
  cout << " elements in int odd[].\n";

  int last = (sizeof(odd)/sizeof(odd[0])-1);
  for (int i = 0; i < last; i++) {
    cout << odd[i] << ", " << even[i] << ", ";
  }
  cout << odd[last] << ", " << even[last] << endl;

  printArray(odd, (sizeof(odd)/sizeof(odd[0])));

  return 0;
}

void printArray(int array[], int size) {
  cout << "Print out the array that was passed in.\n";
  for (int i = 0; i < size; i++) {
    cout << "array[" << i << "] : " << array[i] << endl;
  }
}
