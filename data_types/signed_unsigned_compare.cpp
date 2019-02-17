#include <iostream>
#include <cstdlib>  // C standard library - for EXIT_SUCCESS
using std::cout;
using std::cin;
using std::endl;

int main() {
  signed int signed_num;
  unsigned int unsigned_num;

  cout << "Enter a signed int value: ";
  cin  >> signed_num;
  cout << "Enter an unsigned int value: ";
  cin  >> unsigned_num;

  cout << endl;

  // if (signed_num < unsigned_num)
  /*
   *  This code uses short circuit evaluation of logical expressions.
   *  If signed_num is negative, then it is < 0, which is the minimum unsigned value.
   *  It is obvious that signed_num is less than the unsigned_num, so (true || anything) == true
   *  If the left side of the || is false, then signed_num is within the range of an unsigned value,
   *  which is 0 or positive, so we can compare it to the unsigned_num, and to do that we need to
   *  typecast the signed_num to an unsigned value to avoid compiler warnings.
   *  Typecasting a negative number to an unsigned value would make it a very large positive number,
   *  so the comparisson would be incorrect. The short circuit evaluation avoids this bug.
   */
  if ( (signed_num < 0) || (static_cast<unsigned int>(signed_num) < unsigned_num) ) {
    cout << signed_num << " < " << unsigned_num << endl;
  } else {
    cout << signed_num << " >= " << unsigned_num << endl;
  }

  // if (signed_num > unsigned num)
  /*
   * This code uses short circuit evaluation of logical expressions.
   * Remember that an unsigned_num is 0 or positive. If the signed_num is not 0 or positive, if it
   * is negative, then it clearly cannot be > unsigned_num, so the condition is false, and
   * (false && anything) == false. Only if signed_num is >= 0, there is a chance that it is > unsigned_num
   * so we can then compare the signed_num to the unsigned_num. We need to typecast the non-negative
   * signed_num to an unsigned value to avoid compiler warnings.
   * If signed_num would have been negative, then typecasting it would have given us a very large unsigned
   * value. We eliminate all the possible negative numbers through short circuit evaluation.
   */
  if ( (signed_num >= 0) && (static_cast<unsigned int>(signed_num) > unsigned_num) ) {
    cout << signed_num << " > " << unsigned_num << endl;
  } else {
    cout << signed_num << " <= " << unsigned_num << endl;
  }

  return EXIT_SUCCESS;
}
