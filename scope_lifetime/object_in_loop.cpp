/*
 * Name: object_in_loop.cpp
 * Author: Konstantin Rebrov
 * Language: C++
 * Description: This program has an object in a loop.
 *              It demonstrates that an automatic object is created and destroyed each iteration of the loop.
 *              Since the loop is run 5 times, the automatic object is created and destroyed 5 times.
 *              Each instance of the class is separate from the other ones.
 *              objects and variables are auto by defeult.
 *
 *              However, if we declare the object as static, the result is different. Static objects are
 *              deleted only when the program ends.
 *              So when the static object is created in the loop, it is constructed only once, during the
 *              first iteration of the loop with the value given in the first iteration.
 *              The object is destoyed when the main() function goes out of scope.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Object {
 public:
  Object(int data) : contents_(data) {
    cout << "The constructor was called with " << contents_ << endl;
  }
  ~Object() {
    cout << "The destructor was called and the former value was " << contents_ << endl;
  }
 private:
  int contents_;
};

int main() {
  for (int i = 0; i < 5; i++) {
    cout << "\niteration #" << i + 1 << ":\n";
    cout << "Enter an integer value: ";
    int num;
    cin >> num;
    //Object a(num);  // objects and instances are auto by default in C++
    auto Object a(num); 
    //static Object a(num); 
  } // an auto object is destroyed when it goes out of scope, means when each iteration of the loop reaches }

  cout << "That's it." << endl;

  // a static object is destroyed when its lifetime ends, means when the program ends.
  return 0;
}
