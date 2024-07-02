/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 7
 * Description: File contains the implementation of the
 *              tribonacci function using recursion.
 * Input: None
 * Output: None
 */

#include "tribonacci.h"

/*
 * tribonacci
 * Description: Recursive function to calculate the nth Tribonacci number
 * Input: int t0 - first number of the Tribonacci sequence
 *        int t1 - second number of the Tribonacci sequence
 *        int t2 - third number of the Tribonacci sequence
 *        int n  - the desired entry of the sequence
 * Output: Returns the nth Tribonacci number
 */
int tribonacci(int t0, int t1, int t2, int n)
{
   // Base cases
   if (n == 0)
      return t0;
   if (n == 1)
      return t1;
   if (n == 2)
      return t2;
   // Recursive case
   return tribonacci(t0, t1, t2, n - 1) +
          tribonacci(t0, t1, t2, n - 2) + tribonacci(t0, t1, t2, n - 3);
}
