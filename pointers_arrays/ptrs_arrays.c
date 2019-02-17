/*
 * Name             : ptrs_arrays.c
 * Title            : Pointers and arrays
 * Author           : Konstantin Rebrov
 * Created on       : 08 January 2017
 * Last modified on : 08 January 2017
 * Description      : This program demonstrates the close relationship between
 *                    pointers and arrays.
 * Sources          : https://www.youtube.com/watch?v=ASVB8KAFypk
 */

#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for EXIT_SUCCESS and system()

int main() {
  // a [signed] int takes up 4 bytes on Windows and Linux
  // Therefore, this array takes up 20 bytes.
  signed int nums[] = {2, 4, 5, 8, 1};  // compiler automatically allocates
                                        // enough memory space
  /*
  signed int nums[5];
  nums[0] = 2;
  nums[1] = 4;
  nums[2] = 5;
  nums[3] = 8;
  nums[4] = 1;
  */

  #ifdef _WIN32 // both 32 and 64 bit
    system("cls");
  #endif
  #ifdef __linux__
    system("clear");
  #endif

  /*
  printf(" Address of first array element: %p\n", nums);
  printf("   Value of first array element: %i\n", *nums);
  printf(" Address of second array element: %p\n", nums+1);
  printf("   Value of second array element: %i\n", *(nums+1));
  */

  printf("\n");

  /*
   * To get the number of elements in the array:
   * divide the total size of the array by the size of one element in the array
   */
  printf("There are %i elements in the array\n", sizeof(nums)/sizeof(nums[0]));
  printf("\n");

  for (unsigned int i = 0; i < sizeof(nums)/sizeof(*nums); i++) {
    printf("Address: %p=%p | ", &nums[i], (nums + i));
    printf("Value: %i=%i\n", nums[i], *(nums + i));
  }

  printf("\n");

  int* ptr = nums;  // int* ptr = &nums[0];
  printf("Array is: ");
  for (unsigned int i = 0; i < sizeof(nums)/sizeof(*nums); i++) {
    printf("%i ", *ptr);
    ptr++;
  }
  printf("\n\n");

  return EXIT_SUCCESS;
}
