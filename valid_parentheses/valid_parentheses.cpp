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