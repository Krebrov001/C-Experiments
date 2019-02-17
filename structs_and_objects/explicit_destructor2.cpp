/*
 * https://www.youtube.com/watch?v=EbqjycJza5I
 * Question: Is it possible to call constructor and destructor by yourself?
 */

#include <iostream>


class Base {
  int baseVariable_;  // This variable, a class data member, is private by default

 public:
  Base()
  {
    std::cout << "Base Constructor" << std::endl;
  }

  ~Base()
  {
    std::cout << "Base Destructor" << std::endl;
  }

  void sayHello()
  {
    std::cout << "Hello Hackers" << std::endl;
  }
};


void printLineSeparator()
{
  std::cout << std::string(50, '=') << std::endl;
}


/**
 * Base() invokes the default constructor of the class Base,
 * and creates a temporary/anonymous object/instance, or an rvalue
 * of the class Base.
 * That temporary/anonymous object is then destroyed as soon as it is
 * created, and the Base Destructor is called.
 */
void func1()
{
  Base();
}


/**
 * Base() invokes the default constructor of the class Base,
 * and creates a temporary/anonymous object/instance, or an rvalue
 * of the class Base.
 * Then that temporary object, or modifiable rvalue, is used as any regular
 * object, and the Base Destructor is explicitly called via the
 * . member selection operator
 * Then the Base Destructor is called again, this time by the compiler,
 * when the temporary object gets destroyed on that same line.
 */
void func2()
{
  Base().~Base();
}


/**
 * First the base constructor is invoked to create a temporary object
 * of the base class. Then the sayHello() function of that temporary
 * object is envoked. Finally, the Base Destructor is envoked when the
 * temporary object is destroyed.
 */
void func3()
{
  Base().sayHello();
}


/**
 * First an object of the Base class, obj is created.
 * Then the Base Destructor of the obj object is called.
 * Then the Base Destructor is called again when obj goes out of the
 * function's scope and is destroyed.
 */
void func4()
{
  Base obj;

  obj.~Base();

}


/**
 * This code demonstrates one very important concept in C++.
 * An anonymous/temporary object, or rvalue of a class type,
 * is created, then it is destroyed as soon as it is created.
 * If you want to call a function on this rvalue, you have to put it
 * on the object itself, grab onto it immediately after it is created,
 * before it gets destroyed by the compiler.
 *
 * The temporary object is created, and it is destroyed immediately on that
 * same line. Thus, first the constructor is called, then the destructor
 * is called, then the string literal "something" is printed to the screen.
 */
void func5()
{
  Base();

  std::cout << "something" << std::endl;
}


/**
 * In this function, a regular object/instance of the Base class is created.
 * This object has no reason to be destroyed right away, because it has
 * a name, obj, and it is not an anonymous/temporary object rvalue.
 * This object gets destroyed only when it goes out of scope, when the
 * function ends. Thus, first the constructor is called, then the string
 * literal "something" is printed to the screen, then the destructor is
 * called when the program execution reaches the }
 *
 * Unlike anonymous/temporary objects which are created and then
 * destroyed, regular objects persist until they go out of scope and
 * then they are destroyed.
 */
void func6()
{
  Base obj;

  std::cout << "something" << std::endl;
}


/**
 * In this code, the constructor of the std::string class is invoked to
 * create a std::string object, specifically a string with 5 'a' chars.
 * Then .size() is called on that anonymous string object, returning me
 * the int 5. Then the string is destroyed and the returned value is
 * printed to the screen.
 *
 * The constructor and destructor of the std::string class do not
 * print anything to the screen.
 */
void func7()
{
  std::cout << std::string(5, 'a').size() << std::endl;
}


int main() {
  func1();
  printLineSeparator();
  func2();
  printLineSeparator();
  func3();
  printLineSeparator();
  func4();
  printLineSeparator();
  func5();
  printLineSeparator();
  func6();
  printLineSeparator();
  func7();
  printLineSeparator();

  return 0;
}
