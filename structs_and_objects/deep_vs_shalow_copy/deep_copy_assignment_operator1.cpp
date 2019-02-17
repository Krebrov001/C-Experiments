// Here, we defined the overloaded assignment operator as a member function
// of the class Test.
// The overloaded assignment operator does a deep copy, but does not change
// the id of the object to uniquely identify that object in the output.
// Now the code works as expected.
#include <iostream>

using std::cout;
using std::endl;


class Test {
  public:
    Test() : ptr{new int(0)}, val{0}, id{count++} {}

    Test(int ptr_val, int new_val) : ptr{new int(ptr_val)}, val{new_val}, id{count++} {}

    ~Test()
    {
        delete ptr;
    }

    Test& operator=(const Test& rhs)
    {
        *ptr = *(rhs.ptr);
	val = rhs.val;
    }

    void setPtrVal(int ptr_val)
    {
        *ptr = ptr_val;
    }

    void setVal(int new_val)
    {
        val = new_val;
    }

    void printData() const
    {
	cout << "id  = " << id  << endl;
        cout << "val = " << val << endl;
	cout << "ptr = " << ptr << endl;
	cout << "*ptr = " << *ptr << endl << endl;
    }
  private:
    int* ptr;
    int val;
    int id;

    static int count;
};

int Test::count = 1;


int main()
{
    Test t1;
    Test t2(2, 2);

    t1.printData();
    t2.printData();

    t2 = t1;  // Overloaded assignment operator
    t1.printData();
    t2.printData();

    t2.setVal(3);
    t2.setPtrVal(3);

    t1.printData();
    t2.printData();

    return 0;
}
