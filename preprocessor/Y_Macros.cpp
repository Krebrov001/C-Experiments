#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// A handy macro to print the name of the variable and its value.
#define PRINT_VAR(x) cout << #x << " = " << x << endl;

// This is my master list macro for the days of the week.
// This is actually where the information for my data is stored.
// This master list calles the X() macro for each item in the list,
// which performs a given operation for one item in the list.
// Any changes made to the list in this single location
// will affect the code generated by the X() macro.
// This makes it easy to update the list and recompile the code.
#define DAYS_OF_WEEK \
  X(monday) \
  X(tuesday) \
  X(wednesday) \
  X(thursday) \
  X(friday) \
  X(saturday) \
  X(sunday)

int main() {
  /*
     The following transformations happen to the code below:

  #define X(dayOfWeek) int dayOfWeek = 0; 
  DAYS_OF_WEEK
  #undef X

  #define X(dayOfWeek) int dayOfWeek = 0; 
  X(monday) \
  X(tuesday) \
  X(wednesday) \
  X(thursday) \
  X(friday) \
  X(saturday) \
  X(sunday)
  #undef X

  #define X(dayOfWeek) int dayOfWeek = 0; 
  X(monday) X(tuesday) X(wednesday) X(thursday) X(friday) X(saturday) X(sunday)
  #undef X

  int monday = 0; int tuesday = 0; int wednesday = 0; int thursday = 0; int friday = 0; int saturday = 0; int sunday = 0;
   */

  // Create a variable for each day of the week and initialize it to 0.
  #define X(dayOfWeek) int dayOfWeek = 0; 
  DAYS_OF_WEEK
  #undef X

  /*
     After defining the X() macro, and using it to transform the DAYS_OF_WEEK "master list" macro,
     we undef that X macro.
     We want to be able to reuse the X() macro again later in the code with a different definition.
     Each definition of the X() macro serves only a specific purpose in a single place in the code.
     If we want to use the same definition of the X() macro in multiple places in the code,
     such as printing out a list, we simply copy/paste it.
     At least that is far less of a hassle than having to manually copy/paste the whole master list and possibly
     make erroneous changes to it.
   */

  // Creates an enumerated type filled up with enum rvalues representing
  // the different days of the week.
  #define X(dayOfWeek) e_##dayOfWeek, 
  enum DaysOfWeek {
    DAYS_OF_WEEK
  };
  #undef X

  // Prints the days of the week to stdout, with endl after each day.
  cout << "The days of the week are:" << endl;
  #define X(dayOfWeek) cout << #dayOfWeek << endl; 
  DAYS_OF_WEEK
  #undef X

  cout << endl;

  // Prints out the names of the enum rvalues of the days of the week,
  // and their values what they are equal to.
  cout << "The rvalues of the enumerated type DaysOfWeek are:" << endl;
  #define X(dayOfWeek) PRINT_VAR(e_##dayOfWeek)
  DAYS_OF_WEEK
  #undef X

  /*
     Observations?
     First the DAYS_OF_WEEK macro is expanded,
     Then each X(dayOfWeek) is replaced with  PRINT_VAR(e_dayOfWeek)
     Then each PRINT_VAR(e_dayOfWeek) is replaced with  cout << "e_dayOfWeek" << " = " << e_dayOfWeek << endl;
     Is this triple maro substitution?
   */

  // Creates a vector of strings and adds each day of the week to the vector.
  vector<string> weekDays;
  #define X(dayOfWeek) weekDays.push_back(#dayOfWeek);
  DAYS_OF_WEEK
  #undef X

  cout << endl;

  // Print the contents of the vector.
  for (auto x : weekDays) {
    cout << x << " ";
  }
  cout << endl;

  /*
     C++11 ranged for-loop:
     for (auto var : vectorName or arrayName) {
       cout << var << " ";
     }
     consists of two parts inside the for ( )
     (
     1. variable which will be assigned to each element in the array/vector
     :
     2. name of the vector or array to be iterated over
     )
   */

  // Print the contents of the vector.
  for (int i = 0; i < weekDays.size(); i++) {
    PRINT_VAR(weekDays.at(i))
  }

  /*
    PRINT_VAR(weekDays.at(i)) gets converted to  cout << "weekDays.at(i)" << " = " << weekDays.at(i) << endl;
    Expansion of this macro occurs during the preprocessing stage.
    So "weekDays.at(i)" is being stringized.
    Of course the preprocessor can't tell what i is, because i is only an element during runtime of the code.
    But the value weekDays.at(i) is evaluated at runtime and it is printed successfully.
   */

  cout << endl;

  // Find the total number of characters in all the strings.
  size_t total_num_chars = 0;
  #define X(dayOfWeek) (string(#dayOfWeek)).length() +
  total_num_chars += DAYS_OF_WEEK 0;
  #undef X

  cout << "Total chars: " << total_num_chars << endl;

  /*
     How does the above code work?
     First, "dayOfWeek" is stringized.
     Then that string is passed into the std::string() class constructor,
     and an rvalue of the string class is returned.
     Then .length() is called on that string class rvalue, to return the length of the string.
     Now we have an int rvalue.
     Then the + adds in the next int rvalue for the length of the next string.
     The 0 after DAYS_OF_WEEK is needed so that the last + operator has a right side operand.
     So we have:
     total_num_chars += 5 + 6 + 4 + ... + 5 + 0;

     It is worth noting that std::string() class constructor returns an rvalue of the string class.
     However just as .length() was called on that string class rvalue, another function could have
     been called, modifying the state of that string class rvalue.
     rvalues of a user-defined type (or class) may be modifiable.
     The same is not true for rvalues of the default built-in primitive data types (int, float, bool).
   */

  return 0;
}
