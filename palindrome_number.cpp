/*9. Palindrome Number
Easy

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

    -231 <= x <= 231 - 1

 
Follow up: Could you solve it without converting the integer to a string?*/


class Solution {
public:

    /* The algorithm consist of the following key points:
       1) Negative Numbers and Zero Ending Check: The initial if-statement
          effectively filters out negative numbers and any positive number 
          ending with 0, except for 0 itself. This is crucial because negative 
          numbers can't be palindromes due to the minus sign, and numbers 
          ending in 0 can only be palindromes if the number is 0, as no other 
          number can start with 0.
        2) Single-Digit Check: Adding a check for single-digit numbers 
           (x >= 0 && x < 10) directly returns true for these cases as single 
           digits are palindrome by definition.
        3) Reverse Half of the Number: Initialize a variable to store the 
           reversed half. Iterate through the original number, reducing it 
           by dividing by 10 each time, and build up the reversed half by 
           multiplying the reversed half by 10 and adding the last digit of 
           the original number.
        4) Handling Even and Odd Digits:
           For numbers with an even number of digits, the reversed half should 
           be equal to the original half for the number to be a palindrome.
           For numbers with an odd number of digits, the reversed half will 
           contain middle digit of the original number as its last digit. So, you 
           should remove the last digit from the reversed number. This can be 
           done by dividing it by 10 during the comparison.*/

    bool isPalindrome(int x) {
        // Check for negative numbers and numbers ending in 0 (except for 0 
        // itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // Single-digit numbers are always palindromes
        if (x >= 0 && x < 10) return true;

        // Reversing half of the number to check palindrome
        int reversedHalf = 0;
        while (x > reversedHalf) {
            int lastDigit = x % 10;
            reversedHalf = reversedHalf * 10 + lastDigit;
            x /= 10;
        }

        // As explained above, for numbers with an odd number of digits, the 
        // reversed half will contain middle digit of the original number as 
        // its last digit. So, you should remove the last digit from the 
        // reversed number. This can be done by dividing it by 10 during the 
        // comparison.
        // For example, when a palindrome number with odd number of digits goes
        // into the while loop, we get:
        // 1) Initially, x = 12321, and reversedHalf = 0.
        // 2) After processing one digit (1), x = 1232, and reversedHalf = 1.
        // 3) After processing another digit (2), x = 123, and reversedHalf = 12.
        // 4) After processing another digit (3), x = 12, and reversedHalf = 123.
        // So, for the comparison we do reversedHalf / 10 which results in 12
        // as 12.3 will be truncated to 12 for an int.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};