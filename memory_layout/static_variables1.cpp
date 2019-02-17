#include <iostream>
using namespace std;

// Macro to print out a variable/expression and it's value.
#define PRINT(x) cout << #x" = " << x << endl;

int global1;
int global2 = 0;
int global3 = 1;

static int static1;
static int static2 = 0;
static int static3 = 2;

class myClass {
  public:
    int a;
    static int static4;
    static int static5;
};

int myClass::static4;
int myClass::static5 = 5;

int main()
{
    myClass object;

    static int static6;
    static int static7 = 7;

    PRINT(&global1);
    PRINT(&global2);
    PRINT(&global3);
    PRINT(&static1);
    PRINT(&static2);
    PRINT(&static3);
    PRINT(&myClass::static4);
    PRINT(&myClass::static5);
    PRINT(&static6);
    PRINT(&static7);

    return 0;
}
