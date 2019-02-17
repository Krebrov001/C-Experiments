/*
 * Name        : random_recursion.cpp
 * Date        : 03/21/2017
 * Author      : Konstantin Rebrov
 * Description : This program shows that a recursive function does not call
 *               itself but rather another identical function.
 *               Each random number is unique to the function in which
 *               it was declared.
 *               The program execution keeps calling recursive functions until the "magic number" is reached.
 *               This program was fixed on 01/18/2017.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;
using std::rand;
using std::srand;

// This is not one function!
// It is a "blueprint" of the "function".
void rand_function() {
  int rand_int;
  rand_int = rand() % 6;
  cout << rand_int << endl;
  if (rand_int != 5) {
    rand_function();
  }
}

int main() {
  srand(time(0));
  rand_function();

  return 0;
}
