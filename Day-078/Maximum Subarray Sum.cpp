// Problem: Maximum Subarray Sum
// Problem Link: https://leetcode.com/problems/maximum-subarray/
// Time Complexity: O(N)
// Space Complexity: O(1)
// Approach: Kadane's Algorithm to find the maximum sum of a contiguous subarray by iterating through the array and keeping track of the current sum and maximum sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            // Either start new subarray from current element
            // or add to existing subarray
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update maximum sum if current sum is larger
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};