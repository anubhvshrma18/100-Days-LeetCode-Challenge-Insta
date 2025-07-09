// LeetCode Problem: https://leetcode.com/problems/missing-number/
// Problem: Given an array containing n distinct numbers taken from 0, 1, // 2, ..., n, find the one that is missing from the array.
// Approach: Use the formula for the sum of the first n natural numbers to find the missing number.
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <vector
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return total - sum;
    }
};