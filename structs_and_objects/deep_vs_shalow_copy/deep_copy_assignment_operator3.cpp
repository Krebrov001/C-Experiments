// Because the overloaded copy constructor was created here,
// we have a deep copy, not a shallow copy.
// We don't have problems such as accessing already freed memory or
// double free due to more than one pointer pointing to the same
// memory location.
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

    Test(const Test& rhs) : ptr{new int( *(rhs.ptr)  )}, val{rhs.val}, id{count++}
    {
        cout << "copy constructor called" << endl;
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
    Test t1(10, 15);

    {
        Test t2 = t1;
        t2.printData();
    }

    t1.printData();

    return 0;
}
