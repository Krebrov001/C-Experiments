#include <iostream>

#define NAME(x) #x

template <typename T>
void foo(T value)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << NAME(value) << std::endl
                           << std::endl;
}

/*
void callMe(int* p)
{
  std::cout << "Value of int pointer: " << p << std::endl;
}

void callMe(char* cp)
{
  std::cout << "Value of char pointer: " << cp << std::endl;
}

void callMe(std::nullptr_t np)
{
  std::cout << "Value is of type std::nullptr_t" << std::endl;
}

void callMe(int i)
{
  std::cout << "Value of int: " << i << std::endl;
}
*/

int main()
{
  foo(nullptr);
  foo(NULL);

  //callMe(nullptr);
  //callMe(NULL);

  // int* lvalue = pointer rvalue;
  int *p1 = 0;

  // int* lvalue = int rvalue
  //int *p2 = 5;

  // You cannot assign nullptr to a lvalue of bool type!
  //bool flag = nullptr;
  //std::cout << std::boolalpha << flag << std::endl;

  if (nullptr) {
    std::cout << "nullptr is apparently true" << std::endl;
  } else {
    std::cout << "nullptr is apparently false" << std::endl;
  }

  if (NULL) {
    std::cout << "NULL is apparently true" << std::endl;
  } else {
    std::cout << "NULL is apparently false" << std::endl;
  }

  return 0;
}
