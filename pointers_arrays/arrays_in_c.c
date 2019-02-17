/*
 * Arrays & Structs, Video 1: Arrays in C
 * https://www.youtube.com/watch?v=y2BAaD3fW8A&list=PL0oekSefhQVJdk0hSRu6sZ2teWM740NtL&index=33
 */

 #include <stdio.h>
 #include <stdlib.h>

/* Without the typedef, zip_dig would have been an actual array of 5 ints
 * on the paper.
 * The typedef turns it into a stamp of 5 ints.
 */
typedef int zip_dig[5];

#define PCOUNT 4 /* The number of 1-D arrays in the multidimensional array. */
#define UCOUNT 3 /* The number of 1-D arrays in the multi-level array. */

int zip2int_1(zip_dig z, int size) {
  int zi = 0;
  int i  = 0;
  for (i = 0; i < size; i++) {
    zi = zi * 10 + z[i];
  }

  return zi;
}

/**
 * Transforms an array of digits (ex: {1, 2, 3}) into a single int 123.
 * zip_dig z creates z as a zip_dig, an array of 5 ints.
 * However since arrays are passed by pointer, z is actually an int*
 * zlast contains the address of the last valid element in the array.
 * The pointer z traverses along the array until it goes out of bounds
 * of the last valid element in the array.
 * Each element into the array is stored into zi, then multiplied by 10
 * (similar to left shifting), and the next digit is added into the ones
 * collumn.
 */
int zip2int_2(zip_dig z, int size) {
  int zi = 0;
  int* zlast = z + (size - 1);
  do {
    zi = zi * 10 + *z;
    z++;
  } while (z <= zlast);

  return zi;
}

int main(void) {
  /* We can use zip_dig as a stamp,
     This creates cmu as a zip_dig, or an array of 5 ints all in one go.
   */
   zip_dig cmu = { 1, 5, 2, 1, 3 };
   zip_dig uw  = { 9, 8, 1, 9, 5 };
   zip_dig ucb = { 9, 4, 7, 2, 0 };

  printf("cmu: %d\n", zip2int_1(cmu, 5));
  printf("uw : %d\n", zip2int_1(uw, 5));
  printf("ucb: %d\n", zip2int_1(ucb, 5));

  printf("cmu: %d\n", zip2int_2(cmu, 5));
  printf("uw : %d\n", zip2int_2(uw, 5));
  printf("ucb: %d\n", zip2int_2(ucb, 5));

  printf("\n");

  /* We can use zip_dig as a stamp,
     sea is an array of 4 zip_dig "objects", where each zip_dig "object" is an array of 5 ints!
     We inititalize sea much like we do a regular 2-D array.
     It's really an array of 1-D arrays of 5 ints each.
   */
  zip_dig sea[PCOUNT] =
  { {9, 8, 1, 9, 5},
    {9, 8, 1, 0, 5},
    {9, 8, 1, 0, 3},
    {9, 8, 1, 1, 5} };

  printf("sea[0]: %d\n", zip2int_1(sea[0], 5));
  printf("sea[1]: %d\n", zip2int_1(sea[1], 5));
  printf("sea[2]: %d\n", zip2int_1(sea[2], 5));
  printf("sea[3]: %d\n", zip2int_1(sea[3], 5));

  printf("\n");

  /* univ is an array of 3 int pointers.
     having just the name of an array returns the base address of the array,
     or a pointer to the first element in the array.
     uw, cmu, and ucb are arrays of 5 integers each, so they are all int *'s.
     This is a multi-level array.
   */
  int* univ[UCOUNT] = {uw, cmu, ucb};

  printf("univ[0]: %d\n", zip2int_1(univ[0], 5));  /* uw  */
  printf("univ[1]: %d\n", zip2int_1(univ[1], 5));  /* cmu */
  printf("univ[2]: %d\n", zip2int_1(univ[2], 5));  /* ucb */

  printf("\n");

  return EXIT_SUCCESS;
}
