// This file is used to debug while solving the LeetCode problems!

// This file is used to debug while solving the LeetCode problems!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        std::sort(strs.begin(), strs.end());

        std::string& first = strs.front();
        std::string& last = strs.back();
        size_t minLength = std::min(first.size(), last.size());

        // We find the index of the last character that the first string 
        // shares with the last string.
        size_t i = 0;
        while (i < minLength && first[i] == last[i]) {
            ++i;
        }

        // We return the common characters between the first and last strings 
        // i.e., the common prefix.
        return first.substr(0, i);
    }
};

int main() {
    Solution sol;
    
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"interstellar", "internet", "internal"};
    vector<string> strs4 = {"", "b", "c"};
    vector<string> strs5 = {};
    vector<string> strs6 = {"apple", "apple", "apple"};

    cout << "Test Case 1: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs1) << "\"." << endl;

    cout << "Test Case 2: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs2) << "\"." << endl;

    cout << "Test Case 3: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs3) << "\"." << endl;

    cout << "Test Case 4: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs4) << "\"." << endl;

    cout << "Test Case 5: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs5) << "\"." << endl;

    cout << "Test Case 6: ";
    cout << "The longest common prefix is \"" << sol.longestCommonPrefix(strs6) << "\"." << endl;

    return 0;
}
