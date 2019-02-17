/**
 * @file     recursive_FizzBuzz.cpp
 * @author   Konstantin Rebrov <krebrov@mail.csuchico.edu>
 * @version  08/10/2018
 *
 * @section DESCRIPTION
 *
 * FizzBuzz: Output numbers from 1 to x.
 * If the number is divisible by 3, replace it with "Fizz".
 * If the number is divisible by 5, replace it with "Buzz".
 * If the number is divisible by 3 and 5, replace it with "FizzBuzz".
 *
 * This program demonstrates printing out FizzBuzz for all integers [1...x] inclusive.
 * Unlike many solutions to the problem, my program does not use for-loops!
 * I used recursion instead of iteration.
 * I have two recursive functions here that get the job done:
 * - binaryFizzBuzz() uses a binary in-order traversal to print the numbers
 * - recursiveFizzBuzz() uses regular old recursion with a base case to accomplish this
 *   task.
 *
 * @sources
 * Byte By Byte Interview Question: FizzBuzz
 * https://www.youtube.com/watch?v=c0OMPDLef08
 */
#include <cstdlib>   // for EXIT_SUCCESS
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/**
 * This function prints the FizzBuzz status of the int parameter.
 *   if n is a multiple of 3, prints "Fizz"
 *   if n is a multiple of 5, prints "Buzz"
 *   if n is a multiple of both 3 and 5, prints "FizzBuzz"
 *   otherwise just prints the value of n.
 *
 * This function is called by binaryFizzBuzz() and recursiveFizzBuzz().
 */
void printFizzBuzz(int n)
{
    if (n % 3 == 0) {
        if (n % 5 == 0)
	    cout << "FizzBuzz" << endl;
	else
	    cout << "Fizz" << endl;
    } else if (n % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << n << endl;
    }
    return;
}


/**
 * This function traverses all the numbers [1...x] and prints their FizzBuzz status.
 * An algorithm similar to binary search or in-order traversal is used to print
 * all the numbers in increasing order in O(log(x)) time.
 * It also takes up O(log(x)) space on the runtime stack.
 *
 * @param int low - When calling this function from the main() function, this parameter
 *                  should be 1.
 *
 * @param int high - When calling this function from the main() function, this parameter
 *                   should be x.
 *
 * During the recursion, the value of this parameter is adjusted until you get to
 * the base case, when low == high. Then that number is passed into printFizzBuzz().
 */
void binaryFizzBuzz(int low, int high)
{
    if (low == high) {
        printFizzBuzz(high);
	return;
    } else {
        int mid = low/2 + high/2;
	binaryFizzBuzz(low, mid);
	binaryFizzBuzz(mid+1, high);
	return;
    }
}


/**
 * This function traverses all the numbers [1...x] and prints their FizzBuzz status.
 * The algorithm uses recursion instead of iteration to print all the numbers in increasing
 * order in O(x) time. It also takes up O(x) space on the runtime stack.
 *
 * @param int n - The number from which to start the recursion.
 *                When calling this function from the main() function, this parameter
 *                should be 1.
 *
 * @param int max - The maximum number to be reached in the recursion.
 *                  When calling this function from the main() function, this parameter
 *                  should be x.
 *
 * Starting from n, it goes into recursion and that number is passed into printFizzBuzz(),
 * until it hits the base case, when n == max. Then the recursion comes back down the stack.
 */
void recursiveFizzBuzz(int n, int max)
{
    printFizzBuzz(n);

    if (n == max)
      return;
    else
      recursiveFizzBuzz(n+1, max);

    return;
}


int main()
{
    int x;  // The number to run the FizzBuzz algorithm up to.

    cout << "Enter the maximum FizzBuzz value: ";
    cin  >> x;

    binaryFizzBuzz(1, x);
    cout << endl;

    cout << std::string(20, '-') << endl;

    recursiveFizzBuzz(1, x);
    cout << endl;

    return EXIT_SUCCESS;
}
