// This file is used to debug while solving the LeetCode problems!

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int integer_number = 0;
        unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, 
                                           {'L', 50}, {'C', 100}, {'D', 500}, 
                                           {'M', 1000}};

        for (int i = 0; i < s.size(); ++i) {
            // If the current value is less than the next value, it means this 
            // is a subtraction case. For example, when we are at 'I' for the 
            // number "IX".
            if (i + 1 < s.size() && values[s[i]] < values[s[i + 1]]) {
                integer_number += values[s[i + 1]] - values[s[i]];
                ++i; // Skip the next character since we have already 
                     // processed it.
                     
            // Else, simply add the current number to the total sum!
            } else {
                integer_number += values[s[i]];
            }
        }

        return integer_number;
    }
};

int main() {
    Solution sol;
    std::string roman1 = "LVIII";
    std::string roman2 = "MCMXCIV";

    cout << "The integer form of " << roman1 << " is " << sol.romanToInt(roman1) << "." << endl;
    cout << "The integer form of " << roman2 << " is " << sol.romanToInt(roman2) << "." << endl;

    return 0;
}