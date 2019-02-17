#include <iostream>
using namespace std;


class Car {
  public:
    Car() : ID(counter++)
    {
        cout << "Car " << ID << "created" << endl;
    }

    ~Car()
    {
        cout << "Car " << ID << "destroyed" << endl;
    }
  private:
    int ID;
    static int counter;
};

int Car::counter = 1;


int main()
{
    Car car1;
    {
        Car car2;
    }
    Car car3;

    return 0;
}
