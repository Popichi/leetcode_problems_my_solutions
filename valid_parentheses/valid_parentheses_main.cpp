#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
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

int main() {
    Solution sol;

    std::vector<std::string> testCases = {
        "()",                   // 1: True
        "()[]{}",               // 2: True
        "(]",                   // 3: False
        "([)]",                 // 4: False
        "{[]}",                 // 5: True
        "",                     // 6: True (empty string)
        "((()))",               // 7: True
        "((())",                // 8: False
        "[({})]",               // 9: True
        "[({}]",                // 10: False
        "{[()()]}",             // 11: True
        "{[(])}",               // 12: False
        "((()()))",             // 13: True
        "((()()))]",            // 14: False
        "([",                   // 15: False
        "])",                   // 16: False
        "(){}}{",               // 17: False
        "[]",                   // 18: True
        "[",                    // 19: False
        "]",                    // 20: False
        "([{}])",               // 21: True
        "([{}]))",              // 22: False
        "{{{{{}}}}}",           // 23: True
        "(((((((((())))))))))", // 24: True
        "(((((((()",            // 25: False
        ")(()))",               // 26: False
        "([)]",                 // 27: False
        "{[()]}()",             // 28: True
        "{[()]}(}",             // 29: False
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool result = sol.isValid(testCases[i]);
        std::cout << "Test Case " << i + 1 << ": \"" << testCases[i] << "\" -> "
             << (result ? "True" : "False") << std::endl;
    }

    return 0;
}
