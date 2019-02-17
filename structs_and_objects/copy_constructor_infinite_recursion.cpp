#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Dog {
  public:
    Dog(int num) : value(num) {
        cout << "Dog gets constructed with " << value << endl;
    }

    Dog(Dog dog) {
        cout << "Copy constructor!" << endl;
    }
  private:
    int value;
};


int main()
{
    Dog d1(5);

    Dog d2(d1);

    return 0;
}
