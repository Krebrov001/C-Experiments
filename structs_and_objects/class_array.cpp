#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Numbers {
 public:
  Numbers(int size);
  ~Numbers();
  void InputNums();
  void OutputNums();

 private:
  int *array, size;;
};

int main() {
  int num1;
  cout << "Start the program." << endl;
  cout << "Enter a value to be passed into the constructor: ";
  cin >> num1;
  Numbers object(num1);
  object.InputNums();
  object.OutputNums();

  return 0;
}

Numbers::Numbers(int size) {
  this->size = size;
  array = new int[size];
}

Numbers::~Numbers() {
  delete[] array;
  array = NULL;
  cout << "Object was destroyed" << endl;
}

void Numbers::InputNums() {
  for (int i = 0; i < size; i++) {
    cout << "Enter a value for array[" << i << "]: ";
    cin >> array[i];
  }
}

void Numbers::OutputNums() {
  for (int i = 0; i < size; i++) {
    cout << "array[" << i << "] = " << array[i] << endl;
  }
}
