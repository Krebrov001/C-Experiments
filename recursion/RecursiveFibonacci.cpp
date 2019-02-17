/*
 * Name        : RecursiveFibonacci.cpp
 * Author      : Konstantin Rebrov
 * Date        : 04/08/2017
 * Language    : C++
 * Description : This program demonstrates using a recursive algorithm
 *               (function) to print out the Fibonacci sequence.
 */

#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int Fibonacci(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
  cout << "How many numbers of the Fibonacci sequence do you want?" << endl;
  int numbers;
  cin >> numbers;
  if (numbers == 0)
    exit(0);
  else if (numbers < 0)
    exit(1);
  for (int i = 0; i < (numbers - 1); i++) {
    cout << Fibonacci(i) << ", ";
  }
  cout << Fibonacci(numbers - 1) << endl;

  return 0;
}
