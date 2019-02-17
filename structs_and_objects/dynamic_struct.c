#include <stdlib.h>  // for EXIT_SUCCESS
#include <stdio.h>   // for printf()

int main()
{
    struct S1 {
        char c;
	int i[2];
	double v;
    } *p = malloc( sizeof(struct S1) );

    p->c = 'a';
    p->v = 3.14;
    printf("%c\n", p->c);

    free(p);

    return EXIT_SUCCESS;
}
