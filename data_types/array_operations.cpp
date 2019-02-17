/*
 * Name             : array_operations.cpp
 * Title            : Common Array Operations
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 14 January 2017
 * Last modified on : 15 Jaunary 2017
 * Description      : This program defines several functions that perform common
 *                    array operations such as:
 *                      - neatly printing the contents of an array to stdout
 *                      - setting each array element to the sum of itself and the next element
 *                      - reversing an array
 */

#include <iostream>  // C++ standard input/output
#include <cstdlib>   // C standard library - for EXIT_SUCCESS and size_t data type
using std::cin;   // used to get program input from  stdin  [0]
using std::cout;  // used to print program output to stdout [1]
using std::cerr;  // used to print error messages to stderr [2]
using std::endl;  // prints a '\n' and flushes the buffer


/*
 * This function prints an int array with the array elements separated by a comma,
 * but without a comma after the last element.
 *
 * @param const int array[] - This int array cannot be modified.
 *                            Technically this is actually a pointer to the array
 *                            base address.
 * @param const size_t array_length - The size of the array in number of elements.
 *
 */
void printArray(const int array[], const size_t array_length) {
  //------------------------------------------------------------------------------
  //  size_t is a data type defined in stdlib.h or cstdlib
  //  It is an unsigned type that is used to hold an array index or loop counter.
  //  a size_t is also the type returned by the sizeof() operator
  //  To find out what size_t is typedef'd to, use the following command:
  //       echo | gcc -E -xc -include 'stddef.h' - | grep size_t
  //       typedef long unsigned int size_t;
  //------------------------------------------------------------------------------
  size_t i;
  for (i = 0; i < (array_length - 1); i++) {
    cout << array[i] << ", ";
  }
  cout << array[i] << endl;
}


/*
 * This function sets each array element [except the last one]
 * as the sum of itself and the next element in the array.
 *
 * @param int array[] - The int array that is to be modified.
 * @param const size_t array_length - The size of the array in number of elements.
 *
 */
// arrays are passed by pointer, so int array[] is equivalent to int* array here
// I use int array[] for readability and clarity, that an array is passed
// rather than just any pointer.
//void SumNext(int* array, const size_t array_length) {
void SumNext(int array[], const size_t array_length) {
  for (size_t i = 0; i < (array_length - 1); i++) {
    array[i] += array[i + 1];
  }
}


/*
 * This function reverses an array of any size in number of array elements.
 * First the outermost elements are swapped, then the next inner ones, etc, etc.
 * The algorithm swaps array elements from the outside in until it gets to the middle,
 * swapping the two middle elements if the size of the array is even,
 * or leaving the single middle element alone if the size of the array is odd.
 * It will take this function (array_length / 2) loop iterations to reverse the array.
 * If the size of the array is 1, the loop is not even entered, and the array is
 * already "reversed."
 *
 * @param int array[] - The int array that is to be reversed.
 * @param const size_t array_length - The size of the array in number of elements.
 *
 */
void ReverseArray(int array[], const size_t array_length) {
  auto int temp;
  for (size_t i = 0; i < (array_length / 2); i++) {
    temp = array[i];
    array[i] = array[array_length - 1 - i];
    array[array_length - 1 - i] = temp;
  }
}


/*
 * This is the main method/function of the program.
 * The program execution starts here at runtime.
 */
int main() {
  ////////////////////////////////////////////////////////////////
  //
  // Comment out one array or the other to use it.
  // The functions can be called with arrays of different sizes.
  //
  ////////////////////////////////////////////////////////////////

  const size_t ARRAY_SIZE = 7;
  int numbersArray[ARRAY_SIZE] = {10, 20, 30, 40, 50, 60, 70};  // array initialization list

  //const size_t ARRAY_SIZE = 4;
  //int numbersArray[ARRAY_SIZE] = {10, 20, 30, 40};  // array initialization list

  // If the size of the array would be omitted, the compiler would allocate
  // enough memory space to house the items in the initialization list

  printArray(numbersArray, ARRAY_SIZE);

  SumNext(numbersArray, ARRAY_SIZE);

  printArray(numbersArray, ARRAY_SIZE);

  ReverseArray(numbersArray, ARRAY_SIZE);

  printArray(numbersArray, ARRAY_SIZE);

  return EXIT_SUCCESS;
}
