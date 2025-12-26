/*
Problem:
LeetCode 1480 - Running Sum of 1D Array

Given an array nums, return the running sum of nums.

Approach:
Use prefix sum technique:
result[i] = result[i - 1] + nums[i]

Time Complexity: O(N)
Space Complexity: O(N)

Example:
Input: [1,2,3,4]
Output: [1,3,6,10]
*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the result vector of size n
        std::vector<int> result(n);
        
        // Base case: The first element is just the first number
        if (n > 0) {
            result[0] = nums[0];
        }

        // Loop starting from index 1
        // Formula: result[i] = result[i - 1] + nums[i]
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + nums[i];
        }
        
        return result;
    }
};

int main() {
    // 1. Setup Input
    std::vector<int> nums = {1, 2, 3, 4};
    
    // 2. Create Solution Object
    Solution sol;
    
    // 3. Get Result
    std::vector<int> output = sol.runningSum(nums);
    
    // 4. Print Output
    std::cout << "Input: [1, 2, 3, 4]" << std::endl;
    std::cout << "Output: [";
    for (int i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        // Add comma if not the last element
        if (i < output.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}