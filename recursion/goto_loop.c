#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  // for true, false, and bool data type in C Programming Language!


int fact1(int n)
{
    int i = 2;
    int result = 1;

    loop:
        if (!(i <= n)) {
	    //break;
	    goto end;
	} else {
            result = result * i;
	    i = i + 1;
	    goto loop;
	}
    end:

    return result;
}


int fact2(int n)
{
    int i = 2;
    int result = 1;

    while (true) {
        if (!(i <= n)) {
	    break;
	} else {
	    result = result * i;
	    i = i + 1;
	}
    }

    return result;
}


int fact3(int n, int i)
{
    if (!(i <= n)) {
        return 1;
    } else {
        return i * fact3(n, i + 1);
    }
}


int main(void)
{
    int x = 0;
    printf("Enter an int value\n > ");
    scanf("%i", &x);
    printf("%i! = %i\n", x, fact1(x));
    printf("%i! = %i\n", x, fact2(x));
    printf("%i! = %i\n", x, fact3(x, 2));

    return EXIT_SUCCESS;
}
