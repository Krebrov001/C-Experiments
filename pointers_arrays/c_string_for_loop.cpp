#include <cstdlib>   // for malloc(), free()
#include <cstring>   // for strdup()
#include <iostream>
using namespace std;

void upperString(char* t, const char* s)
{
    for (; *s != '\0'; *(t++) = toupper(*(s++)))
        ;

    *(t++) = '\0';
}

int main()
{
    // strdup returns char*
    char* const a = strdup("hello");
    // malloc returns void*
    char* const b = static_cast<char*>( malloc(6 * sizeof(char)) );
    upperString(b, a);
    cout << a << endl;
    cout << b << endl;
    free(a);
    free(b);

    return 0;
}
