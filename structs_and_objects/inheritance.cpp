#include <iostream>
#include <cmath>
using namespace std;

class Shape {
  protected:
    char area_color;
    char line_color;
    int  line_width;
    int  area;
  public:
    Shape(char area_color, char line_color, int line_width)
    : area_color(area_color), line_color(line_color), line_width(line_width)
    {
      cout << "Shape constructor called" << endl;
    }
    virtual ~Shape() {
      cout << "Shape destructor called" << endl;
    }

    virtual int returnArea() = 0;
};


class Triangle : public Shape {
  private:
    int base;
    int height;
  public:
    Triangle(char area_color, char line_color, int line_width, int base, int height)
    : Shape(area_color, line_color, line_width), base(base), height(height)
    {
       cout << "Triangle constuctor called" << endl;
    }

    virtual ~Triangle()
    {
      cout << "Triangle destructor called" << endl;
    }

    virtual int returnArea() {
      return (base * height) / 2;
    }
};


class Circle : public Shape {
  private:
    int radius;
  public:
    Circle(char area_color, char line_color, int line_width, int radius)
    : Shape(area_color, line_color, line_width), radius(radius)
    {
       cout << "Circle constuctor called" << endl;
    }

    virtual ~Circle()
    {
      cout << "Circle destructor called" << endl;
    }

    virtual int returnArea() {
      return M_PI * radius * radius;
    }
};


int main()
{
/*
    // Example 1:
    Triangle equilateral('r', 'b', 2, 4, 8);
    Circle round('r', 'b', 2, 10);

    // Example 2:
    Shape* ptr = &equilateral;
    cout << "area: " << ptr->returnArea() << endl;
    Shape* ptr3 = &round;
    cout << "area: " << ptr3->returnArea() << endl;
*/

    // Example 3:
    Shape* ptr2 = new Triangle('r', 'b', 2, 4, 8);
    delete ptr2;

    // Example 4:
    Shape newshape('r', 'b', 2);
    cout << "area: " << newshape.returnArea() << endl;
    return 0;
}
