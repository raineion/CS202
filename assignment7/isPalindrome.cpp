/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 7
 * Description: This file contains the implementation
 *              of the isPalindrome function using recursion.
 * Input: None
 * Output: None
 */

#include "isPalindrome.h" // for isPalindrome information
#include <string>         // for string

/*
 * isPalindrome
 * Description: Recursive function to check if a string is a palindrome
 * Input: string str - the string to check
 *        int start - the starting index to check
 *        int end - the ending index to check
 * Output: Returns true if the string is a palindrome, false otherwise
 */
bool isPalindrome(string str, int start, int end)
{
   // if the string is empty or has one character, it is a palindrome
   if (start >= end)
      return true;
   // if the first and last characters 
   // do not match, it is not a palindrome
   if (str[start] != str[end])
      return false;
   // Recursive case: check the remaining substring
   return isPalindrome(str, start + 1, end - 1);
}
