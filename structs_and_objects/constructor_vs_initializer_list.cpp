#include <iostream>
using namespace std;

class Rectangle {
  public:
    //Rectangle() : x(5), y(6), width(7), height(8) {}
    Rectangle() = delete;

    void printMe()
    {
        cout << "The rectangle is located at (" << x << ',' << y << ") and is " << width << " x " << height << endl;
    }
    double x;
    double y;
    double width;
    double height;
};


int main()
{
    Rectangle r = {0.0, 0.0, 3.0, 4.0};
    r.printMe();

    //Rectangle s;  // uninitialized!
    //s.printMe();
}

