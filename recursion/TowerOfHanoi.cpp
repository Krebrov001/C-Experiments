#include <iostream>
using std::cout;
using std::endl;

int TowerOfHanoi(int num_disks) {
  if (num_disks == 1)
    return 1;
  else
    return 2 * TowerOfHanoi(num_disks - 1) + 1;
}

int main() {
  for (int i = 1; i <= 5; i++) {
    cout << i << ": " << TowerOfHanoi(i) << endl;
  }
  return 0;
}
