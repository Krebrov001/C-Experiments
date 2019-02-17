#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using std::string;
using std::ostream;
using std::setfill;
using std::setw;
using std::cout;
using std::endl;

/*
 * Class Money.
 * A class that handles amounts of money in U.S. Currency.
 */
class Money {
 public:
  /*
   * Constructor #1.
   * Sets dollars and cents to the supplied values. Defaults to 0
   * @param int dollars - The value to set dollars_ to
   * @param int cents - The value to set cents_ to
   */
  Money(int dollars = 0, int cents = 0)
      : dollars_(dollars),
        cents_(cents) {
  }

  /*
   * Accessor for dollars_
   * @return int - The dollars_ value
   */
  int dollars() const {
    return dollars_;
  }

  /*
   * Accessor for cents_
   * @return int - The cents_ value
   */
  int cents() const {
    return cents_;
  }

  /*
   * Mutator for dollars_
   * @param int dollars - The value to set dollars_ to
   */
  void set_dollars(int dollars) {
    dollars_ = dollars;
  }

  /*
   * Mutator for cents_
   * @param int cents - The value to set cents_ to
   */
  void set_cents(int cents) {
    cents_ = cents;
  }

  /*
   * Overload of + operator. This is a friend function.
   * @param Money amount1 - The first object to add
   * @param Money amount2 - The second object to add
   * @return Money - The two objects added together
   */
  friend const Money operator +(const Money& amount1, const Money& amount2);

  /*
   * Overload of binary - operator. This is a friend function.
   * @param Money amount1 - The object to subtract from
   * @param Money amount2 - The object to be subtracted
   * @return Money - The result of the subtraction
   */
  friend const Money operator -(const Money& amount1, const Money& amount2);

  /*
   * Overload of == operator. This is a friend function.
   * @param Money amount1 - The first object to compare
   * @param Money amount2 - The second object to compare
   * @return bool - True if the objects have the same values, otherwise false
   */
  friend bool operator ==(const Money &amount1, const Money &amount2);

  /*
   * Overload of unary - operator. This is a friend function.
   * @param Money amount - The object to negate
   * @return Money - The result of the negation of the two member variables
   */
  friend const Money operator -(const Money &amount);

  /*
   * Overload of << operator.
   * Outputs the money values to the output stream.
   * Should be in the form $x.xx
   * @uses setw()
   * @uses setfill()
   * @param ostream &out - The ostream object to output to
   * @param Money amount - The Money object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
  friend ostream& operator <<(ostream &out, const Money &amount);

 private:
  int dollars_;
  int cents_;
};

int main() {
  Money paycheck1(50, 50), paycheck2(-100, 0), paycheck3(100, 70);
  Money paycheck4;
  paycheck4 = paycheck1 + paycheck2;
  cout << paycheck1 << '+' << paycheck2 << '=' << paycheck4 << "\n\n";
  
  cout << paycheck3  << '-' << paycheck4;
  paycheck3 = paycheck3 - paycheck4;
  cout << '=' << paycheck3 << endl;

  paycheck3 = -paycheck3;
  cout << "New value (negated): ";
  cout << paycheck3 << endl;
  
  Money paycheck5(50, 50);
  if (paycheck1 == paycheck5)
     cout << "They are the same." << endl;
  else
    cout << "They are not the same." << endl;
}

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

/*
const Money operator -(const Money& amount1, const Money& amount2) {
  cout << "In the '-' operator" << endl;
  cout << amount1.dollars_ << '.' << amount1.cents_ << " - ";
  cout << amount2.dollars_ << '.' << amount2.cents_ << endl;
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  cout << "Convert to all cents." << endl;
  cout << "  " << all_cents1 << '-';
  cout << "  " << all_cents2 << endl;
  // Subtract the second amount of cents from the first
  all_cents1 -= all_cents2;
  // Handle the fact that money can be negative
  int abs_cents1_new = abs(all_cents1);
  int final_dollars = abs_cents1_new / 100;
  int final_cents = abs_cents1_new % 100;
  // If the result of the operation is negative, negate final dollars and cents
  if (all_cents1 < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}
*/

const Money operator -(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Subtract the second amount of cents from the first
  all_cents1 -= all_cents2;
  // Handle the fact that money can be negative
  int abs_cents1_new = abs(all_cents1);
  int final_dollars = abs_cents1_new / 100;
  int final_cents = abs_cents1_new % 100;
  // If the result of the operation is negative, negate final dollars and cents
  if (all_cents1 < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  return (amount1.cents_ == amount2.cents_ && 
          amount1.dollars_ == amount2.dollars_);
}

const Money operator -(const Money &amount) {
  int cents_total = amount.cents_ + amount.dollars_ * 100;
  cents_total *= -1;
  int abs_cents = abs(cents_total);
  int final_dollars = abs_cents / 100;
  int final_cents = abs_cents % 100;
  if (cents_total < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

ostream& operator <<(ostream &out, const Money &amount) {
  double all_cents = amount.cents_ + amount.dollars_ * 100;
  all_cents /= 100;
  double abs_cents = fabs(all_cents);
  out.setf(std::ios::fixed | std::ios::showpoint);
  out.precision(2);
  if (all_cents < 0)
    out << '-';
  out << '$' << abs_cents;
  return out;
}

