#include <iostream>
#include <cctype>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int main() {
  int a = 5;
  cout << "a = " << a << endl;
  int &b = a;
  cout << endl << "b = " << b << endl;
  b += 2;
  cout << "b = " << b << endl;
  cout << "a = " << a << endl;
  if (b == a)
    cout << boolalpha << (b == a) << endl;
  
  int array[3];
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  int *pointer;
  pointer = array;
  cout << "Address of array: " << array << endl;
  cout << "Contents of pointer: " << pointer << endl;
  cout << "pointer[0] = " << pointer[0] << endl;
  cout << "pointer[1] = " << pointer[1] << endl;
  cout << "pointer[2] = " << pointer[2] << endl;

  int* numbers;
  int size;
  {
    int temp_size;
    cout << "What is the size of your array?" << endl;
    cin >> temp_size;
    numbers = new int[temp_size];
    size = temp_size;
  }
  cout << "The size of this array is ";
  cout << size << endl;
  for (int i = 0; i < size; i++) {
    cout << "Enter a value of numbers[" << i << "]: ";
    cin >> numbers[i];
  }
  for (int i = 0; i < size; i++) {
    cout << numbers[i] << endl;
  }

  // Error: the dynamic array was not deleted

  return 0;
}
