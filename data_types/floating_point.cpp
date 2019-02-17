#include <iostream> // C++ input/output - for cout and endl
#include <cstdlib>  // C standard library - for EXIT_SUCCESS, EXIT_FAILURE
#include <cmath>    // C math library - for INFINITY, NAN, HUGE_VALF, M_PI, M_E
#include <cfloat>   // C float library - for FLT_MAX, FLT_MIN
#include <cstdio>   // C standard input/output - for printf(), scanf()
using std::cout;
using std::endl;

int main() {
  float a = 2.75;
  int i = *(int *) &a;
  cout << a << endl;
  cout << i << endl << endl;

  i = 4286578689;
  a = *(float*) &i;
  cout << i << endl;
  cout << a << endl;

  a = INFINITY;
  i = *(int*) &a;
  cout << a << endl;
  cout << i << endl;

  a = NAN;
  i = *(int*) &a;
  cout << a << endl;
  cout << i << endl;

  a = HUGE_VALF;
  i = *(int*) &a;
  cout << a << endl;
  cout << i << endl;

  a = M_PI;
  i = *(int*) &a;
  cout << a << endl;
  cout << i << endl;

  a = 0.1;
  i = *(int*) &a;
  cout << a << endl;
  cout << i << endl;

  a = FLT_MAX;
  i = *(int*) &a;
  cout << a << endl;
  printf("%#x\n", i);
  printf("%#010x\n", i);

  a = FLT_MIN;
  i = *(int*) &a;
  cout << a << endl;
  printf("%#x\n", i);
  printf("%#010x\n", i);

  i = 37;
  a = *(float*) &i;
  cout << a << endl;

  cout << endl;

  int num = 0x0f050904;
  cout << num << endl;

  return EXIT_SUCCESS;
}

