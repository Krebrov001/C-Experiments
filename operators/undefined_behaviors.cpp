#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;


void foo(int a, int b)
{
  cout << "  a: " << a << endl;
  cout << "  b: " << b << endl;
}


int main()
{
  int i = 1;
  cout << "i: " << i << endl;
  foo(i++, i++);
  cout << "i: " << i << endl;

  printf("%d += 2 : %d\n", i, i += 2);

  return 0;
}
