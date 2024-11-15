// This file is used to debug while solving the LeetCode problems!

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n) solution:
        vector<int> indices {};
        unordered_map<int, int> nums_map;

        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (nums_map.find(complement) != nums_map.end()) {
                indices.push_back(nums_map[complement]);
                indices.push_back(i);
                return indices;
            }
            nums_map[nums[i]] = i;
        }

        return indices;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test Case 1: Indices: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test Case 2: Indices: [" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Test Case 3: Indices: [" << result3[0] << ", " << result3[1] << "]" << endl;

    // Additional test cases
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 9;
    vector<int> result4 = sol.twoSum(nums4, target4);
    cout << "Test Case 4: Indices: [" << result4[0] << ", " << result4[1] << "]" << endl;

    vector<int> nums5 = {0, 4, 3, 0};
    int target5 = 0;
    vector<int> result5 = sol.twoSum(nums5, target5);
    cout << "Test Case 5: Indices: [" << result5[0] << ", " << result5[1] << "]" << endl;

    return 0;
}
