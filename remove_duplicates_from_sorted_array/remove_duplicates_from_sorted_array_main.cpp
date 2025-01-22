#include <iostream>
#include <vector>
#include <cassert>

// Uncomment this if you want to use your current approach
//#define USE_ERASE_METHOD 

class Solution {
public:
#ifdef USE_ERASE_METHOD
    // Your erase-based approach (but corrected)
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        auto it = nums.begin();
        while (it != nums.end() - 1) {
            if (*it == *(it + 1)) {
                it = nums.erase(it); // erase the duplicate
            } else {
                ++it; // move on if not duplicate
            }
        }
        return nums.size();
    }
#else
    // Classic two-pointer approach
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int i = 0;
        for (int j = 1; j < (int)nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
#endif
};

// Helper function to print vectors (for debugging)
void printVector(const std::vector<int>& nums, int k = -1) {
    // If k isn't specified or negative, print full vector
    if (k < 0) k = (int)nums.size();

    std::cout << "[ ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}

int main() {
    Solution sol;

    // Test Case 1
    {
        std::vector<int> nums = {1, 1, 2};
        int k = sol.removeDuplicates(nums);

        std::cout << "Test Case 1:" << std::endl;
        std::cout << "Return k = " << k << std::endl;
        std::cout << "Modified array = ";
        printVector(nums, k);
        std::cout << std::endl;
        // Expected k = 2, array = [1, 2, ...]
    }

    std::cout << std::endl;

    // Test Case 2
    {
        std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        int k = sol.removeDuplicates(nums);

        std::cout << "Test Case 2:" << std::endl;
        std::cout << "Return k = " << k << std::endl;
        std::cout << "Modified array = ";
        printVector(nums, k);
        std::cout << std::endl;
        // Expected k = 5, array = [0, 1, 2, 3, 4, ...]
    }

    std::cout << std::endl;

    // Additional Test Case
    {
        std::vector<int> nums = {1,2,2,2,3};
        int k = sol.removeDuplicates(nums);

        std::cout << "Additional Test Case:" << std::endl;
        std::cout << "Return k = " << k << std::endl;
        std::cout << "Modified array = ";
        printVector(nums, k);
        std::cout << std::endl;
        // Expected k = 3, array = [1,2,3, ...]
    }

    return 0;
}