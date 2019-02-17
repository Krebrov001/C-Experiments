/*
 * Name        : variables_limits.c
 * Author      : Konstantin Rebrov
 * Description : Example of using the limits.h header file in the C standard library.
 *               This program displays information about the size and range of values for different C data types in green!
 * Sources     : https://stackoverflow.com/a/8249232/5500589
 *               http://www.geeksforgeeks.org/system-call-in-c/
 *               https://stackoverflow.com/a/23657072/5500589
 */

#include <stdio.h>    // includes printf() and scanf()
#include <limits.h>   // includes macros defining the limit values of data types
#include <stdlib.h>   // includes system()
#include <wchar.h>    // includes wchar_t data type
#include <stdint.h>   // includes [u]intX_t data types
#include <stdbool.h>  // stdbool.h defines bool, true, and false to be used in C programs.
#ifdef _WIN32
  #include <windows.h>  // for changing the properties of the windows console
#endif

// for linux: defines the color constants
#ifdef __linux__
  #define FGD_GRN "\x1B[32m"
  #define RESET   "\x1B[0m"
  #define BRIGHT  "\x1B[1m"
#endif

// This is the main method of the program.
// The program starts here at runtime.
int main() {
  // clears the screen and prints a newline
  #ifdef __linux__
    system("clear");
  #endif
  #ifdef _WIN32  // both 32 and 64 bit
    system("cls");
  #endif
  printf("\n");

  // for windows: saves the default console settings
  #ifdef _WIN32  // both 32 and 64 bit
    // grab a handle to the console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    // save current attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
  #endif
  
  // sets the color of the output text to bright green
  #ifdef __linux__
    printf(FGD_GRN);
    printf(BRIGHT);
  #endif
  #ifdef _WIN32
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  #endif

  printf("There are %i bits in a byte.\n", CHAR_BIT);

  // sets the color of the output text to plain green
  #ifdef __linux__
    printf(RESET);
    printf(FGD_GRN);
  #endif
  #ifdef _WIN32
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  #endif

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the char data types
  // sizeof() returns a long int
  printf("  Size of signed char:    %2li bytes = %3li bits\n", sizeof(signed char), sizeof(signed char) * CHAR_BIT);
  printf("  Size of unsigned char:  %2li bytes = %3li bits\n", sizeof(unsigned char), sizeof(unsigned char) * CHAR_BIT);
  printf("  Size of wchar_t:        %2li bytes = %3li bits\n", sizeof(wchar_t), sizeof(wchar_t) * CHAR_BIT);
  // print the limit values for the char data types
  printf("  Minimum char value:          %+4i\n", CHAR_MIN);
  printf("  Maximum char value:          %+4i\n", CHAR_MAX);
  printf("  Minimum signed char value:   %+4i\n", SCHAR_MIN);
  printf("  Maximum signed char value:   %+4i\n", SCHAR_MAX);
  printf("  Minimum unsigned char value: %4u\n", 0);
  printf("  Maximum unsigned char value: %4u\n", UCHAR_MAX);
  // this code determines if char is signed or unsigned
  if (CHAR_MIN == SCHAR_MIN && CHAR_MAX == SCHAR_MAX) {
    printf("  char data type is signed\n");
  } else if (CHAR_MIN == 0 && CHAR_MAX == UCHAR_MAX) {
    printf("  char data type is unsigned\n");
  }
  printf("  Maximum number of bytes in a multi-byte characer: %i\n\n", MB_LEN_MAX);

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the short int data types
  // sizeof() returns a long int
  printf("  Size of signed short int:    %2li bytes = %3li bits\n", sizeof(signed short int), sizeof(signed short int) * CHAR_BIT);
  printf("  Size of unsigned short int:  %2li bytes = %3li bits\n", sizeof(unsigned short int),
  sizeof(unsigned short int) * CHAR_BIT);
  // print the limit values for the short int data types
  printf("  Minimum signed short int value:   %+6i\n", SHRT_MIN);
  printf("  Maximum signed short int value:   %+6i\n", SHRT_MAX);
  printf("  Minimum unsigned short int value: %6u\n", 0);  // 0 is an unsigned value for consistency
  printf("  Maximum unsigned short int value: %6u\n", USHRT_MAX);
  printf("\n");

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the int data types
  // sizeof() returns a long int
  printf("  Size of signed int:    %2li bytes = %3li bits\n", sizeof(signed int), sizeof(signed int) * CHAR_BIT);
  printf("  Size of unsigned int:  %2li bytes = %3li bits\n", sizeof(unsigned int), sizeof(unsigned int) * CHAR_BIT);
  // print the limit values for the int data types
  printf("  Minimum signed int value:   %+11i\n", INT_MIN);
  printf("  Maximum signed int value:   %+11i\n", INT_MAX);
  printf("  Minimum unsigned int value: %11u\n", 0);
  printf("  Maximum unsigned int value: %11u\n", UINT_MAX);
  printf("\n");

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the long int data types
  // sizeof() returns a long int
  printf("  Size of signed long int:    %2li bytes = %3li bits\n", sizeof(signed long int), sizeof(signed long int) * CHAR_BIT);
  printf("  Size of unsigned long int:  %2li bytes = %3li bits\n", sizeof(unsigned long int),
  sizeof(unsigned long int) * CHAR_BIT);
  // print the limit values of the long int data types
  printf("  Minimum signed long int value:   %+20li\n", LONG_MIN);
  printf("  Maximum signed long int value:   %+20li\n", LONG_MAX);
  printf("  Minimum unsigned long int value: %20u\n", 0);
  printf("  Maximum unsigned long int value: %20lu\n", ULONG_MAX);
  printf("\n");

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the long long int data types
  // sizeof() returns a long int
  printf("  Size of signed long long int:    %2li bytes = %3li bits\n", sizeof(signed long long int),
  sizeof(signed long long int) * CHAR_BIT);
  printf("  Size of unsigned long long int:  %2li bytes = %3li bits\n", sizeof(unsigned long long int),
  sizeof(unsigned long long int) * CHAR_BIT);
  printf("\n");

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of the standard int data types
  printf("  Size of int8_t:    %2li bytes = %3li bits\n", sizeof(int8_t), sizeof(int8_t) * CHAR_BIT);
  printf("  Size of uint8_t:   %2li bytes = %3li bits\n", sizeof(uint8_t), sizeof(uint8_t) * CHAR_BIT);
  printf("  Size of int16_t:   %2li bytes = %3li bits\n", sizeof(int16_t), sizeof(int16_t) * CHAR_BIT);
  printf("  Size of uint16_t:  %2li bytes = %3li bits\n", sizeof(uint16_t), sizeof(uint16_t) * CHAR_BIT);
  printf("  Size of int32_t:   %2li bytes = %3li bits\n", sizeof(int32_t), sizeof(int32_t) * CHAR_BIT);
  printf("  Size of uint32_t:  %2li bytes = %3li bits\n", sizeof(uint32_t), sizeof(uint32_t) * CHAR_BIT);
  printf("  Size of int64_t:   %2li bytes = %3li bits\n", sizeof(int64_t), sizeof(int64_t) * CHAR_BIT);
  printf("  Size of uint64_t:  %2li bytes = %3li bits\n", sizeof(uint64_t), sizeof(uint64_t) * CHAR_BIT);
  printf("\n");

  // prints a line separator
  printf("============================\n\n");

  // print the sizes of other data types
  printf("  Size of bool:         %2li bytes = %3li bits\n", sizeof(bool), sizeof(bool) * CHAR_BIT);
  printf("  Size of float:        %2li bytes = %3li bits\n", sizeof(float), sizeof(float) * CHAR_BIT);
  printf("  Size of double:       %2li bytes = %3li bits\n", sizeof(double), sizeof(double) * CHAR_BIT);
  printf("  Size of long double:  %2li bytes = %3li bits\n", sizeof(long double), sizeof(long double) * CHAR_BIT);
  printf("  Size of pointer:      %2li bytes = %3li bits\n", sizeof(void*), sizeof(void*) * CHAR_BIT);
  printf("\n");

  // resets the color of the output text
  #ifdef __linux__
    printf(RESET);
  #endif
  #ifdef _WIN32
    SetConsoleTextAttribute(hConsole, saved_attributes);
  #endif
  
  return 0;
}

