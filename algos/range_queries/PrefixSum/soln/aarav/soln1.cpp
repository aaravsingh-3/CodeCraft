/*
Problem:
LeetCode 303 - Range Sum Query: Immutable

Given an integer array nums, handle multiple queries:
find the sum of elements between indices L and R inclusive.

Approach:
Build a prefix sum array where:
prefix[i] = sum of nums[0...i]

Then:
sum(L, R) = prefix[R] - prefix[L-1]   (if L > 0)

Time Complexity:
Preprocessing: O(N)
Each Query: O(1)

Space Complexity: O(N)

Example:
Input: nums = [-2,0,3,-5,2,-1], query(0,2)
Output: 1
*/

#include <iostream>
#include <vector>

// Class definition
class NumArray {
private:
    std::vector<int> prefix;

public:
    // Constructor: Preprocessing O(N)
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        // Resize prefix to N+1 and initialize with 0
        // We use N+1 so that prefix[0] is always 0, handling the "left=0" edge case gracefully.
        prefix.resize(n + 1, 0);

        // Build the prefix sum array
        // prefix[i+1] stores the sum of nums[0]...nums[i]
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    // Query: O(1)
    int sumRange(int left, int right) {
        // Formula: prefix[R+1] - prefix[L]
        // This calculates sum(0...R) - sum(0...L-1)
        return prefix[right + 1] - prefix[left];
    }
};

// Main driver code
int main() {
    // 1. Setup the input array
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    // 2. Instantiate the object
    // Note: In LeetCode, this happens behind the scenes.
    NumArray* obj = new NumArray(nums);

    // 3. Run queries
    // Query 1: sumRange(0, 2) -> -2 + 0 + 3 = 1
    int result1 = obj->sumRange(0, 2);
    std::cout << "Query(0, 2): " << result1 << std::endl;

    // Query 2: sumRange(2, 5) -> 3 + (-5) + 2 + (-1) = -1
    int result2 = obj->sumRange(2, 5);
    std::cout << "Query(2, 5): " << result2 << std::endl;

    // Query 3: sumRange(0, 5) -> Sum of all elements = -3
    int result3 = obj->sumRange(0, 5);
    std::cout << "Query(0, 5): " << result3 << std::endl;

    // 4. Cleanup
    delete obj;

    return 0;
}