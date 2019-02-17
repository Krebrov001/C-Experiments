#include <iostream>
#include <string>
using namespace std;


class temp {
 public:
  temp() { cout << "constructor" << endl; }
  ~temp() { cout << "destructor" << endl; }
};


int main()
{
    cout << string(8, '-') << endl;
    temp();
    cout << string(50, '-').size() << endl;
    string* a = &string(20, 'a');
    cout << *a << endl;

    return 0;
}
