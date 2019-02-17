/*
 * Name        : sorting.cpp
 * Author      : Konstantin Rebrov
 * Date        : 04/01/2017
 * Language    : C++
 * Description : Implementation of various sorting argorithms in C++.
 *               These sorting algorithms are:
 *               	Bubble Sort
 *               	Optimized Bubble Sort
 *                Selection Sort
 *                InsertionSort
 *               This program uses command line macros during compilation
 *               For more information see line 128
 * Sources     : Luke Sathrum's Pseudocode (CSCI-21 Lecture slides PDFs)
 */

#ifndef SORT_ALG
  #pragma message("You must define SORT_ALG to be a sorting function")
  #error Read the comments/documentation inside the source code
#endif

#ifndef ARRAY
  #pragma message("You must define ARRAY to be the name of one of the arrays")
  #error Read the comments/documentation inside the source code
#endif

#include <iostream>
#include <algorithm> // includes the predefined swap function
#include <unistd.h>  // includes sleep();
#include <cstdlib>   // includes system();
using std::cout;
using std::cin;
using std::endl;
using std::swap;

/*
 * This function prints out an array
 * @param int array[] - the array to be printed out
 *                      can also be an int*
 * @param int size    - size of the array
 */
void PrintArray(int array[], int size) {
  for (int i = 0; i < (size - 1); i++) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << endl;
}

/*
 * This function performs the bubble sort and returns the sorted array
 * Loop through all the array indexes to the end
 * If the value is greater than the value at the next index, swap values
 * The largest values keep bubbling up to the top
 * The "end" does not consider the largest swapped values that are done
 * and so decrements, shifts down to the first index
 * Then the sorting algorithm ends.
 * @param int array[] - the array to be sorted
 *                      can also be an int*
 * @param int size    - size of the array
 */
void BubbleSort(int array[], int size) {
  unsigned int counter = 0;
  for (int i = (size - 1); i >= 1; i--) {
    for (int j = 0; j <= (i - 1); j++) {
      sleep(4); // takes seconds
      cout << "Try " << ++counter << ":\n";
      cout << "Value of i: " << i << endl;
      cout << "Value of j: " << j << endl;
      PrintArray(array, size);
      cout << endl;
      if (array[j] > array[j + 1])
        swap(array[j], array[j + 1]); // #include <algorithm>
    }
  }
}

/*
 * This is basically an optimized version of the bubble sort
 * The sorted array is returned
 * The next go is not started if the array is already sorted
 * Breaks out of the loop and returns the sorted array
 * This approach saves time.
 * @param int array[] - the array to be sorted
 *                      can also be an int*
 * @param int size    - size of the array
 */
void BubbleSortOptimized(int array[], int size) {
  unsigned int counter = 0;
  bool swapped;
  for (int i = (size - 1); i >= 1; i--) {
    // set swapped to false at the start of each go
    swapped = false;
    for (int j = 0; j <= (i - 1); j++) {
      sleep(4); // takes seconds
      cout << "Try " << ++counter << ":\n";
      cout << "Value of i: " << i << endl;
      cout << "Value of j: " << j << endl;
      PrintArray(array, size);
      cout << endl;
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]); // #include <algorithm>
        swapped = true;
      }
    }
    // if we haven't swapped in this go, that means the array is already sorted
    if (!swapped)
      break;
  }
}

/*
 * This is the selection sort.
 * It starts at the beginning of the array and goes through it,
 * searching for the absolute smallest value and saves its index.
 * And if at the end of each iteration, the index of the smallest value
 * is not the index of the beginning, meaning that the smallest value is not
 * where it is supposed to be, it swaps the values. 
 * And each iteration, it ignores the smallest value at the front that is
 * already sorted, so the beginning is incremented over one.
 * @param int array[] - the array to be sorted
 *                      can also be an int*
 * @param int size    - size of the array
 */
void SelectionSort(int array[], int size) {
  unsigned int counter = 0;
  int i, smallest;
  for (i = 0; i <= (size - 1); i++) {
    smallest = i;
    for (int j = (i + 1); j <= (size - 1); j++) {
      sleep(4); // takes seconds
      if (array[j] < array[smallest])
        smallest = j;
      cout << "Try " << ++counter << ":\n";
      cout << "Value of i: " << i << endl;
      cout << "Value of j: " << j << endl;
      cout << "Index of smallest: " << smallest << endl;
      PrintArray(array, size);
      cout << endl;
    }
    if (smallest != i)
      swap(array[i], array[smallest]); // #include <algorithm>
  }
}

