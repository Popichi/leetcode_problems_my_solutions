/*14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.*/

class Solution {
public:
    std::string longestCommonPrefix(vector<string>& strs) {

        // Vertical Scanning
        
        /* 
        // Best Case: O(n), where n is the number of strings in the vector
        // of strings. For example, this happens when there are no common 
        // prefixes.

        // Worst Case: O(n x m), where n is the number of strings in the 
        // vector of strings and m is the size of the shortest common string. 
        // For example, this happens when all the strings are the same.

        // Space complexity: O(m) for all cases, where m is the size of the 
        // shortest common string.

        if (strs.empty()) return ""; // Early return for empty input

        std::string common_prefix;

        // We start the outer loop with the index of the strings instead of 
        // the index of the list of string because we want to do vertical 
        // scan i.e. first compare the first character in every string, then 
        // the second  character, then the third, then the fourth and so on...
        for (size_t j = 0; j < strs[0].size(); ++j) {
            char c = strs[0][j];    // This is candidate common character

            // We go over the jth character of each string and if all the 
            // strings have this character, then we add it to the common 
            // prefix string.
            for (size_t i = 1; i < strs.size(); ++i) {

                // We return the common prefix as soon as a difference is 
                // found within any two strings as this means we've already 
                // figured out the common prefix
                if (j >= strs[i].size() || strs[i][j] != c) {
                    return common_prefix;
                }
            }
            common_prefix.push_back(c);
        }
        return common_prefix;*/
    
        // Lexicographically Sorting The Input List

        // For lexicographically sorting the list of strings:
        // The cost of sorting an array of strings lexicographically is 
        // O(NlogN), where NN is the number of strings. However, this doesn't 
        // account for the comparison cost of the strings themselves during 
        // the sort operation.
        // The comparison of two strings in the worst case can be up to 
        // O(M), where M is the length of the longest string in the array. 
        // Therefore, the sorting step can be more precisely estimated as 
        // O(NlogN⋅M).

        // For comparing the first and last string:
        // The best case for the comparison step would be O(1), occurring if 
        // the first character of the first and last strings in the sorted 
        // array differs, indicating there is no common prefix.
        // The worst case for the comparison of the first and last strings 
        // would be O(M), where M is the length of the longest in the list if 
        // all of the strings are the same.

        // Best Case Runtime: O(Nlog⁡N⋅M)+O(1)~=O(Nlog⁡N⋅M)
        // Worst Case Runtime: O(Nlog⁡N⋅M)+O(M)~=O(Nlog⁡N⋅M)

        // If you sort the strings lexicographically before finding the 
        // longest common prefix, you can optimize the problem slightly. Once 
        // sorted, you only need to compare the first and the last strings in 
        // the sorted array to find the longest common prefix. This is because 
        // if the first and last strings in the sorted list have a common 
        // prefix, then all strings in between necessarily share that prefix. 
        // This method reduces the problem to a single comparison between two 
        // strings, potentially simplifying the logic and reducing the number 
        // of comparisons needed

        // Sorting an array of strings lexicographically arranges the strings 
        // in dictionary order, not necessarily by their lengths. This means 
        // that the order is determined based on the alphabetical order of 
        // characters in the strings, comparing them character by character 
        // from left to right. The length of the strings plays a role only 
        // when comparing strings where one is a prefix of the other.

        // Here are a few points to clarify how lexicographical sorting works:
        // 1. Comparison by Characters: If you have strings "apple", "banana", 
        // and "grape", sorting them lexicographically results in "apple", 
        // "banana", "grape" because "a" comes before "b", which comes before 
        // "g" in the alphabet.
        // 2. Prefixes: If the strings are "app", "apple", and "bat", after 
        // sorting, you will get "app", "apple", "bat". Here, "app" comes 
        // before "apple" not because it is shorter but because it is a 
        // prefix and all preceding characters are equal.
        // 3. Mixed Lengths: For strings of different lengths where one is 
        // not a prefix of the other, the first differing character determines 
        // the order. For example, "cat", "car", and "camera" would be sorted 
        // as "camera", "car", "cat".
        // Shorter Lengths Not Always First: Lexicographical sorting does not 
        // mean shorter strings always come before longer ones. For example, 
        // "z" will come after "aardvark" because the first character "z" is 
        // lexicographically after "a".

        if (strs.empty()) return "";

        std::sort(strs.begin(), strs.end());

        std::string& first = strs.front();
        std::string& last = strs.back();
        size_t minLength = std::min(first.size(), last.size());

        // We find the index of the last character that the first string 
        // shares with the last strings (these two strings may be equal which 
        // means i would be equal to first.size() - 1)
        size_t i = 0;
        while (i < minLength && first[i] == last[i]) {
            ++i;
        }

        // We return the common characters betweent the first and last strings 
        // i.e. the common prefix.
        return first.substr(0, i);
    }
};