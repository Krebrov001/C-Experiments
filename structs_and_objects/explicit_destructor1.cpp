/*
   Once a destructor is invoked for an object, the object no longer exists; the behavior is undefined if the destructor is invoked for an object whose lifetime has ended. Example: if the destructor for an automatic object is explicitly invoked, and the block is subsequently left in a manner that would ordinarily invoke implicit destruction of the object, the behavior is undefined.
 */
#include <iostream>
using std::cout;
using std::endl;

class myClass {
  public:
   myClass()
   {
     i = 1;
     cout << "default ";
     cout << "constructor called with " << this->i << endl;
   }

   myClass(int i)
   {
     this->i = i;
     cout << "constructor called with " << this->i << endl;
   }

   ~myClass()
   {
     cout << "object " << i << " destroyed!" << endl;
   }

   void printData()
   {
     cout << "object's data is " << i << endl;
   }
  private:
   int i;  // private data member
};

int main() {
  myClass a;
  myClass b;
  myClass c(8);

  a.printData();
  b.printData();
  c.printData();

  /* I want to explicitly destroy object b. */
  b.~myClass();
  b.printData();
  /*
     Destroying an object has two parts:
     1. Calling the destructor.
     2. Deallocating the memory of the object itself.
     The destructor is needed to deallocate the memory which the object
     allocates, such as creating new dynamic sub-objects or opening files.
     The destructor in that case deallocates the dynamic sub-objects
     or closes the files.
     The destructor does not deallocate the memory for the object itself.
     That is typically done by the compiler if this is a stack object,
     or by delete (the dynamic memory manager) if this is a dynamic object.

     Calling the destructor explicitly does not deallocate the memory
     for the object itself. That is why you are able to access that memory.
     However, doing so is undefined behavior, and could lead to unforseeable
     Heisenbugs! Calling the printData() function is undefined behavior.
     The fact that the function worked as expected means that you just
     got lucky, because this is a relatively small and simple class with
     few internal components.
     Then the destructor is called again, this time by the compiler when
     the object goes out of scope and is deallocated/destroyed.
     Calling a destructor twice is technically undefined behavior.

     What if you have a class with many internal complexities?
     This hypothetical class may have dynamically allocated data members.
     When the destructor is explicitly called the first time,
     it deallocates those data members.
     Then calling printData() attempts to access the already freed
     dynamic data members on the heap. The program may crash or it may
     work silently without any visible errors.
     However that is undefined behavior!
     Then when the object itself gets destroyed when it goes out of scope,
     the destructor is called again, double deleting, or double freeing
     the already freed dynamic data members, which can lead to bugs
     or security vulnerabilities! This is also undefined behavior!
     For simple little test programs, invoking undefined behavior
     by calling the destructor function manually on an automatic stack
     object may seem harmless, but if you are engineering a complicated
     system of software with classes having a lot of internal complexities,
     you want to avoid any problems associated with undefined behaviors
     at all costs!
   */

  /* all the destructors get called when the objects go out of scope */

  return 0;
}
