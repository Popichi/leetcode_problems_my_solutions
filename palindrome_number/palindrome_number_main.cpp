// This file is used to debug while solving the LeetCode problems!

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Check for negative numbers and numbers ending in 0 (except for 0 itself)
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

        // For numbers with an odd number of digits, discard the middle digit
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution sol;

    int test1 = 121;
    int test2 = -121;
    int test3 = 10;
    int test4 = 12321;
    int test5 = 0;
    int test6 = 123454321;
    int test7 = 12345;
    int test8 = 1;
    int test9 = -101;

    cout << "Test Case 1: " << test1 << " -> " << (sol.isPalindrome(test1) ? "True" : "False") << endl;
    cout << "Test Case 2: " << test2 << " -> " << (sol.isPalindrome(test2) ? "True" : "False") << endl;
    cout << "Test Case 3: " << test3 << " -> " << (sol.isPalindrome(test3) ? "True" : "False") << endl;
    cout << "Test Case 4: " << test4 << " -> " << (sol.isPalindrome(test4) ? "True" : "False") << endl;
    cout << "Test Case 5: " << test5 << " -> " << (sol.isPalindrome(test5) ? "True" : "False") << endl;
    cout << "Test Case 6: " << test6 << " -> " << (sol.isPalindrome(test6) ? "True" : "False") << endl;
    cout << "Test Case 7: " << test7 << " -> " << (sol.isPalindrome(test7) ? "True" : "False") << endl;
    cout << "Test Case 8: " << test8 << " -> " << (sol.isPalindrome(test8) ? "True" : "False") << endl;
    cout << "Test Case 9: " << test9 << " -> " << (sol.isPalindrome(test9) ? "True" : "False") << endl;

    return 0;
}
