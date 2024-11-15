/*1. Two Sum

Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/

#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n^2) solution:
        /*vector<int> indices {};
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target and i != j) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }

        return indices;*/

        // O(n) solution:
        vector<int> indices {};
        std::unordered_map<int, int> nums_map;

        /*The logic for finding the two indices that add up to the target is 
          integrated into the a single loop. As we iterate over the array, 
          we're doing two things simultaneously:
          
          1. Checking if the complement of the current number 
             (i.e., target - nums[i]) is already in the map. If it is, it 
             means we have already seen a number that, when added to the 
             current number, equals the target. In this case, we immediately 
             return the indices. This also handles when there are duplicate 
             numbers as we immediately return the found indices.
          2. If the complement is not found, we insert the current number and 
             its index into the map. This is for future iterations, in case we 
             encounter a number that would form the target sum with this 
             number.*/
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