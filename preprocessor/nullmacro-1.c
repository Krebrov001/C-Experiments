/*
 * Name        : nullmacro-1.c
 * Author      : Konstantin Rebrov
 * Date        : 04/13/2017
 * Language    : C
 * Description : This program is an improved version of nullmacro.c
 *               The user is prompted to enter the name of a file, and fp tries to open it
 * Sources     : TutorialsPoint C Standard Library Page 91
 */

#include <stddef.h>  //includes NULL
#include <stdio.h>

int main()
{

  FILE *fp;
  /* 100 chars just in case the user enters a long filename on the terminal */
  char filename[100];

  printf("Enter a filename to open: ");
  /* warning: the `gets' function is dangerous and should not be used. */
  gets(filename);

  fp = fopen(filename, "r");
  if ( fp != NULL )
  {
    printf("Opend file %s successfully\n", filename);
    fclose(fp);
  }
  else
  {
    printf("Could not open file %s\n", filename);
  }

  return(0);

}  
