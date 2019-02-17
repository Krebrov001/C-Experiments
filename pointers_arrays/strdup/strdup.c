#include "strdup.h"

char* strdup(const char* s)
{
    /* Count the length of the c-string s. */
    /* Do it manually so that we don't have to include strlen. */
    /* strlen is in string.h, which also contains it's own version of strdup we are trying to replace. */
    size_t numchars = 0;
    const char* s1 = s;
    for (; *s1 != '\0'; ++s1, ++numchars)
        ;

    ++numchars;
    /* Repurpose s1 to point to the dynamically allocated array. */
    s1 = malloc(numchars * sizeof(char));
    /* Set the source pointing to the original c-string. */
    const char* source = s;
    /* Set the dest pointing to the dynamically allocated array. */
    char* dest = s1;

    /* Copy all the characters. */
    for (; *source != '\0'; *(dest++) = *(source++))
        ;

    /* Put a '\0' at the end of the destination string. */
    *(dest++) = '\0';

    return s1;
}
