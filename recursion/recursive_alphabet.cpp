#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
using std::cout;
using std::endl;
using std::string;


string getAlpha(string letter) {
  if (letter == "Z") {
    return "Z";
  } else {
    return letter + getAlpha(string(1, (letter.at(0) + 1)));
  }
}


int main() {
  cout << "The letters of the English alphabet in uppercase are: ";
  cout << getAlpha("A");
  cout << endl;

  return EXIT_SUCCESS;
}
