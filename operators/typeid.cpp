#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;


int main() {
  int a = 9;
  double b = 3.14;
  float e = 2.74;
  char c = 'T';
  string Register = "eax";

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(e).name() << endl;
  cout << typeid(c).name() << endl;
  cout << typeid(Register).name() << endl;

  return 0;
}
