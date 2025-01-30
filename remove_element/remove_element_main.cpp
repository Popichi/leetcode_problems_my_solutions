#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Uncomment the following line to test the erase-based solution
// #define USE_ERASE_METHOD

class Solution {
public:

#ifdef USE_ERASE_METHOD
    // Erase-based approach
    int removeElement(std::vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
#else
    // Two-pointer approach
    int removeElement(std::vector<int>& nums, int val) {
        int j = 0;
        int i = 0;
        int k = 0;
        while (i < (int)nums.size()) {
            if (nums[i] != val && nums[j] != val) {
                // Both i and j are 'good' positions
                ++i;
                ++j;
                ++k;
            } else if (nums[i] == val && nums[j] == val) {
                // Move i forward to find a non-val element
                ++i;
            } else if (nums[i] != val && nums[j] == val) {
                // Swap a 'val' out of the front
                std::swap(nums[i], nums[j]);
                ++i;
                ++j;
                ++k;
            }
        }
        return k;
    }
#endif
};

// Helper function to print a vector (for debugging)
void printVector(const std::vector<int>& vec, int k = -1) {
    if (k < 0) k = (int)vec.size();
    std::cout << "[ ";
    for (int i = 0; i < k; ++i) {
        std::cout << vec[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}

int main() {
    Solution sol;

    {
        // Test Case 1 from LeetCode
        std::cout << "=== Test Case 1 ===" << std::endl;
        std::vector<int> nums = {3,2,2,3};
        int val = 3;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 2, result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    {
        // Test Case 2 from LeetCode
        std::cout << "=== Test Case 2 ===" << std::endl;
        std::vector<int> nums = {0,1,2,2,3,0,4,2};
        int val = 2;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 5, result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    // Additional Test Cases
    {
        // Test Case 3: Empty array
        std::cout << "=== Test Case 3: Empty Array ===" << std::endl;
        std::vector<int> nums = {};
        int val = 1;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 0, result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    {
        // Test Case 4: Array with no occurrences of val
        std::cout << "=== Test Case 4: No Occurrences ===" << std::endl;
        std::vector<int> nums = {1,2,3,4};
        int val = 5;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 4, result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    {
        // Test Case 5: Array where all are val
        std::cout << "=== Test Case 5: All Are val ===" << std::endl;
        std::vector<int> nums = {2,2,2,2};
        int val = 2;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 0, result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    {
        // Test Case 6: Mixed elements
        std::cout << "=== Test Case 6: Mixed ===" << std::endl;
        std::vector<int> nums = {4,1,2,4,3,4,0,4};
        int val = 4;
        std::cout << "Input nums: ";
        printVector(nums);
        std::cout << ", val = " << val << std::endl;

        int k = sol.removeElement(nums, val);

        std::cout << "Expected k = 4 (any valid arrangement of [1,2,3,0] in the first k) => "
                  << " result k = " << k << std::endl;
        std::cout << "Modified nums (first k elements kept): ";
        printVector(nums, k);
        std::cout << "\n\n";
    }

    return 0;
}
