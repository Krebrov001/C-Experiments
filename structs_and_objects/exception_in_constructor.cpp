#include <iostream>
using std::cout;
using std::endl;


class Date {
  public:
    Date(int d = 0, int m = 0, int y = 0)
    : day{d}, month{m}, year{y}
    {
        cout << "The constructor is called." << endl;
	throw "Bad Boy";
    }

    ~Date()
    {
        cout << "The destructor is called." << endl;
    }

    void printMe()
    {
        cout << month << '/' << day << '/' << year << endl;
    }
  private:
    int day;
    int month;
    int year;
};


int main()
{
    try {
        Date dt;  // This object gets destroyed at the }
    } catch (...) {
        cout << "Exception caught!" << endl;
    }

    cout << "After exception hangling statement." << endl;

    //dt.printMe();

    return 0;
}
