#ifndef M_D_ARRAY_H
#define M_D_ARRAY_H

#if defined(__cplusplus)
  #include <cstddef>
  extern "C" {
#else
  #include <stddef.h>
#endif

/**
 * These functions print the contents of the array to stdout:
 *
 * These functions work with a:
 * 1-D array
 * 2-D array
 * 3-D array
 *
 * @param p - A pointer p to the first element in the array,
 *            the data is const, which means that the internal contents of the array cannot be modified.
 * @param size_t size - The number of elements in the multidimensional array itself.
 */
void print1Darray(const int p[],       size_t size);
void print2Darray(const int p[][3],    size_t size);
void print3Darray(const int p[][2][2], size_t size);

/**
 * These functions set all ints in the array to newVal.
 *
 * These functions work with a:
 * 1-D array
 * 2-D array
 * 3-D array
 *
 * @param p - A pointer p to the first element in the array,
 *            the internal contents of the array can be modified
 * @param size_t size - The number of elements in the multidimensional array itself.
 * @param int newVal - All the ints in the array are set to this number
 */
void edit1Darray(int* p,         size_t size, int newVal);
void edit2Darray(int (*p)[3],    size_t size, int newVal);
void edit3Darray(int (*p)[2][2], size_t size, int newVal);

#if defined(__cplusplus)
  }
#endif

#endif /* M_D_ARRAY_H */

