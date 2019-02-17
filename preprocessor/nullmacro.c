/*
 * Name        : nullmacro.c
 * Author      : Konstantin Rebrov
 * Date        : 04/13/2017
 * Language    : C
 * Description : This program demonstrates the usage of NULL Macro.
 *               file.txt must exist and nofile.txt must not exist.
 *               fp is set to NULL whenever it can't open a file
 *               (the file does not exist).
 * Sources     : TutorialsPoint C Standard Library Page 91
 */

#include <stddef.h>  //includes NULL
#include <stdio.h>

int main()
{

  FILE *fp;

  fp = fopen("file.txt", "r");
  if ( fp != NULL )
  {
    printf("Opend file file.txt successfully\n");
    fclose(fp);
  }

  fp = fopen("nofile.txt", "r");
  if ( fp == NULL )
  {
    printf("Could not open file nofile.txt\n");
  }

  return(0);

}  
