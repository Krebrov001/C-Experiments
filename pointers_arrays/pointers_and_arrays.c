/*
 * Name             : pointers_and_arrays.c
 * Author           : Konstantin Rebrov
 * Created on       : 08/19/2017
 * Last modified on : 12/21/2017
 * Language         : C
 * Description      : This program tests out the relationship between pointers and arrays
 * Sources          : https://www.youtube.com/watch?v=CpjVucvAc3g&index=7&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
 *                    https://www.youtube.com/watch?v=5tPLyHCZdU0
 */

#include <stdio.h> // C standard input/output

int main() {

  int array[5]; // allocates memory for an array of 5 integers
  array[0] = 5;
  array[1] = 8;
  array[2] = 2;
  array[3] = 6;
  array[4] = 7;

  /*
  char array[5]; // allocates memory for an array of 5 characters
  array[0] = 'A';
  array[1] = 'B';
  array[2] = 'C';
  array[3] = 'D';
  array[4] = 'E';
  */

  int total_length = sizeof(array);  // gets the size of the whole array in bytes
  printf("The  whole array takes up %d bytes\n", total_length);
  int num_size = sizeof(array[0]);  // gets the size of the first element in the array in bytes
  printf("An element of the array takes up %d bytes\n", num_size);
  int num_array_elements = total_length / num_size;
  printf("There are %d elements in the array\n", num_array_elements);
  printf("\n");
  
  printf("Address of first element (base address): %p\n", array);
  printf("Value of first element: %d\n", *array);
  printf("Value of first element: %d\n", array[0]);
  printf("Address of second element: %p\n", array + 1);
  printf("Value of second element: %d\n", *(array + 1));
  printf("Value of second element: %d\n", array[1]);
  printf("\n");

  for (int i = 0; i < num_array_elements; i++) {
    printf("%d : %d\n", i, array[i]);
  }
  printf("\n");

  for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
    printf("%d : %d\n", i, *(array + i));
  }
  printf("\n");

  return 0;
}

