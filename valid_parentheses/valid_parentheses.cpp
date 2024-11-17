/*20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and 
']', determine if the input string is valid.

An input string is valid if:

1) Open brackets must be closed by the same type of brackets.
2) Open brackets must be closed in the correct order.
3) Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

// Time complexity: O(n) where n is the length of the input string. We traverse the input 
// string only once. Therefore, we get O(n) time complexity in both worst and best case 
// scenarios.

// Space complexity: O(n) where n is the length of the input string. In the worst case, an input 
// might consist of only opening brackets, braces and / or parentheses. Therefore, we get O(n) space 
// complexity in the worst case. In the best case, the string might be have a closing bracket, 
// brace and / or parentheses which means the algorithm terminates without storing anything in the 
// stack.


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parentheses;

        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parentheses.push(c);
            } else {
                if (c == ')' && !parentheses.empty() && parentheses.top() == '(') {
                    parentheses.pop();
                } else if (c == '}' && !parentheses.empty() && parentheses.top() == '{') {
                    parentheses.pop();
                } else if (c == ']' && !parentheses.empty() && parentheses.top() == '[') {
                    parentheses.pop();
                } else {
                    return false;
                }
            }
        }

        if (parentheses.empty()) {
            return true;
        } else {
            return false;
        }
    }
};