/*
 * This is the insertion sort.
 * Just like the selection sort, it moves the smallest value to the beginning.
 * Each iteration, i increments, and if the next value is less than the
 * previous one, the inner while loop moves it to the beginning.
 * Then i increments to ignore the already sorted lowest value.
 * @param int array[] - the array to be sorted
 *                      can also be an int*
 * @param int size    - size of the array
 */
void InsertionSort(int array[], int size) {
  unsigned int counter = 0;
  for (int i = 0; i <= (size - 1); i++) {
    int j = i; // the compiler is smart enough not to recreate j each iteration
    while ((j > 0) && (array[j] < array[j - 1])) {
      sleep(4); // takes seconds
      cout << "Try " << ++counter << ":\n";
      cout << "Value of i: " << i << endl;
      cout << "Value of j: " << j << endl;
      PrintArray(array, size);
      cout << endl;
      swap(array[j], array[j - 1]);
      j = j - 1;
    }
  }
}

/*
 * The shell sort compares two pairs of numbers and swaps them if out of order.
 * The variable gap is set to the size of the array integer divided by 2
 * This determines the number of first pairs to be sorted
 * and the distance between them.
 * The variable i is set to the index of the second element
 * The variable temp holds the value of the second element
 * Inner while loop with the j checks if the first element in the pair
 * is greater than the second (means they are out of order) and if so,
 * sets the value of the second element to the value of the first element
 * and sets the value of the first element to temp (value of second element)
 * If they are not out of order, the inner while loop is not entered and
 * the second element in the pair is assigned to temp, or itself (redundant)
 * The gaps continue dividing by 2 to swap every possible pair, eventually
 * coming to a gap of 1 and checking every consecutive pair, and after that
 * gap becomes 0 so the loop (sorting process) ends and the array is sorted.
  * @param int array[] - the array to be sorted
 *                      can also be an int*
 * @param int size    - size of the array
 */
 void ShellSort(int array[], int size) {
   int gap = size / 2;
   unsigned int iteration = 0;
   cout << "Before loop" << endl;
   while (gap > 0) {
     //cout << "gap: " << gap;
     for (int i = gap; i <= (size - 1); i++) {
       //cout << "\ti: " << i << endl;
       int temp = array[i];
       int j = i;
       while ((j >= gap) && (array[j - gap] > temp)) {
         array[j]  = array[j - gap];
         cout << "swap" << endl;
         j -= gap;
       }
       array[j] = temp;
       cout << "Try " << ++iteration << ":\n";
       cout << "Gap\ti\tj\n";
       cout << gap << '\t' << i << '\t' << j << '\n';
       PrintArray(array, size);
       cout << endl;
     }
     gap = gap / 2;
   }
 }

int main() {
  // one of the arrays presented by Luke Sathrum
  // let the compiler determine size of the array
  int array1[] = {24, 13, 9, 64, 7, 23, 34, 47};

  // an already sorted array!
  int array2[] = {1, 2, 5, 8, 10, 15, 20, 25, 30};

  // a reverse sorted array!
  int array3[] = {75, 50, 45, 30, 25, 18, 17, 12, 10, 6, 5};

  // another array presented by Luke Sathrum
  int array4[] = {7, 2, 1, 5, 3};

  // the third array presented by Luke Sathrum
  int array5[] = {34, 17, 23, 35, 45, 9, 1};

  /*
   * This code uses command line macros defined by g++
   * SORT_ALG should be one of the sorting function names such as:
   *   BubbleSort
   *   BubbleSortOptimized
   *   SelectionSort
   *   InsertionSort
   * ARRAY should be the name of one of the arrays, without the brackets:
   *   array1
   *   array2
   *   array3
   *   array4
   *   array5
   * Example of compiling the program with g++ using command line macros:
   *   g++ -D SORT_ALG=BubbleSort -D ARRAY=array1 sorting.cpp
   */
  SORT_ALG(ARRAY, sizeof(ARRAY) / sizeof(ARRAY[0]));
  cout << "The sorted array: ";
  PrintArray(ARRAY, sizeof(ARRAY) / sizeof(ARRAY[0]));
  cout << endl;

  return 0;
}
