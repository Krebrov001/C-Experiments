/*
 * Name: dynamic_pointer_arrays.cpp
 * Author: Konstantin Rebrov
 * Date: 03/28/2017
 * Description: Demonstrate using dynamic arrays as pointers
 *              and the relationship between pointers and arrays
 * Sources: dynamic_arrays.cpp (Luke Sathrum)
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
 * This function prints out the array using array bracket syntax
 * @param int *array - the dynamic array that was created in main()
 *                     uses the int pointer syntax
 * @param const int &size - size of the array, a const by reference int value
 *                          is a reference variable but contents can't be changed
 */
void PrintArray1(int *array, const int &size);

/*
 * This function prints out the array using int pointer syntax
 * @param int array[] - the dynamic array that was created in main()
 *                      uses the array bracket syntax
 * @param const int &size - size of the array, a const by reference int value
 *                          is a reference variable but contents can't be changed
 */
void PrintArray2(int array[], const int &size);

int main() {
  // int *numbers is an int pointer
  // actually a pointer to an array
  int *numbers, size;

  cout << "Enter the size of the dynamic array: ";
  cin >> size;

  // new int[size] returns the address of a dynamic array of given size
  // the numbers int pointer stores that address
  // and points to the array index 0
  numbers = new int[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter a value for array[" << i << "]: ";
    cin >> numbers[i];
  }

  PrintArray1(numbers, size);

  PrintArray2(numbers, size);

  int *numbers2 = new int[size + 2];
  int i;
  for (i = 0; i < size; i++) {
    numbers2[i] = numbers[i];
  }
  while (i < size + 2) {
    numbers2[i] = 7;
    i++;
  }
  PrintArray2(numbers2, size + 2);

  

  return 0;
}

void PrintArray1(int *array, const int &size) {
  for (int i = 0; i < size - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << endl;
}

void PrintArray2(int array[], const int &size) {
  for (int i = 0; i < size - 1; i++) {
    cout << *array << ", ";
    array++;
  }
  cout << *array << endl;
}

