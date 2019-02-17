#include <stdio.h>   // C standard input/output
#include <stdlib.h>  // C standard library - for malloc(), free(), size_t

int main() {
  int a;  // goes on stack
  int* p;
  p = malloc(sizeof(int));  // allocate the size of an int on the heap and
                            // returns a pointer to that memory location
  *p = 10;  // saves 10 into the dynamic variable.
  printf("The value of the dynamic variable: %i\n", *p);
  printf("Some garbage value: %i\n", *(p + 1));
  free(p);  // deallocates the dynamic variable

  /* Now we will use the pointer to point to a dynamic array */
  size_t num_elements;
  printf("Enter the size of the dynamic array: ");
  scanf("%lu", &num_elements);
  p = malloc(num_elements * sizeof(int));

  // Print out the uninitialized dynamic array.
  for (size_t i = 0; i < num_elements; i++) {
    printf("The %luth element is: %d\n", (i + 1), p[i]);
  }
  printf("\n");

  // Input values for the dynamic array.
  for (size_t i = 0; i < num_elements; i++) {
    printf("Enter the %luth value: ", (i + 1));
    scanf("%d", (p + i));
  }

  // Print out the dynamic array to confirm that the values had been saved.
  for (size_t i = 0; i < num_elements; i++) {
    printf("The %luth element is: %d\n", (i + 1), p[i]);
  }

  free(p);  // deallocates the dynamic array

  return 0;
}
