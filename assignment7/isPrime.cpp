/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 7
 * Description: This file contains the implementation
 *              of the isPrime function using recursion.
 * Input: None
 * Output: None
 */

#include "isPrime.h" // for isPrime information

/*
 * isPrime
 * Description: Recursive function to check if a number x is prime
 * Input: int x - the number to check
 *        int y - the current divisor to check (initially set to x - 1)
 * Output: Returns true if x is prime, false otherwise
 */
bool isPrime(int x, int y)
{
   // Base case: if y is 1, then x is prime
   if (y == 1)
      return true;
   // If x is divisible by y, then it is not prime
   if (x % y == 0)
      return false;
   // Recursive case: check for the next divisor
   return isPrime(x, y - 1);
}
