// Here, no overloaded assignment operator is defined either, but that does
// not matter, since on line 61, we have initialization, not assignment.
// And because there is no overloaded copy constructor defined, the compiler
// generates the default copy constructor, which just does a shallow copy.
// We have several problems here:
// 1. When t2 gets destroyed inside the enclosing scope, t1's ptr is no
//    longer valid (line 63)
// 2. t1 tries to access/print data which has already been freed (line 65)
// 3. When t1 gets destroyed at the end of the main() function, we have
//    a double free bug (line 67)
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
