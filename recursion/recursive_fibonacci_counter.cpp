/**
 * @file     recursive_fibonacci_counter.cpp
 * @author   Konstantin Rebrov
 * @version  08/06/2018
 *
 * @section DESCRIPTION
 *
 * This program demonstrates how a recursive implementation of the Fibonacci algorithm
 * is inefficient compared to the iterative implementation.
 * This is because the time complexity for the recursive algorithm grows just like the
 * Fibonacci sequence itself because the recurrence relation is defined in terms of the
 * previous two numbers.
 * A certain previous element in the Fibonacci sequence may be calculated more than once.
 *
 * This program was inspired by:
 * mycodeschool Why recursion is not always good
 * https://www.youtube.com/watch?v=GM9sA5PtznY&index=2&list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO
 *
 * The thing is that the naive recursive algorithm without memoization keeps calculating
 * the lower-order terms in the Fibonacci sequence over and over again.
 * Fib(0), Fib(1), Fib(2) are called every single time when the are a dependency for a
 * recursive call before them in the stack.
 * Even though these terms have been already calculated, the recursive algorithm doesn't
 * know about them, and so it does unnecessary redundant work.
 *
 * My program maintains a vector of ints where each element contains the number of times
 * the corresponding recursive call has been calculated.
 * When all the recursive calls have completed, and the recursive algorithm returns the final
 * result, Fib(n), the vector has put on record the number of recursive calls made to calculate
 * a given previous element in the Fibonacci sequence.
 *
 * One interesting observation is that for any original input size n,
 * the number of times that F(1) has been called == fib[n]
 * This is because F(1) returns 1 and F(1) is the base case.
 * All of the recursive function calls return values that are made up of the base case value,
 * or "atoms" of the recursion. The whole is equal to the num of its parts.
 * As many calls to F(1) are made as they are necessary to build up the final value.
 * If we want to build up Fib(6) == 8, we need to get 8 atoms, and so call F(1) 8 times.
 */
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // for std::setw(w)

#include <cstdlib>  // for EXIT_SUCCESS

/**
 * This function calculates the Fibonacci number fib[n]
 * It also counts how many times each recursive function call is calculated.
 *
 * @param int n - The fib[n] number to calculate.
 *
 * @param std::vector<int>& times - This vector contains the number of times each recursive
 *        Fibonacci function call had been calculated for the total running time of the algorithm.
 *        times.at(0) contains the number of times Fib(0) had been calculated.
 *        times.at(1) contains the number of times Fib(1) had been calculated.
 *        times.at(2) contains the number of times Fib(2) had been calculated.
 *         ...
 *        The vector is pass by reference. It lives in the main() function.
 *        It's length is the n + 1 which is input from the user in the main() function.
 *
 * @return int - returns fib[n]
 */
int Fib(int n, std::vector<int>& times);


/**
 * This function finds the length (in number of digits) of the longest int value in the vector.
 * This is because I want all values in the vector to be printed with the same width in chars
 * so that they will be aligned nicely.
 *
 * This is the first version of the function.
 * It uses the std::string library to get the length of the int value as a string.
 * The benefit is that using a standard C++ library takes approximately constant time to find
 * the length of every number.
 * The disadvantage is that this is a C++ specific thing, and I am not entirely sure how
 * efficient it is to use std::string either.
 *
 * @param int std::vector<int>& times - The values in the vector can have any length, and I want to
 *                                      find the length of the longest int value.
 *
 * @return int - The length (in printable digits) of the longest int value in the vector.
 */
int findLongestLength1(std::vector<int>& times);


/**
 * This function finds the length (in number of digits) of the longest int value in the vector.
 * This is because I want all values in the vector to be printed with the same width in chars
 * so that they will be aligned nicely.
 *
 * This is the second version of the function.
 * It uses a repeated division algorithm to find the number of decimal digits in the int value.
 * The benefit is that you do not have to use the std::string library.
 * The disadvantage is that for each number, the algorithm is Ө(number of digits)
 * If the number is 1234567890, the while loop executes 10 times!
 *
 * @param int std::vector<int>& times - The values in the vector can have any length, and I want to
 *                                      find the length of the longest int value.
 *
 * @return int - The length (in printable digits) of the longest int value in the vector.
 */
int findLongestLength2(std::vector<int>& times);


int main() {
	
	// The index of the nth Fibonacci number, fib[n]
	int n;
	std::cout << "Give me an n: ";
	std::cin >> n;
	
	// The times vector contains the number of recursive calls made
	// for each Fibonacci number.
	//
	// It's size is n+1 because the Fibonacci numbers start at fib[0],
	// if fib is like an unending "array" of the Fibonacci numbers.
	// The first Fibonacci number is returned by Fib(0).
	//
	// All the elements in the vector are initialized to 0.
	// When Fib(x) is entered, it increments times.at(x)
	std::vector<int> times(n+1, 0);
	
	// The value of the nth Fibonacci number, fib[n]
	int final_value = Fib(n, times);
	
	/* Now vector times contains the number of times Fib() was called for each Fibonacci number. */
	
	
	// print the result of the Fibonacci calculation
	std::cout << "fib[" << n << "] == " << final_value << std::endl << std::endl;
	
	// The length (number of digits) of the longest number.
	// This is necessary in order to print all the digits in the same width in chars.
	int longestLength = findLongestLength2(times);
	
	// Print out all the data from the times vector.
	for (size_t i = 0; i < times.size(); ++i) {
		std::cout << "Fib(" << i << ") was calculated " << std::setw(longestLength) << times.at(i) << " times" << std::endl;
	}
	
	return EXIT_SUCCESS;
}


int Fib(int n, std::vector<int>& times) {
	// Increment the number of times Fib(n) has been calculated.
	++times.at(n);
	
	// do the actual Fibonacci numbers calculation
	if (n <= 1)
		return n;
	else
		return Fib(n-1, times) + Fib(n-2, times);
}


int findLongestLength1(std::vector<int>& times) {
	// The length (number of digits) of the longest number.
	int longestLength = 1;
	
	// The longest number (in digits) as a string.
	std::string longestNumber;
	
	// Uses std::string::length() to find the length of the current number
	// and compare it to the longestLength.
	for (std::vector<int>::const_iterator it = times.cbegin(); it != times.cend(); ++it) {
		longestNumber = std::to_string(*it);
		if (longestNumber.length() > longestLength)
			longestLength = longestNumber.length();
	}
	
	return longestLength;
}


int findLongestLength2(std::vector<int>& times) {
	// The length (number of digits) of the longest number.
	int longestLength = 1;
	
	// The value of the current number.
	int currentNumber;
	// The length (number of digits) of the current number.
	int currentLength;
	
	for (std::vector<int>::const_iterator it = times.cbegin(); it != times.cend(); ++it) {
		currentNumber = *it;
		currentLength = 0;
		
		// Keeps dividing the currentNumber by 10 until we reach 0.
		// Counts the number of times the currentNumber can be divided by 10,
		// the number of decimal (base-10) digits in the currentNumber;
		while (currentNumber > 0) {
			currentNumber /= 10;
			++currentLength;
		}
		
		if (currentLength > longestLength)
			longestLength = currentLength;
	}
	
	return longestLength;
}
