#include <iostream>
#include <cstdlib>  // C standard library - for EXIT_SUCCESS
#include <cmath>    // C math library - for INFINITY and HUGE_VALF
using std::cout;
using std::cin;
using std::endl;

int main() {
  float num1 = 540000000;
  float num2 = 5.4e8;
  float num3 = 5.4e+08;
  cout << num1 << ' ' << num2 << ' ' << num3 << endl;
  num1 = 0.000001;
  num2 = 1.0e-6;
  num3 = 1e-06;
  cout << num1 << ' ' << num2 << ' ' << num3 << endl;

  cout << endl;

  if ((12.0f / 0.0f) == INFINITY)
    cout << std::boolalpha << true << endl;

  if ((12.0f / 0.0f) == HUGE_VALF)
    cout << std::boolalpha << true << endl;

  if ((-12.0f / 0.0f) == -INFINITY)
    cout << std::boolalpha << true << endl;

  return EXIT_SUCCESS;
}
