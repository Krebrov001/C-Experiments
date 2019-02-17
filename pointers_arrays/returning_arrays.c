#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

#include "returning_arrays.h"

struct String {
  char buffer[SIZE];
};

int main(void)
{

  #ifdef PTR_TO_LOCAL_ARRAY

    char* word = ptr_to_local_array();

  #elif defined(STRING_LITERAL)

    char* word = string_literal();

  #elif defined(PTR_TO_GLOBAL_ARRAY)

    char* word = ptr_to_global_array();

  #elif defined(PTR_TO_STATIC_ARRAY)

    char* word = ptr_to_static_array();

  #elif defined(PTR_TO_MALLOC_ARRAY)

    char* word = ptr_to_malloc_array();

  #elif defined(FILL_DYNAMIC_ARRAY)

    char* word = malloc(sizeof(char) * SIZE);
    fill_dynamic_array(word, SIZE);

  #elif defined(STRUCT_BY_VALUE)

    struct String myWord = struct_by_value();
    word = &myWord.buffer;

  #else

    #error None of the macros were declared!
    #pragma message("Please define one a macro to activate a function.")

  #endif

    printf("%s\n", word);

  #ifdef PTR_TO_MALLOC_ARRAY
    free(word);
  #endif

  #ifdef FILL_DYNAMIC_ARRAY
    free(word);
  #endif
    
    return EXIT_SUCCESS;
}
