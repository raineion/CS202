/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 7
 * Description: This file contains the implementation of
 *              the arrayMax function using recursion.
 * Input: None
 * Output: None
 */

#include "arrayMax.h" // for arrayMax information

/*
 * arrayMax
 * Description: Recursive function to find the 
 *              maximum value in a portion of an array
 * Input: int arr[] - the array to search
 *        int start - the starting index to search
 *        int length - the number of elements to include in the search
 * Output: Returns the maximum value in the 
 *         specified portion of the array
 */
int arrayMax(int arr[], int start, int length)
{
   // Base case: if the length is 1, return the only element
   if (length == 1)
      return arr[start];

   // Recursive case: find the max in the rest of the array
   int max_of_rest = arrayMax(arr, start + 1, length - 1);

   // Return the maximum of the first element and the max of the rest
   return (arr[start] > max_of_rest) ? arr[start] : max_of_rest;
}
