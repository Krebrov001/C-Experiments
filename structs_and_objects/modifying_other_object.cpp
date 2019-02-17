#include <iostream>
using namespace std;

class Bucket {
  public:
    // Acts as constructor acceptint two arguments x and y,
    // one argument x,
    // or no arguments (default constructor).
    Bucket(int x = 0, int y = 0) : x(x), y(y) {}

    Bucket(const Bucket& rhs)
    {
        this->x = rhs.x;
	this->y = rhs.y;
    }

    void modifyOther(Bucket* other)
    {
        other->x = -1;
	other->y = 1;
    }

    void printInfo()
    {
        cout << "x = " << this->x << endl;
        cout << "y = " << this->y << endl;
	cout << endl;
    }
  private:
    int x;
    int y;
};


int main()
{
    Bucket a(10, 5);
    a.printInfo();

    Bucket b(8, 9);
    b.printInfo();

    a.modifyOther(&b);

    a.printInfo();
    b.printInfo();

    return 0;
}
