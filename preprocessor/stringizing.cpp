#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

#define VARNAME(x) #x
#define VARTYPE(x) typeid(x).name()

#define EVAL_VAR(x) cout << VARTYPE(x) << " " << VARNAME(x) << " = " << x << endl;

int main() {
  int    a = 19;
  double b = 27.3;
  char   c = 'A';
  string name = "Konstantin Rebrov";

  EVAL_VAR(a);
  EVAL_VAR(b);
  EVAL_VAR(c);
  EVAL_VAR(a + b);
  EVAL_VAR(a + c);
  EVAL_VAR(b + c);
  EVAL_VAR(name);

  return 0;
}
