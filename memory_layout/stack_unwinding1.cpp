#include <iostream>
using namespace std;

class Car {
  public:
    Car()
    {
        ID = counter++;
        cout << "Car " << ID << " created." << endl;
    }

    ~Car()
    {
        cout << "Car " << ID << " destroyed." << endl;
    }
  private:
    static int counter;

    int ID;
};

int Car::counter = 1;


int main()
{
    Car car1;

    Car car2;

    Car car3;

    Car car4;

    return 0;
}
