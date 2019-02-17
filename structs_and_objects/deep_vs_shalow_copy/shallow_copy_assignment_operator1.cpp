// The problem here is that there is no overloaded assignment operator here,
// so a shallow copy is done.
// We have the following problems:
// 1. Memory leak of t2's ptr (line 61)
// 2. The pointers of both objects share the same memory (lines 65, 66)
// 3. Double free when t2 is deleted from the stack, then t1 is deleted
//    from the stack when the objects go out of scope (line 71)
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
    Test t1;
    Test t2(2, 2);

    t1.printData();
    t2.printData();

    t2 = t1;  // Shallow Copy
    t1.printData();
    t2.printData();

    t2.setVal(3);
    t2.setPtrVal(3);

    t1.printData();
    t2.printData();

    return 0;
}
