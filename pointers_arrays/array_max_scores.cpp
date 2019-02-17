/*
 * Name             : array_max_scores.cpp
 * Title            : Maximum score value in an array demonstration
 * Language         : C++
 * Author           : Konstantin Rebrov
 * Created on       : 16 January 2017
 * Last modified on : 16 January 2017
 * Description      : Instead of having two for loops,
 *                    one to input the scores, and another to calculate the max value,
 *                    we can combine the score input loop and the max value loop
 *                    into one. First, ask the user to enter a score.
 *                              Then, determine if that newly entered value is the max value.
 *                    The max value is always set to the very first value in the array,
 *                    so the input statement for the first element is not part of the loop.
 * sources          : Absolute C++ Display 5.1 Program Using an Array
 */

// Reads in five scores and shows how much each
// score differs from the highest score.
#include <iostream>
using namespace std;

int main()
{
  // Declaring a single int, an array of 5 ints, and another int all in one line!
  int i, score[5], max;

  cout << "Enter 5 scores:\n";
  cin >> score[0];  // reads until the next whitespace character
  max = score[0];
  for (i = 1; i < 5; i++) {
    cin >> score[i];
    if (score[i] > max)
      max = score[i];
    // max is the largest of the values score[0],..., score[i].
  }

  // This is one cout statement on multiple lines.
  cout << "The highest score is " << max << endl
       << "The scores and their\n"
       << "differences from the highest are:\n";

  // This for loop has only one cout statement.
  for (i = 0; i < 5; i++)
    cout << score[i] << " off by "
         << (max - score[i]) << endl;
  
  return 0;
}
