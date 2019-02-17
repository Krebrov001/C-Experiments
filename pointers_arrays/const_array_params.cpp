/*
 * Name             : const_array_params.cpp
 * Title            : Inconsistent Use of const array Parameters
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 16 January 2017
 * Last modified on : 16 January 2017
 * Description      : When you pass an array into a function as a const array, then if that function calls
 *                    other functions from inside itself, the definitions of those functions must also
 *                    include the array as a const parameter.
 *                      This is done to prevent the called function from inadvertently modifying the
 *                      caller function's const array parameter!
 * Sources          : Absolute C++ Chapter 5 PITFALL: Inconsistent Use of const Parameters
 */

 #include <iostream>   // C++ input/output stream
 using namespace std;  // Who wants to type using std::something a lot of times?


///////////////////////////////////////////////////
//
// These are the function declarations/prototypes.
// The function definitions are below main()
//
///////////////////////////////////////////////////


// This function calls computeAverage(int*, int)
void showDifference(const int a[], int numberUsed);


// Returns the average of the elements in the first numberUsed
// elements of the array a. The array a is unchanged.
double computeAverage(const int a[], int numberUsed);
//double computeAverage(int a[], int numberUsed);


int main() {
  int goodNums[] = {10, 2, 34, 28, 19, 8, 17, 20, 21, 15};

  int arraySize = sizeof(goodNums) / sizeof(goodNums[0]);
  
  cout << "The array has " << arraySize << " elements." << endl;

  showDifference(goodNums, arraySize);
  cout << endl;

  return 0;  // less include clutter
}


///////////////////////////////////////////////////
//
// These are the function definitions.
// The functions are declared above main()
//
///////////////////////////////////////////////////


void showDifference(const int a[], int numberUsed)
{
  double average = computeAverage(a, numberUsed);
  cout << "Average of the " << numberUsed   // This is an example of a single cout statement stretched 
       << " numbers = " << average << endl  // among multiple lines.
       << "The numbers are:\n";
  for (int index = 0; index < numberUsed; index++)
    cout << a[index] << " differs from average by "
         << (a[index] - average) << endl;
}


double computeAverage(const int a[], int numberUsed)
//double computeAverage(int a[], int numberUsed)
{
  int sum = 0;
  for (int index = 0; index < numberUsed; index++)
    sum += a[index];

  return (static_cast<double>(sum) / static_cast<double>(numberUsed));
}
