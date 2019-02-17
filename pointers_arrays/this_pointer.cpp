/* CppNuts : How this pointer Reaches To Member Function In C++?
   https://www.youtube.com/watch?v=_Wv-lEl1sgg&t=0s&list=PLk6CEY9XxSIDy8qVHZV-Nf-r9f2BkRZ6p&index=77
 */
// How C++ functions are translated by the compiler, including the this pointer,
// OR how we can write object-oriented code in C.
//
// Question: What is this pointer in C++?
// Answers : 1. Passed as hidden argument to non static member functions.
//           2. Is a const pointer which holds the address of current object [TYPE* const this]
//           3. If member function is const the, this pointers type becomes
//              [const TYPE* const this]
//
// 1. Static member functions have to concept of an object.
//    They are stand alone functions not belonging to any particular object,
//    they are only scoped to be in that class.
//
// 2. void setValue(Base* const this, int a) { this->_a = a }
//    this is a pointer to a Base object.
//    The pointer is const but the data is not const, meaning that you cannot make this to point to something else,
//    However the object to which it points to is not const in order to modify it's data members through the setter.
//
// 3. int getValue(const Base* const this) const { return this->_a }
//    The pointer is const and the data is const too.
//    In this case the function is being declared as const, so we cannot modify the object that this points to.
//    That's why the data is also const. We can read it but not write to it.
//
// 4. Because the this pointer is a const pointer, we cannot change it.
//    We cannot change this to point to NULL or some other base object.
//
// 5. If we call a non-const function, then the pointer would be const but the data would be non-const.
//    This means that (pun intended) we can modify any data members of this object, and we can even delete it!
//    Here we get a nasty bug!

#include <iostream>
using namespace std;

class Base {
  public:
    void setValue(int a) { _a = a; }
    // void setValue(Base* const this, int a) { this->_a = a }

    int getValue() const { return _a; }
    // int getValue(const Base* const this) const { return this->_a; }

    //void funk() { this = NULL; }
    // void funk(Base* const this) { this = NULL; }

    void hack() { delete this; }
    // void hack(Base* const this) { delete this; }
  private:
    int _a;
};


int main() {
    Base b;
    b.setValue(10);
    // setValue(&b, 10);

    int num = b.getValue();
    // int num = getValue(&b);

    // FIXME: It is a bug!!!
    //b.hack();

    return 0;
}
