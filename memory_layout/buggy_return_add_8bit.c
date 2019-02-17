/*
 * Name        : add_8bit.c
 * Author      : Konstantin Rebrov
 * Date        : 05/27/2017
 * Language    : C
 * Description : The user is prompted to enter two byte-sized (8-bit) binary
 *               numbers. The program adds these two numbers together using
 *               logic gates and displays the result on the screen.
 */

#include <stdio.h>
#include <string.h>   // includes strlen()
#include <stdbool.h>  // includes bool values
#include <stdlib.h>   // inclues EXIT_SUCCESS

/*
 * This function reads in a byte-sized binary number, performs input
 * validation, and asks the user to input a new 8-bit value if the previous
 * value was not valid.
 * @return char* - a char pointer (c-string) containing the binary value
 *
 * FIXME: Update - I checked this code on 05/31/2018
 * This function returns a char*
 * The problem is that byte is a char array (or C-string) which is stored on the stack frame for that function.
 * When the function returns, the pointer to the base of the C-string is returned, (placed into the RAX/EAX register).
 * Then the function's stack frame is cleared off the stack.
 * This is a problem, because the char pointer is pointing to data in a section of memory that was cleared off
 * the stack. The next function call may wipe out that stack frame.
 */
char* ReadByte() {
  char byte[9];  /* the individual "bits" are stored as chars */

  retry:
  printf("start scanning\n");
  scanf("%s", byte);  /* %s means (c-)string */
  /* The second argument is the address of the variable into which to read
   * user input. The name of the char array is a pointer to the first memory
   * location.
   */

  printf("%s, %d\n", byte, strlen(byte));
  // This code checks if every value in the byte is a valid bit.
  if (strlen(byte) != 8) {
    printf("bad size\n");
    printf("\nThe value entered should be a binary number\n");
    printf("Please try again: ");
    goto retry;
  }
  bool bit_is_good = true;
  for (int i = 0; i < 8; i++) {
    printf("%c\n", byte[i]);
    if ((byte[i] != '0') && (byte[i] != '1')) {
      printf("bad bit\n");
      bit_is_good = false;
      break;
    }
  }
  printf("break out of loop\n");
  if (!bit_is_good) {
    printf("\nThe value entered should be a binary number\n");
    printf("Please try again: ");
    goto retry;
  }

  printf("skip goto\n");
  return byte;
}

int main() {
  printf("Please enter a byte-sized (8-bit) binary number: ");
  char* byte = ReadByte();
  printf("%s\n", byte);
  return EXIT_SUCCESS;
}

